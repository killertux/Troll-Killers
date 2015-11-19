#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "_data.hpp"
#include "CMap.hpp"
#include "Defines.hpp"
#include "Connection.hpp"
#include "Enums.hpp"
#include "CCharacter.hpp"
#include <cstdio>
#include <cstring>
#include <sstream>

#include <iostream>

#define MAP_FILE "Maps/mapa.data"

#define IP "127.0.0.1"
#define PORT 4665

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
	_data *recieverBuffer;
	_data senderBuffer;
	int myId;
	char *buffer;
	
	bool storeKeys[ALLEGRO_KEY_MAX];
	int mapX,mapY;
	int maxClients;
	
public:
	Client();
	~Client();
	
	bool connect();
	
	void main_loop();
};

#endif