#include "Cursor.hpp"

Cursor::Cursor(int x, int y, int resX, int resY, int timer){
	this->x=x;
	this->y=y;
	this->resX=resX;
	this->resY=resY;
	this->timer=timer;
	cTimer=0;
}


void Cursor::draw_cursor(){
	al_draw_line(x-10,y,x+10,y,al_map_rgb(0,0,0),4);
	al_draw_line(x,y-10,x,y+10,al_map_rgb(0,0,0),4);
}

void Cursor::move_cursor(ALLEGRO_KEYBOARD_STATE keyState){
	cTimer++;
	
	if(al_key_down(&keyState, ALLEGRO_KEY_UP))
		dir=UP;
	else if(al_key_down(&keyState, ALLEGRO_KEY_DOWN))
		dir=DOWN;
	if(al_key_down(&keyState, ALLEGRO_KEY_LEFT))
		dir=LEFT;
	else if(al_key_down(&keyState, ALLEGRO_KEY_RIGHT))
		dir=RIGHT;
	if(cTimer>=timer){
		if(dir==UP && y>0)
			y-=GRID;
		else if(dir==DOWN && y<resY)
			y+=GRID;
		if(dir==LEFT&& x>0)
			x-=GRID;
		else if(dir==RIGHT && y<resX)
			x+=GRID;
		dir=STOPED;
		cTimer=0;
	}
}
