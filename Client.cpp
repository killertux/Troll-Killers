#include "Client.hpp"

Client::Client(){
	char buffer[255];
	if(!al_init())
		exit(-1);
	al_init_primitives_addon();
	al_init_image_addon();
	al_install_keyboard();
	al_install_mouse();
	al_install_audio();
	al_init_acodec_addon();
	al_reserve_samples(16);
	
	soundtrack=al_load_sample("Sounds/main.ogg");

	config.config_load("client.cfg");
	config.config_get(buffer,"Port");
	port=strtol(buffer,NULL,0);
	config.config_get(buffer,"Res_X");
	res_x=strtol(buffer,NULL,0);
	config.config_get(buffer,"Res_Y");
	res_y=strtol(buffer,NULL,0);
	config.config_get(buffer,"Ip");
	ip=buffer;
	int fullscreen;
	config.config_get(buffer,"Fullscreen");
	fullscreen=strtol(buffer,NULL,0);

	if(fullscreen)
		al_set_new_display_flags(ALLEGRO_FULLSCREEN);


	display=al_create_display(res_x,res_y);
	event_queue=al_create_event_queue();
	timer=al_create_timer(1/FPS);

	al_register_event_source(event_queue,al_get_display_event_source(display));
	al_register_event_source(event_queue,al_get_keyboard_event_source());
	al_register_event_source(event_queue,al_get_mouse_event_source());
	al_register_event_source(event_queue,al_get_timer_event_source(timer));
	
	al_play_sample(soundtrack,0.7,0.0,1.0,ALLEGRO_PLAYMODE_LOOP,NULL);
	//al_hide_mouse_cursor(display);

	maxClients=0;

	for(int i=0;i<ALLEGRO_KEY_MAX;i++)
		storeKeys[i]=false;
	mapX=mapY=0;
	menus=new MenuManager(res_x,res_y);
}

Client::~Client(){
	delete [] players;
	delete [] moved;
	delete menus;
	al_destroy_sample(soundtrack);
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
				if(((_data*)buffer)->type==PROTOCOL_NEW_USER){
					int16_t id,x,y,team,myWeapon;;
					std::stringstream stream;
					stream << ((_data*)buffer)->buffer;
					stream >> id >> x >> y >> team >> myWeapon;
					players[id]=new CCharacter((Weapon)myWeapon);
					players[id]->setX(x);
					players[id]->setY(y);
					players[id]->setTeam((Team)team);
				} else if(((_data*)buffer)->type==PROTOCOL_CHARACTER){
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
				} else if(((_data*)buffer)->type==PROTOCOL_DISCONNECT){
					int16_t id;
					std::stringstream stream;
					stream << ((_data*)buffer)->buffer;
					stream >>id;
					delete players[id];
					players[id]=NULL;
				} else if(((_data*)buffer)->type==PROTOCOL_NEW_SHOOT){
					int16_t id,bulletId,x,y,length,velocity;
					float angle;
					std::stringstream stream;
					stream << ((_data*)buffer)->buffer;
					stream >> id >> bulletId >>x >> y >>length >>velocity >> angle;
					Projectile **projectiles=players[id]->getProjectiles();
					projectiles[bulletId]=new CProjectile(x,y,length,velocity,angle);
					players[id]->sound_shoot(players[myId]->getX(),players[myId]->getY());
				} else if(((_data*)buffer)->type==PROTOCOL_DELETE_BULLET){
					int16_t id,bulletId;
					std::stringstream stream;
					stream << ((_data*)buffer)->buffer;
					stream >> id >> bulletId;
					Projectile **projectiles=players[id]->getProjectiles();
					delete projectiles[bulletId];
					projectiles[bulletId]=NULL;
				} else if(((_data*)buffer)->type==PROTOCOL_REVIVE){
					int16_t id, x,y;
					std::stringstream stream;
					stream << ((_data*)buffer)->buffer;
					stream >> id >> x >> y;
					players[id]->revive(x,y);
				} else if(((_data*)buffer)->type==PROTOCOL_HIT){
					int16_t id,bulletId,playerId,dmg;
					std::stringstream stream;
					stream << ((_data*)buffer)->buffer;
					stream >> id >> bulletId >> playerId >> dmg;
					Projectile **projectiles=players[id]->getProjectiles();
					delete projectiles[bulletId];
					projectiles[bulletId]=NULL;
					players[playerId]->damage(dmg);
					if(players[playerId]->getLife()<=0){
						players[id]->sound_victory(players[myId]->getX(),players[myId]->getY());
						players[playerId]->die();
					}
					players[playerId]->sound_hit(players[myId]->getX(),players[myId]->getY());
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

			mapX=players[myId]->getX()-res_x/2;
			mapY=players[myId]->getY()-res_y/2;
			for(int i=0;i<maxClients;i++)
				if(players[i]!=NULL && !moved[i])
					players[i]->move();
				else if (moved[i])				// So it doesn't move to times
					moved[i]=false;

			players[myId]->colision(map.getObjects(),map.getNobject());

			al_get_mouse_state(&mouseState);
			players[myId]->weaponAngle(mapX,mapY,mouseState.x,mouseState.y);

			//Colision of the bullets
			for(int c=0;c<maxClients;c++)
				if(players[c]!=NULL){
				Projectile **projectiles=players[c]->getProjectiles();
				for(int i=0;i<SCREEN_PROJECTILES;i++)
					if(projectiles[i]!=NULL){
						//First we will colide with the map
						_object *mapObjects=map.getObjects();
						int nObjects=map.getNobject();
						for(int j=0;j<nObjects;j++)
							if(mapObjects[j].type==RECTANGLE){
								if(Projectile::collide(projectiles[i],mapObjects[j])){
									if(c==myId){	//I will only anounce the colision of my bullets;
										senderBuffer.type=PROTOCOL_DELETE_BULLET;
										std::sprintf(senderBuffer.buffer,"%d ",i);
										conn.send_packet_reliable(&senderBuffer,strlen(senderBuffer.buffer)+2,0);
									}
									delete projectiles[i];
									projectiles[i]=NULL;
									break;
								}
							}
						if(projectiles[i]!=NULL){		//Check if the bullet haven't colide yet;
							//Now we will colide with the other players;
							_object *playerObject;
							for(int j=0;j<maxClients;j++){
								if(players[j]!=NULL && !players[j]->getDead() && j!=c){
									playerObject=players[j]->getPlayer();
									if(Projectile::collide(projectiles[i],*playerObject) && players[c]->getTeam()!= players[j]->getTeam()){
										if(c==myId){	//I will only anounce the colision of my bullets;
											senderBuffer.type=PROTOCOL_HIT;
											std::sprintf(senderBuffer.buffer,"%d %d %d ",i,j,players[c]->getWeaponDmg());
											conn.send_packet_reliable(&senderBuffer,strlen(senderBuffer.buffer)+2,0);
											players[j]->damage(players[c]->getWeaponDmg());
											players[j]->sound_hit(players[myId]->getX(),players[myId]->getY());
											if(players[j]->getLife()<=0){
												players[j]->die();
												players[myId]->sound_victory(players[myId]->getX(),players[myId]->getY());
											}
										}
										delete projectiles[i];
										projectiles[i]=NULL;
										break;
									}
								}
							}
						}
					}
				}


			//Move all bullets;
			for(int j=0;j<maxClients;j++){
				if(players[j]!=NULL){
					Projectile **projectiles=players[j]->getProjectiles();
					for(int i=0;i<SCREEN_PROJECTILES;i++)
						if(projectiles[i]!=NULL)
							projectiles[i]->move();
				}
			}
			players[myId]->shoot(mouseState,&conn);

			senderBuffer.type=PROTOCOL_CHARACTER;
			players[myId]->serialize(senderBuffer.buffer);
			conn.send_packet_unreliable(&senderBuffer,strlen(senderBuffer.buffer)+2,0);

			redraw=true;
		}

		if(redraw && al_is_event_queue_empty(event_queue)){
			map.draw_map(mapX,mapY);
			for(int i=0;i<maxClients;i++)
				if(players[i]!=NULL && !players[i]->getDead())
					players[i]->draw(mapX,mapY);
			if(players[myId]->getDead()){
				if(players[myId]->tryToRevive()){
					senderBuffer.type=PROTOCOL_REVIVE;
					std::stringstream stream;
					stream << players[myId]->getX() << " "<< players[myId]->getY() << " ";
					std::sprintf(senderBuffer.buffer,"%s",stream.str().c_str());
					conn.send_packet_reliable(&senderBuffer,strlen(senderBuffer.buffer)+2,0);
				}
			}

			/*	else if (players[i]!=NULL)
					players[i]->draw(0,0);*/
			al_flip_display();
		}

	}
}

bool Client::connect(){
	char *buffer;
	bool bPeers,bMap,bSpawn;
	bPeers=bMap=bSpawn=false;
	if(!conn.create_client(ip,port))
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
				players[myId]=new CCharacter(myWeapon);
				//Now I will respond the server with my Weapon;
				std::stringstream stream;
				stream <<(int16_t)myWeapon <<" ";
				senderBuffer.type=PROTOCOL_MY_WEAPON;
				std::sprintf(senderBuffer.buffer,"%s",stream.str().c_str());
				conn.send_packet_reliable(&senderBuffer,strlen(senderBuffer.buffer)+2,0);
				std::cout << "I was created\n";
				bPeers=true;
				//connected. Now I want the map;
			}else if(buffer[0]==PROTOCOL_MAP_FILE){
				map.deserialize(buffer);
				std::cout << "Now I have the map\n";
				bMap=true;
				//Now i need to know my position
			}else if(buffer[0]==PROTOCOL_SET_POS_TEAM){
				std::stringstream stream;
				recieverBuffer=(_data*)conn.getPacketData();
				int16_t x,y;
				int16_t team;
				stream << recieverBuffer->buffer;
				stream >> x >> y >> team;
				players[myId]->setX(x);
				players[myId]->setSpawnX(x);
				players[myId]->setY(y);
				players[myId]->setSpawnY(y);
				players[myId]->setTeam((Team)team);
				std::cout << "Now I know where I should be\n";
				bSpawn=true;
			}
		}
		if(bPeers && bMap && bSpawn)
			return true;
	}
	return false;
}
