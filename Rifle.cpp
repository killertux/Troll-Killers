#include "Rifle.hpp"


Rifle::Rifle(){
	dmg=50;
	gun = al_load_bitmap("../Weapons/rifle.png");
	if(gun==NULL){
		std::cout << "Rifle image problem!\n";
		exit(-1);
	}
}

void Rifle::draw(int mapX, int mapY)
{
	int mx=al_get_bitmap_width(gun)/2;
	int my=al_get_bitmap_height(gun)/2;
	al_draw_rotated_bitmap(gun,-radius,my,x-mapX,y-mapY,angle+M_PI/2,0);
	//al_draw_bitmap(gun,x-mapX,y-mapY,0);
}
void Rifle::shoot()
{

}
