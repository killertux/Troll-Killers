/*
 * MapEditor.hpp
 *
 *  Created on: 4 de nov de 2015
 *      Author: clemente
 */

#ifndef MAPEDITOR_HPP_
#define MAPEDITOR_HPP_

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "Map.hpp"
#include "Defines.hpp"

#define MAX_OBJECTS 500
#define LENGTH 300
#define WIDTH 200

class MapEditor {
private:
	ALLEGRO_DISPLAY *display;
	ALLEGRO_EVENT_QUEUE *event_queue;
	ALLEGRO_TIMER *timer;
	ALLEGRO_KEYBOARD_STATE keyState;
	ALLEGRO_EVENT ev;
	
	Map *map;
public:
	MapEditor();
	~MapEditor();

	void mainLoop();
	
};

#endif /* MAPEDITOR_HPP_ */
