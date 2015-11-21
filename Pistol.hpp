#ifndef PISTOL_HPP
#define PISTOL_HPP

#include "Weapons.hpp"
#include <iostream>

class Pistol : public Weapons{
public:
	Pistol();
	virtual void shoot();
};

#endif