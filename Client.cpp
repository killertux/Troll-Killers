#include "Client.hpp"

Client::Client(){
	if(!al_init())
		exit(-1);
	al_init_primitives_addon();
	al_install_keyboard();
	
	//al_set_new_display_flags(ALLEGRO_FULLSCREEN);
	
	
	display=al_create_display(RES_X,RES_Y);
	event_queue=al_create_event_queue();
	timer=al_create_timer(1/FPS);
	
	al_register_event_source(event_queue,al_get_display_event_source(display));
	al_register_event_source(event_queue,al_get_keyboard_event_source());
	al_register_event_source(event_queue,al_get_timer_event_source(timer));
	
	al_hide_mouse_cursor(display);
	
	if(map.load_map("../mapa.data"))
	maxClients=0;
	
	for(int i=0;i<ALLEGRO_KEY_MAX;i++)
		storeKeys[i]=false;
	mapX=mapY=0;
}

Client::~Client(){
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
			al_get_keyboard_state(&keyState);
			redraw=true;
		}
		
		if(redraw && al_is_event_queue_empty(event_queue)){
			map.draw_map(mapX,mapY);
			al_flip_display();
			
		}
		
	}
}

bool Client::connect(){
	char stdBuffer[255];
	if(!conn.create_client("127.0.0.1",PORT))
		return false;
	while(conn.event_service(10000)!=0){
		if(conn.event_type_receive()){
		//	std::memset(&dataBuffer,0,sizeof(_data));
			recieverBuffer=(_data*)conn.getPacketData();
			if(recieverBuffer->type==PROTOCOL_N_PEERS){
				maxClients=recieverBuffer->buffer[0];
				myId=recieverBuffer->buffer[1];
				players=new CCharacter*[maxClients];
				//connected. Now I want the map;
				
				return true;
			}
		}
	}
	return false;
}