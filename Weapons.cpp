#include "Weapons.hpp"

#include <iostream>
void Weapons::calculateAngle(int mapX,int mapY,int mouseX, int mouseY){
	//int dist=sqrt(pow(x-mapX-mouseX))
	angle=atan(((float)(y-mapY-mouseY))/(x-mapX-mouseX));
	if(x-mapX-mouseX>=0)
		angle-=M_PI;

	std::cout << mouseX <<" " << mouseY << " " << angle << std::endl;
}
