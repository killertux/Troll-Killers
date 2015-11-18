#ifndef CCHARACTER_HPP
#define CCHARACTER_HPP

//Character class to be handled by the client. A lot of allegro

#include "IGObject.hpp"
#include "Enums.hpp"
#include "_object.hpp"
#include "_data.hpp"
#include "Defines.hpp"

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

class CCharacter:public IGObject{
private:
	_object player;
	int16_t velocity;
	int16_t id;
	int16_t dir;		//Instead of using Direction and Team (enums)
	int16_t team;
public:
	CCharacter();
	~CCharacter();
	int16_t getId(){return id;}
	int16_t getX(){return player.x;}
	int16_t getY(){return player.y;}
	int16_t getVelocity(){return velocity;}
	Team getTeam(){return (Team)team;}
	Direction getDir(){return (Direction)dir;}
	void setDir(Direction dir){this->dir=dir;}
	int serialize(char *buffer);
	
	void draw(int x,int y);
	void move();
	
	void setX(int16_t x){this->player.x=x;}
	void setY(int16_t y){this->player.y=y;}
	void setTeam(Team team){this->team=(int16_t)team;}
};

#endif