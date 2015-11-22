#include "Rifle.hpp"


Rifle::Rifle(){
	type=(int16_t)RIFLE;
	dmg=50;
	magSize=20;
	nProjectile=1;
	shootTimer=55;
	dispersion=0.17453;		//10º
	
	gun = al_load_bitmap("../Weapons/rifle.png");
	if(gun==NULL){
		std::cout << "Rifle image problem!\n";
		exit(-1);
	}
}

void Rifle::shoot(ALLEGRO_MOUSE_STATE &mouseState)
{

}
