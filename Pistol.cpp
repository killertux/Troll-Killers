#include "Pistol.hpp"


Pistol::Pistol(){
	dmg=20;
	gun = al_load_bitmap("../Weapons/pistol.png");
	if(gun==NULL){
		std::cout << "Pistol image problem!\n";
		exit(-1);
	}
}

void Pistol::shoot()
{

}
