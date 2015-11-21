#include "Rifle.hpp"


Rifle::Rifle(){
	dmg=50;
	gun = al_load_bitmap("../Weapons/rifle.png");
	if(gun==NULL){
		std::cout << "Rifle image problem!\n";
		exit(-1);
	}
}

void Rifle::shoot()
{

}
