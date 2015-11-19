#include "Client.hpp"

Client::Client(){
	if(!al_init())
		exit(-1);
	al_init_primitives_addon();
	al_init_image_addon();
	al_install_keyboard();
	al_install_mouse();
	
	//al_set_new_display_flags(ALLEGRO_FULLSCREEN);
	
	
	display=al_create_display(RES_X,RES_Y);
	event_queue=al_create_event_queue();
	timer=al_create_timer(1/FPS);
	
	al_register_event_source(event_queue,al_get_display_event_source(display));
	al_register_event_source(event_queue,al_get_keyboard_event_source());
	al_register_event_source(event_queue,al_get_mouse_event_source());
	al_register_event_source(event_queue,al_get_timer_event_source(timer));
	
	//al_hide_mouse_cursor(display);
	
	maxClients=0;
	
	for(int i=0;i<ALLEGRO_KEY_MAX;i++)
		storeKeys[i]=false;
	mapX=mapY=0;
}

Client::~Client(){
	delete [] players;
	delete [] moved;
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
	al_destroy_timer(timer);
}

void Client::main_loop(){
	bool done=false;
	bool redraw=false;
	
	al_clear_to_color(al_map_rgb(255,255,255));
	al_start_timer(timer);
	while(!done){
		al_wait_for_event(event_queue, &ev);
		while(conn.event_service(0)>0){
			if(conn.event_type_receive()){
				buffer=(char*)conn.getPacketData();
				if(buffer[0]==PROTOCOL_NEW_USER){
					int16_t id,x,y,team;
					std::stringstream stream;
					stream << ((_data*)buffer)->buffer;
					stream >> id >> x >> y >> team;
					players[id]=new CCharacter();
					players[id]->setX(x);
					players[id]->setY(y);
					players[id]->setTeam((Team)team);
				} else if(buffer[0]==PROTOCOL_CHARACTER){
					int16_t id,x,y,dir;
					float angle;
					std::stringstream stream;
					stream << ((_data*)buffer)->buffer;
					stream >> id >> x >> y >> dir >> angle;
					players[id]->setX(x);
					players[id]->setY(y);
					players[id]->setDir((Direction)dir);
					players[id]->setWeaponAngle(angle);
					moved[id]=true;
				}
			}
			else if(conn.event_type_disconnect())
				exit(-1);
		}
		
		if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			done=true;
		else if(ev.type == ALLEGRO_EVENT_KEY_DOWN){
			storeKeys[ev.keyboard.keycode]=true;
			if(ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE){
				exit(0);
			}
		}
		else if(ev.type == ALLEGRO_EVENT_KEY_UP)
			storeKeys[ev.keyboard.keycode]=false;
		else if(ev.type == ALLEGRO_EVENT_TIMER){
			if(storeKeys[ALLEGRO_KEY_UP])
				players[myId]->setDir(UP);
			else if(storeKeys[ALLEGRO_KEY_DOWN])
				players[myId]->setDir(DOWN);
			else if(storeKeys[ALLEGRO_KEY_LEFT])
				players[myId]->setDir(LEFT);
			else if(storeKeys[ALLEGRO_KEY_RIGHT])
				players[myId]->setDir(RIGHT);
			else
				players[myId]->setDir(STOPED);
			
			mapX=players[myId]->getX()-RES_X/2;
			mapY=players[myId]->getY()-RES_Y/2;
			for(int i=0;i<maxClients;i++)
				if(players[i]!=NULL && !moved[i])
					players[i]->move();
				else if (moved[i])				// So it doesn't move to times
					moved[i]=false;
			
			players[myId]->colision(map.getObjects(),map.getNobject());
			
			al_get_mouse_state(&mouseState);
			players[myId]->weaponAngle(mapX,mapY,mouseState.x,mouseState.y);
			
			senderBuffer.type=PROTOCOL_CHARACTER;
			players[myId]->serialize(senderBuffer.buffer);
			conn.send_packet_unreliable(&senderBuffer,strlen(senderBuffer.buffer)+2,0);

			redraw=true;
		}
		
		if(redraw && al_is_event_queue_empty(event_queue)){
			map.draw_map(mapX,mapY);
			for(int i=0;i<maxClients;i++)
				if(players[i]!=NULL/* && i==myId*/)
					players[i]->draw(mapX,mapY);
			/*	else if (players[i]!=NULL)
					players[i]->draw(0,0);*/
			al_flip_display();
		}
		
	}
}

bool Client::connect(){
	char *buffer;
	int v=0;
	if(!conn.create_client("127.0.0.1",PORT))
		return false;
	while(conn.event_service(10000)!=0){
		if(conn.event_type_receive()){
			buffer=(char*)conn.getPacketData();
			if(buffer[0]==PROTOCOL_N_PEERS){
				recieverBuffer=(_data*)conn.getPacketData();
				maxClients=recieverBuffer->buffer[0];
				myId=recieverBuffer->buffer[1];
				players=new CCharacter*[maxClients];
				moved=new bool[maxClients];
				for(int i=0;i<maxClients;i++){
					players[i]=NULL;
					moved[i]=false;
				}
				players[myId]=new CCharacter;
				std::cout << "I was created\n";
				//connected. Now I want the map;
			}else if(buffer[0]==PROTOCOL_MAP_FILE){
				map.deserialize(buffer);
				std::cout << "Now I have the map\n";
				//Now i need to know my position
			}else if(buffer[0]==PROTOCOL_SET_POS_TEAM){
				std::stringstream stream;
				recieverBuffer=(_data*)conn.getPacketData();
				int16_t x,y;
				int16_t team;
				stream << recieverBuffer->buffer;
				stream >> x >> y >> team;
				players[myId]->setX(x);
				players[myId]->setY(y);
				players[myId]->setTeam((Team)team);
				std::cout << "Now I know where I should be\n";
				return true;
			}
		}
	}
	return false;
}
