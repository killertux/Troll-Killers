#ifndef CURSOR_HPP
#define CURSOR_HPP

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "Defines.hpp"
#include "Enums.hpp"

class Cursor{
private:
	int x,y;
	int resX,resY;
	int timer;
	int cTimer;
	
	Direction dir;
	bool moved;
public:
	Cursor(int x,int y,int resX,int resY,int timer);
	void draw_cursor();
	void move_cursor(ALLEGRO_KEYBOARD_STATE keyState);
};

#endif