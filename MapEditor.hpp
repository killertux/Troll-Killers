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

#define RES_X 1360
#define RES_Y 768
#define FPS 60.0

class MapEditor {
private:
	ALLEGRO_DISPLAY *display;
	ALLEGRO_EVENT_QUEUE *event_queue;
	ALLEGRO_TIMER *timer;
	ALLEGRO_KEYBOARD_STATE keyState;
	ALLEGRO_EVENT ev;
public:
	MapEditor();
	virtual ~MapEditor();

	void mainLoop();
};

#endif /* MAPEDITOR_HPP_ */
