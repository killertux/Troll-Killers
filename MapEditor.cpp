/*
 * MapEditor.cpp
 *
 *  Created on: 4 de nov de 2015
 *      Author: clemente
 */

#include "MapEditor.hpp"

MapEditor::MapEditor() {
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
	
	map = new CMap("MapaTeste",MAX_OBJECTS,LENGTH*GRID,WIDTH*GRID);
	cursor = new Cursor(GRID*5,GRID*5,RES_X,RES_Y,5);
	
	for(int i=0;i<ALLEGRO_KEY_MAX;i++)
		storeKeys[i]=false;
	mapX=mapY=0;
}

MapEditor::~MapEditor() {
	delete map;
	delete cursor;
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
	al_destroy_timer(timer);
}

void MapEditor::main_loop(){
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
			
			//Cursor Comands;
			if(ev.keyboard.keycode == ALLEGRO_KEY_LEFT  && storeKeys[ALLEGRO_KEY_LCTRL])
				cursor->change_cursor(-1);
			if(ev.keyboard.keycode == ALLEGRO_KEY_RIGHT  && storeKeys[ALLEGRO_KEY_LCTRL])
				cursor->change_cursor(-1);
			
			if(ev.keyboard.keycode == ALLEGRO_KEY_RIGHT && storeKeys[ALLEGRO_KEY_ALT])
				cursor->increase_object(RIGHT);
			if(ev.keyboard.keycode == ALLEGRO_KEY_LEFT && storeKeys[ALLEGRO_KEY_ALT])
				cursor->increase_object(LEFT);
			if(ev.keyboard.keycode == ALLEGRO_KEY_DOWN && storeKeys[ALLEGRO_KEY_ALT])
				cursor->increase_object(DOWN);
			if(ev.keyboard.keycode == ALLEGRO_KEY_UP && storeKeys[ALLEGRO_KEY_ALT])
				cursor->increase_object(UP);
			if(ev.keyboard.keycode == ALLEGRO_KEY_ENTER && cursor->object_selected())
				map->new_object(cursor->getObject(mapX,mapY));
			if(ev.keyboard.keycode == ALLEGRO_KEY_DELETE)
				map->destroy_object(cursor->getX()+mapX,cursor->getY()+mapY);
			if(ev.keyboard.keycode == ALLEGRO_KEY_T)
				cursor->change_team();
			
			//Save and Load
			if(ev.keyboard.keycode == ALLEGRO_KEY_S){
				map->save_map((std::string)MAP_FILE);
				std::cout << "Map saved as " << MAP_FILE << std::endl;
			}
			if(ev.keyboard.keycode == ALLEGRO_KEY_L){
				map->load_map((std::string)MAP_FILE);
				std::cout << "Map " << MAP_FILE << " loaded!\n";
				
			}
			
		}
		else if(ev.type == ALLEGRO_EVENT_KEY_UP)
			storeKeys[ev.keyboard.keycode]=false;
		else if(ev.type == ALLEGRO_EVENT_TIMER){
			al_get_keyboard_state(&keyState);
			cursor->move_cursor(keyState);
			
			if(cursor->getX()>RES_X-2*GRID && mapX<LENGTH*GRID){
				mapX+=GRID;
				cursor->setX(cursor->getX()-GRID);
			}
			if(cursor->getX()<GRID && mapX>0){
				mapX-=GRID;
				cursor->setX(cursor->getX()+GRID);
			}
			if(cursor->getY()>RES_Y-2*GRID && mapY<WIDTH*GRID){
				mapY+=GRID;
				cursor->setY(cursor->getY()-GRID);
			}
			if(cursor->getY()<GRID && mapY>0){
				mapY-=GRID;
				cursor->setY(cursor->getY()+GRID);
			}
			
			redraw=true;
		}
		
		if(redraw && al_is_event_queue_empty(event_queue)){
			map->draw_map(mapX,mapY);
			cursor->draw_cursor();;
			draw_grid();
			al_flip_display();
			
		}

	}
}

void MapEditor::draw_grid(){
	for(int i=0;i<LENGTH*GRID;i+=GRID)
		al_draw_line(i,0,i,WIDTH*GRID,al_map_rgb(0,0,0),2);
	for(int j=0;j<WIDTH*GRID;j+=GRID)
		al_draw_line(0,j,LENGTH*GRID,j,al_map_rgb(0,0,0),2);
}
