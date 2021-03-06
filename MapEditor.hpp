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
#include "CMap.hpp"
#include "Defines.hpp"
#include "Cursor.hpp"

#include <iostream>

#define MAX_OBJECTS 500
#define LENGTH 30
#define WIDTH 20

#define RES_X 1024
#define RES_Y 768

#define MAP_FILE "Maps/mapa.data"

class MapEditor {
private:
	ALLEGRO_DISPLAY *display;
	ALLEGRO_EVENT_QUEUE *event_queue;
	ALLEGRO_TIMER *timer;
	ALLEGRO_KEYBOARD_STATE keyState;
	ALLEGRO_EVENT ev;

	Cursor *cursor;
	bool storeKeys[ALLEGRO_KEY_MAX];

	int mapX,mapY;

	CMap *map;
public:
	MapEditor();
	~MapEditor();

	void main_loop();
	void draw_grid();
};

#endif /* MAPEDITOR_HPP_ */
