#include "Rifle.hpp"


Rifle::Rifle(){
	type=(int16_t)RIFLE;
	dmg=50;
	magSize=20;
	nProjectile=1;
	shootTimer=35;
	dispersion=0.0872665;		//5º
	internalTimer=0;
	
	gun = al_load_bitmap("../Weapons/rifle.png");
	if(gun==NULL){
		std::cout << "Rifle image problem!\n";
		exit(-1);
	}
}

void Rifle::shoot(ALLEGRO_MOUSE_STATE &mouseState){
	internalTimer++;
	if((mouseState.buttons & 1) && internalTimer>shootTimer){
		internalTimer=0;
		for(int i=0;i<SCREEN_PROJECTILES;i++)
			if(projectiles[i]==NULL){
				float deviation= (float)rand()/(float)(RAND_MAX/dispersion)*2 -dispersion;
				projectiles[i]=new CProjectile(getWeaponTipX(),getWeaponTipY(),20,60,angle+deviation);
				//projectiles[i]=new CProjectile(x,y,20,60,angle);
				break;
			}
	}
}
