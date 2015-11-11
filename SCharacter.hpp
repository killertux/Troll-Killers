#ifndef SCHARACTER_HPP
#define SCHARACTER_HPP

//Character class to be handled by the server. No allegro functions here!!

#include "IGObject.hpp"
#include "Enums.hpp"
#include "_object.hpp"
#include "_data.hpp"

class SCharacter:public IGObject{
private:
	_object player;
	int velocity;
	int id;
	Direction dir;
	Team team;
public:
	SCharacter(_data *data);
	int getId(){return id;}
	int getX(){player.x;}
	int getY(){player.y;}
	int getVelocity(){return velocity;}
	Team getTeam(){return team;}
	Direction getDir(){return dir;}
	void setDir(Direction dir){this->dir=dir;}
	_data serialize();
	
};

#endif