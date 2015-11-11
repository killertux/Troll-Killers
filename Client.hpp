#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "CMap.hpp"
#include "Defines.hpp"
#include "Connection.hpp"
#include "Enums.hpp"
#include "CCharacter.hpp"

#include <iostream>

#define MAP_FILE "Maps/mapa.data"

class Client{
private:
	ALLEGRO_DISPLAY *display;
	ALLEGRO_EVENT_QUEUE *event_queue;
	ALLEGRO_TIMER *timer;
	ALLEGRO_KEYBOARD_STATE keyState;
	ALLEGRO_EVENT ev;
	
	Connection conn;
	CMap map;
	CCharacter **players;
	
	bool storeKeys[ALLEGRO_KEY_MAX];
	int mapX,mapY;
public:
	Client();
	~Client();
	
	void main_loop();
};

#endif