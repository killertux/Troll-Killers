#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

#include "IGObject.hpp"
#include "_object.hpp"

#include <math.h>


class Projectile : public IGObject{
protected:
	int16_t velocity;
	int16_t id;
	int16_t x,y,length;
	float angle;

public:
	Projectile(int16_t x,int16_t y,int16_t length,int16_t velocity,float angle);
	Projectile();
	int16_t getId(){return id;}			
	int16_t getX(){return x;}
	int16_t getY(){return y;}
	float getAngle(){return angle;}
	int16_t getVelocity(){return velocity;}
	int16_t getLength(){return length;}
	void serialize(char *buffer);
	
	void setX(int16_t x){this->x=x;}
	void setY(int16_t y){this->y=y;}
	void setAngle(float angle){this->angle=angle;}
	
	static bool collide(Projectile *projectile,_object &object);
	
	void move();
};

#endif