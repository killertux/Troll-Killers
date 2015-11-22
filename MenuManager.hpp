#ifndef MENUMANAGER_HPP
#define MENUMANAGER_HPP

#include <allegro5/allegro.h>
#include "Menu.hpp"
#include "Enums.hpp"
//#include "Client.hpp"

class Client;

class MenuManager{
private:
	IMenu *menu;
	int res_x,res_y;
public:
	MenuManager(int res_x,int res_y);
	int main_loop(ALLEGRO_TIMER *timer,ALLEGRO_EVENT_QUEUE *event_queue, Client *myDad);
};

#include "Client.hpp"
#endif