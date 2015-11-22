#include "CProjectile.hpp"

#include <iostream>

void CProjectile::draw(int mapX,int mapY){
	int endX,endY;
	endX=length*cos(angle)+x;
	endY=length*sin(angle)+y;
	al_draw_line(x-mapX,y-mapY,endX-mapX,endY-mapY,al_map_rgb(0,0,0),2);
}

CProjectile::CProjectile(int16_t x, int16_t y, int16_t length, int16_t velocity,float angle){
	this->velocity=velocity;
	this->x=x;
	this->y=y;
	this->length=length;
	this->angle=angle;
}