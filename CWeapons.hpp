#include "Weapons.hpp"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

class Pistol : public Weapon{
    dmg = 20;
public:
    ALLEGRO_BITMAP *gun = NULL;
    Pistol ();
};

class Rifle : public Weapon{
    dmg = 50;
public:
    ALLEGRO_BITMAP *gun = NULL;
    Rifle();
};

