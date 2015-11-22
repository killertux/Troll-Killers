#ifndef CPROJECTILE_HPP
#define CPROJECTILE_HPP

#include "Projectile.hpp"

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <math.h>

class CProjectile:public Projectile{

public:
	CProjectile(int16_t x,int16_t y,int16_t length,int16_t velocity,float angle);
	void draw(int mapX,int mapY);
};

#endif