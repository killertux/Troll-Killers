#include "Weapons.hpp"

#include <iostream>
void Weapons::calculateAngle(int mapX,int mapY,int mouseX, int mouseY){
	float dist1=sqrt(pow(x-mapX-mouseX,2)+pow(y-mapY-mouseY,2));
	angle=atan(((float)(y-mapY-mouseY))/(x-mapX-mouseX))-atan(radius/dist1);
	if(x-mapX-mouseX>=0)
		angle-=M_PI;
}
