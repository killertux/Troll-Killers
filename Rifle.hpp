#ifndef RIFLE_HPP
#define RIFLE_HPP

#include "Weapons.hpp"
#include <iostream>

class Rifle : public Weapons{
public:
	Rifle();
	virtual void draw(int mapX,int mapY);
	virtual void shoot();
};

#endif