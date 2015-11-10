#ifndef CURSOR_HPP
#define CURSOR_HPP

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "Defines.hpp"
#include "Enums.hpp"
#include "_object.hpp"

class Cursor{
private:
	int x,y;
	int resX,resY;
	int timer;
	int cTimer;
	
	int lengthInc;
	int widthInc;
	
	Direction dir;
	bool moved;
		
	Team team;
	_object objCursor;
	ObjectType objSelected;
public:
	Cursor(int x,int y,int resX,int resY,int timer);
	void draw_cursor();
	void move_cursor(ALLEGRO_KEYBOARD_STATE keyState);
	
	int getX(){return x;}
	int getY(){return y;}
	void setX(int x){this->x=x;}
	void setY(int y){this->y=y;}
	
	void change_cursor(int i);
	void change_team();
	void increase_object(Direction incDir);
	_object getObject(int mapX,int mapY){objCursor.x+=mapX;objCursor.y+=mapY;return objCursor;}
	bool object_selected(){return (objSelected!=NONE)?true:false;}
};

#endif
