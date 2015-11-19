#ifndef WEAPONS_CPP
#define WEAPONS_CPP

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <cmath>

class Weapons{
protected:
	ALLEGRO_BITMAP *gun;
	int16_t x,y,radius;			//This radius is from the player;
	float angle;
	int16_t dmg;
public:
	void setX(int16_t x){this->x=x;}
	void setY(int16_t y){this->y=y;}
	void setRadius(int16_t radius){this->radius=radius;}
	void setAngle(float angle){this->angle=angle;}
	int16_t getX(){return x;}
	int16_t getY(){return y;}
	float getAngle(){return angle;}
	
	void calculateAngle(int mapX,int mapY,int mouseX,int mouseY);
	
	virtual void draw(int mapX,int mapY)=0;
	virtual void shoot()=0;
	virtual ~Weapons(){al_destroy_bitmap(gun);}
};

#endif