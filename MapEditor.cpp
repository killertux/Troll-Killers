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
}

MapEditor::~MapEditor() {
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
	al_destroy_timer(timer);
}

void MapEditor::mainLoop(){
	bool done=false;

	al_clear_to_color(al_map_rgb(255,255,255));
	al_start_timer(timer);
	while(!done){
		al_wait_for_event(event_queue, &ev);

		if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			done=true;

	}
}
