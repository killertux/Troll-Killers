#ifndef RIFLE_HPP
#define RIFLE_HPP

#include "Weapons.hpp"
#include <iostream>

class Rifle : public Weapons{
public:
	Rifle();
	virtual void shoot();
};

#endif