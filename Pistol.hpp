#ifndef PISTOL_HPP
#define PISTOL_HPP

#include "Weapons.hpp"
#include <iostream>
#include <math.h>

class Pistol : public Weapons{
	bool shooted;
public:
	Pistol();
	virtual void shoot(ALLEGRO_MOUSE_STATE &mouseState,Connection *conn);
};

#endif