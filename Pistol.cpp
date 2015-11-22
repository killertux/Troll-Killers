#include "Pistol.hpp"



Pistol::Pistol(){
	type=(int16_t)PISTOL;
	dmg=20;
	magSize=12;
	nProjectile=1;
	shootTimer=0;			//Because I am not an automatic
	dispersion=0.174533;		//10º
	shooted=false;
	
	gun = al_load_bitmap("../Weapons/pistol.png");
	if(gun==NULL){
		std::cout << "Pistol image problem!\n";
		exit(-1);
	}
}

void Pistol::shoot(ALLEGRO_MOUSE_STATE &mouseState){
	if((mouseState.buttons & 1) && !shooted){
		shooted=true;
		for(int i=0;i<SCREEN_PROJECTILES;i++)
			if(projectiles[i]==NULL){
				float deviation= (float)rand()/(float)(RAND_MAX/dispersion)*2 -dispersion;
				projectiles[i]=new CProjectile(getWeaponTipX(),getWeaponTipY(),20,60,angle+deviation);
				//projectiles[i]=new CProjectile(x,y,20,60,angle);
				break;
			}
	} else if(!(mouseState.buttons & 1))
		shooted=false;
}
