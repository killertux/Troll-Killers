#include "Projectile.hpp"

Projectile::Projectile(){
}

Projectile::Projectile(int16_t x, int16_t y, int16_t length, int16_t velocity,float angle){
	this->velocity=velocity;
	this->x=x;
	this->y=y;
	this->length=length;
	this->angle=angle;
}

void Projectile::serialize(char* buffer){

}

void Projectile::move(){
	int endX,endY;
	endX=(length+velocity)*cos(angle);
	endY=(length+velocity)*sin(angle);
	x=x+endX;
	y=y+endY;
}
