#include "Pistol.hpp"

Pistol::Pistol(){
	type=(int16_t)PISTOL;
	dmg=20;
	magSize=12;
	nProjectile=1;
	shootTimer=0;			//Because I am not an automatic
	dispersion=0.174533;		//10�
	shooted=false;
	
	gun = al_load_bitmap("Weapons/pistol.png");
	if(gun==NULL){
		std::cout << "Pistol image problem!\n";
		exit(-1);
	}
	sound= al_load_sample("Sounds/pistol.ogg");
}
//Here we shoot
void Pistol::shoot(ALLEGRO_MOUSE_STATE &mouseState,Connection *conn){
	if((mouseState.buttons & 1) && !shooted){	//Because it is an semi-automatic
		_data senderBuffer;
		al_play_sample(sound,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
		shooted=true;
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
	} else if(!(mouseState.buttons & 1))
		shooted=false;
}