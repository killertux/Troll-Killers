#ifndef WEAPONS_CPP
#define WEAPONS_CPP

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "Defines.hpp"
#include "Enums.hpp"
#include <cmath>
#include "CProjectile.hpp"

#define SCREEN_PROJECTILES 150		//Max number of projectiles on the screen;

class Weapons{
protected:
	ALLEGRO_BITMAP *gun;
	int16_t type;				//What Type of gun am I?
	int16_t x,y,radius;			//This radius is from the player;
	float angle;
	int16_t dmg;
	int16_t magSize;
	int16_t nProjectile;
	int16_t shootTimer;
	float dispersion;
	
	CProjectile **projectiles;
public:
	Weapons();
	virtual ~Weapons();
	void setX(int16_t x){this->x=x;}
	void setY(int16_t y){this->y=y;}
	void setRadius(int16_t radius){this->radius=radius;}
	void setAngle(float angle){this->angle=angle;}
	int16_t getX(){return x;}
	int16_t getY(){return y;}
	int16_t getWeaponTipX();
	int16_t getWeaponTipY();
	float getAngle(){return angle;}
	
	void calculateAngle(int mapX,int mapY,int mouseX,int mouseY);
	
	virtual void draw(int mapX,int mapY);
	virtual void shoot(ALLEGRO_MOUSE_STATE &mouseState)=0;
};

#endif