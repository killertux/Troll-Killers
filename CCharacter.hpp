#ifndef CCHARACTER_HPP
#define CCHARACTER_HPP

//Character class to be handled by the client. A lot of allegro

#include "IGObject.hpp"
#include "Enums.hpp"
#include "_object.hpp"
#include "_data.hpp"
#include "Defines.hpp"
#include "Rifle.hpp"
#include "Pistol.hpp"
#include <sstream>
#include <math.h>
#include <cstdio>
#include "Connection.hpp"

#include <iostream>

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#define RESPAWN_TIMER 60*5

class CCharacter:public IGObject{
private:
	_object player;
	int16_t velocity;
	int16_t id;
	int16_t dir;		//Instead of using Direction and Team (enums)
	int16_t team;
	int16_t myWeapon;		//Name my weapon
	
	bool dead;
	int16_t xSpawn;
	int16_t ySpawn;
	int internalSpawnTimer;
	int life;
	
	Weapons *weapon;
	
	float distance(int x1,int x2);
public:
	CCharacter(Weapon myWeapon);
	~CCharacter();
	int16_t getId(){return id;}
	int16_t getX(){return player.x;}
	int16_t getY(){return player.y;}
	int16_t getVelocity(){return velocity;}
	int getLife(){return life;}
	_object *getPlayer(){return &player;}
	bool getDead(){return dead;}
	Team getTeam(){return (Team)team;}
	Direction getDir(){return (Direction)dir;}
	void setDir(Direction dir){this->dir=dir;}
	void serialize(char *buffer);
	
	void draw(int x,int y);
	void move();
	void die(){dead=true;}
	bool tryToRevive();
	void revive(int16_t x,int16_t y);
	void damage(int dmg){life-=dmg;}
	
	void colision(_object *objects,int n);
	
	void setX(int16_t x){this->player.x=x;weapon->setX(x);}
	void setY(int16_t y){this->player.y=y;weapon->setY(y);}
	void setSpawnX(int16_t x){this->xSpawn=x;}
	void setSpawnY(int16_t y){this->ySpawn=y;}
	void setTeam(Team team);
	
	void weaponAngle(int mapX,int mapY,int mouseX,int mouseY);
	void setWeaponAngle(float angle){weapon->setAngle(angle);}
	void shoot(ALLEGRO_MOUSE_STATE &mouseState,Connection *conn){weapon->shoot(mouseState,conn);}
	int getWeaponDmg(){return weapon->getDmg();}
	void sound_shoot(int x,int y);
	Projectile **getProjectiles(){return weapon->getProjectiles();}
};

#endif