#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <iostream>

#include "_data.hpp"
#include "CMap.hpp"
#include "Defines.hpp"
#include "Connection.hpp"
#include "Enums.hpp"
#include "CCharacter.hpp"
#include "MenuManager.hpp"
#include "Configuration.hpp"

class Client{
private:
	ALLEGRO_DISPLAY *display;
	ALLEGRO_EVENT_QUEUE *event_queue;
	ALLEGRO_TIMER *timer;
	ALLEGRO_MOUSE_STATE mouseState;
	ALLEGRO_EVENT ev;
	MenuManager *menus;
	
	Connection conn;
	Configuration config;
	CMap map;
	CCharacter **players;
	_data *recieverBuffer;
	_data senderBuffer;
	int myId;
	char *buffer;
	Weapon myWeapon;
	
	int res_x,res_y;
	int port;
	std::string ip;
	
	bool *moved;
	bool storeKeys[ALLEGRO_KEY_MAX];
	int mapX,mapY;
	int maxClients;
	
public:
	Client();
	~Client();
	
	void setWeapon(Weapon myWeapon){this->myWeapon=myWeapon;}
	
	void menu(){menus->main_loop(timer,event_queue,this);}
	
	bool connect();
	
	void main_loop();
};

#endif