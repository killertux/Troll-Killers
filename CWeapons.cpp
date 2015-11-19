#include "Weapons.hpp"
#include "CWeapons.hpp"

Pistol::Pistol(){
	dmg=20;
	gun = al_load_bitmap("Weapons\\pistol.jpg");
}

Rifle::Rifle(){
	dmg=50;
	gun = al_load_bitmap("Weapons\\rifle.jpg");
}

