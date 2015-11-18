#include "Weapons.hpp"
#include "CWeapons.hpp"

Pistol::Pistol(){
    gun = al_load_bitmap("Weapons\\pistol.jpg");
}

Rifle::Rifle(){
    gun = al_load_bitmap("Weapons\\rifle.jpg");
}

