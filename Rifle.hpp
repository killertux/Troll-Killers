#ifndef RIFLE_HPP
#define RIFLE_HPP

#include "Weapons.hpp"
#include <iostream>

class Rifle : public Weapons{
	int internalTimer;
public:
	Rifle();
	virtual void shoot(ALLEGRO_MOUSE_STATE &mouseState,Connection *conn);
};

#endif