#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

class Weapon{
    int pos_x , pos_y, ang_x, ang_y;
    int dmg;
    ALLEGRO_BITMAP *gun = NULL;
public:
    void setposx (int x){
        pos_x = x;
    }
    void setposy (int y){
        pos_y = y;
    }
    void setangx(int x){
        ang_x = x;
    }
    void setangy(int y){
        ang_y = y;
    }
    void rotation ();
};

class Pistol : public Weapon{
    dmg = 20;
public:
    Pistol ();
};

class Rifle : public Weapon{
    dmg = 50;
public:
    Rifle();
};
