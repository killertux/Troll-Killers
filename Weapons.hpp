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
    void rotation (){
        float imageWidth, imageHeight;
        imageWidth = al_get_bitmap_width (gun);
        imageHeight = al_get_bitmap_height (gun);
        al_draw_rotated_bitmap(ALLEGRO_BITMAP *gun, imageWidth / 2 ,  imageHeight / 2 ,  dx,  dy, angle, 0) //preencher dx, dy e angle
    }
};

class Pistol : public Weapon{
    dmg = 20;
public:
    Pistol (){
        gun = al_load_bitmap("Weapons\\pistol.jpg");
    }
};

class Rifle : public Weapon{
    dmg = 50;
public:
    Rifle(){
        gun = al_load_bitmap("Weapons\\rifle.jpg");
    }
};
