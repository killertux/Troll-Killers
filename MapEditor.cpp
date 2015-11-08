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

	al_set_new_display_flags(ALLEGRO_FULLSCREEN);


	display=al_create_display(RES_X,RES_Y);
	event_queue=al_create_event_queue();
	timer=al_create_timer(1/FPS);

	al_register_event_source(event_queue,al_get_display_event_source(display));
	al_register_event_source(event_queue,al_get_keyboard_event_source());
	al_register_event_source(event_queue,al_get_timer_event_source(timer));

	al_hide_mouse_cursor(display);
	
	map = new Map("MapaTeste",MAX_OBJECTS,LENGTH*GRID,WIDTH*GRID);
	cursor = new Cursor(GRID*5,GRID*5,RES_X,RES_Y,5);
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
			if(ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE){
				exit(0);
			}
		} 
		else if(ev.type == ALLEGRO_EVENT_TIMER){
			al_get_keyboard_state(&keyState);
			cursor->move_cursor(keyState);
			
			redraw=true;
		}
		
		if(redraw && al_is_event_queue_empty(event_queue)){
			map->draw_map();
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
