#include "Weapons.hpp"

void Weapon::rotation (){
        float imageWidth, imageHeight;
        imageWidth = al_get_bitmap_width (gun);
        imageHeight = al_get_bitmap_height (gun);
        al_draw_rotated_bitmap(ALLEGRO_BITMAP *gun, imageWidth / 2 ,  imageHeight / 2 ,  dx,  dy, angle, 0) //preencher dx, dy e angle
    }

