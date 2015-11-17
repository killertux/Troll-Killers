#ifndef SCHARACTER_HPP
#define SCHARACTER_HPP

//Character class to be handled by the server. No allegro functions here!!

#include "IGObject.hpp"
#include "Enums.hpp"
#include "_object.hpp"
#include "_data.hpp"
#include <iostream>

class SCharacter:public IGObject{
private:
	_object player;
	int16_t velocity;
	int16_t id;
	int16_t dir;		//Instead of using Direction and Team (enums)
	int16_t team;		//We are using int16_t because of the endianes
public:
	SCharacter(int id);
	~SCharacter();
	int16_t getId(){return id;}
	int16_t getX(){return player.x;}
	int16_t getY(){return player.y;}
	int16_t getVelocity(){return velocity;}
	Team getTeam(){return (Team)team;}
	Direction getDir(){return (Direction)dir;}
	void setDir(Direction dir){this->dir=dir;}
	int serialize(char *buffer);
	
	void setX(int16_t x){player.x=x;}
	void setY(int16_t y){player.y=y;}
	void setTeam(Team team){this->team=(int16_t)team;}
};

#endif