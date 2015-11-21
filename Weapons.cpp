#include "Weapons.hpp"

#include <iostream>
void Weapons::calculateAngle(int mapX,int mapY,int mouseX, int mouseY){
	float dist1=sqrt(pow(x-mapX-mouseX,2)+pow(y-mapY-mouseY,2));
	angle=atan(((float)(y-mapY-mouseY))/(x-mapX-mouseX))-atan(radius/dist1);
	if(x-mapX-mouseX>=0)
		angle-=M_PI;
}

void Weapons::draw(int mapX, int mapY)
{
	int mx=al_get_bitmap_width(gun)/2;
	int my=al_get_bitmap_height(gun)/2;
	al_draw_rotated_bitmap(gun,-radius,my,x-mapX,y-mapY,angle+M_PI/2,0);
	//al_draw_bitmap(gun,x-mapX,y-mapY,0);
}