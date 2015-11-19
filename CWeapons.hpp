#include "Weapons.hpp"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#define

class Pistol : public Weapon{
public:
    ALLEGRO_BITMAP *gun = NULL;
    Pistol ();
};

class Rifle : public Weapon{
public:
    ALLEGRO_BITMAP *gun = NULL;
    Rifle();
};

