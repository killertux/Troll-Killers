#include "Weapons.hpp"

#include <iostream>

Weapons::Weapons(){
	projectiles=new CProjectile*[SCREEN_PROJECTILES];
	for(int i=0;i<SCREEN_PROJECTILES;i++)
		projectiles[i]=NULL;
}
Weapons::~Weapons(){
	delete [] projectiles;
	al_destroy_bitmap(gun);
	al_destroy_sample(sound);
}



void Weapons::calculateAngle(int mapX,int mapY,int mouseX, int mouseY){
	float dist1=sqrt(pow(x-mapX-mouseX,2)+pow(y-mapY-mouseY,2));
	angle=atan(((float)(y-mapY-mouseY))/(x-mapX-mouseX))-atan(radius/dist1);
	if(x-mapX-mouseX>=0)
		angle-=M_PI;
	//angle+=M_PI/2;
}

void Weapons::draw(int mapX, int mapY)
{
	//int mx=al_get_bitmap_width(gun)/2;
	int my=al_get_bitmap_height(gun)/2;
	al_draw_rotated_bitmap(gun,-radius,my,x-mapX,y-mapY,angle+M_PI/2,0);
	//Drawing the projectiles now
	for(int i=0;i<SCREEN_PROJECTILES;i++)
		if(projectiles[i]!=NULL)
			projectiles[i]->draw(mapX,mapY);
		
}
int16_t Weapons::getWeaponTipX(){
	int mx=al_get_bitmap_width(gun)/2;
	int my=al_get_bitmap_height(gun)/2;
	int tangle=angle+M_PI/2;
	int d=cos(angle)*my-sin(angle)*mx;
	return x+cos(tangle)*radius+sin(tangle)+d;
}
int16_t Weapons::getWeaponTipY(){
	int mx=al_get_bitmap_width(gun)/2;
	int my=al_get_bitmap_height(gun)/2;
	int tangle=angle+M_PI/2;
	int d=sin(angle)*my+cos(angle)*mx;
	return y+sin(tangle)*radius+cos(tangle)+d;
}

void Weapons::play_sound(float distance){
	float volume=2*exp(-pow(distance,2)/pow(800,2));
	if(volume >1)
		volume=1;
	std::cout << volume <<std::endl;
	al_play_sample(sound,volume,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
}
