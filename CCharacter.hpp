#ifndef CCHARACTER_HPP
#define CCHARACTER_HPP

//Character class to be handled by the client. A lot of allegro

#include "IGObject.hpp"
#include "Enums.hpp"
#include "_object.hpp"
#include "_data.hpp"

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

class CCharacter:public IGObject{
private:
	_object player;
	int velocity;
	int id;
	Direction dir;
	Team team;
public:
	CCharacter();
	~CCharacter();
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