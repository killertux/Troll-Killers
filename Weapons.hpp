#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

class Weapon{
    int pos_x , pos_y, ang_x, ang_y;
    int dmg;
    ALLEGRO_BITMAP *gun = NULL;
public:
    setposx (int x){
        pos_x = x;
    }
    setposy (int y){
        pos_y = y;
    }
    setangx(int x){
        ang_x = x;
    }
    setangy(int y){
        ang_y = y;
    }
    Weapon(ALLEGRO_BITMAP img){

    }
};

class pistol : public Weapon{
    dmg = 20;
};

class rifle : public Weapon{
    dmg = 50;
};
