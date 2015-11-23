#include "Rifle.hpp"


Rifle::Rifle(){
	type=(int16_t)RIFLE;
	dmg=50;
	magSize=20;
	nProjectile=1;
	shootTimer=35;
	dispersion=0.0872665;		//5º
	internalTimer=0;
	
	gun = al_load_bitmap("Weapons/rifle.png");
	if(gun==NULL){
		std::cout << "Rifle image problem!\n";
		exit(-1);
	}
	sound= al_load_sample("Sounds/rifle.ogg");
}

void Rifle::shoot(ALLEGRO_MOUSE_STATE &mouseState,Connection *conn){
	internalTimer++;
	_data senderBuffer;
	if((mouseState.buttons & 1) && internalTimer>shootTimer){
		internalTimer=0;
		al_play_sample(sound,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
		for(int i=0;i<SCREEN_PROJECTILES;i++)
			if(projectiles[i]==NULL){
				float deviation= (float)rand()/(float)(RAND_MAX/dispersion)*2 -dispersion;
				std::stringstream stream;
				projectiles[i]=new CProjectile(getWeaponTipX(),getWeaponTipY(),20,60,angle+deviation);
				stream << i << " " << getWeaponTipX() << " " <<getWeaponTipY() << " " << 20 << " " << 60 << " " << angle+deviation << " ";
				senderBuffer.type=PROTOCOL_NEW_SHOOT ;
				std::sprintf(senderBuffer.buffer,"%s",stream.str().c_str());
				conn->send_packet_reliable(&senderBuffer,strlen(senderBuffer.buffer)+2,0);
				break;
			}
	}
}
