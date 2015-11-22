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
	endX=(velocity)*cos(angle);
	endY=(velocity)*sin(angle);
	x=x+endX;
	y=y+endY;
}

bool Projectile::collide(Projectile *projectile,_object &object){
	float angle=projectile->getAngle();
	int x=projectile->getX()+(projectile->getLength()*cos(angle));
	int y=projectile->getY()+(projectile->getLength()*sin(angle));
	float i,j;
	if(object.type==RECTANGLE)
		for(int c=0;c<projectile->getLength();c++){
			i=x+(float)c*cos(angle);
			j=y+(float)c*sin(angle);
			if(i>object.x && i<object.x+object.length && j>object.y && j<object.y+object.width)
				return true;
		}
	else if(object.type==CIRCLE)
		for(int c=0;c<projectile->getLength();c++){
			i=x+(float)c*cos(angle);
 			j=y+(float)c*sin(angle);
			if(sqrt(pow(i-object.x,2)+pow(j-object.y,2))<=object.radius)
				return true;
		}
	return false;
}

