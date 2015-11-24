#ifndef WEAPONS_CPP
#define WEAPONS_CPP

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include "Defines.hpp"
#include "Enums.hpp"
#include <cmath>
#include "CProjectile.hpp"
#include "Connection.hpp"
#include <sstream>
#include <cstdio>

class Weapons{//Classe geral de armas, contendo as vari�veis necess�rias , como imagem , dados da arma e o som emitido
protected:
	ALLEGRO_BITMAP *gun;
	ALLEGRO_SAMPLE *sound;

	int16_t type;				//What Type of gun am I?
	int16_t x,y,radius;			//This radius is from the player;
	float angle;                //Angulo em que os tiros podem sair, quanto maior o angulo , maior a possivel dispers�o dos tiros
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
	int16_t getDmg(){return dmg;}
	float getAngle(){return angle;}
	Projectile **getProjectiles(){return (Projectile**)projectiles;}
	void play_sound(float distance);

	void calculateAngle(int mapX,int mapY,int mouseX,int mouseY);

	virtual void draw(int mapX,int mapY);
	virtual void shoot(ALLEGRO_MOUSE_STATE &mouseState,Connection *conn)=0;
};

#endif
