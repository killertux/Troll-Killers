#include "SCharacter.hpp"

//A lot of work to do

SCharacter::SCharacter(int id){
	velocity=PLAYER_VELOCITY;
	this->id=id;
	dir=(int16_t)STOPED;
	ready=false;
}
void SCharacter::make_ready(){
	ready=true;
}


SCharacter::~SCharacter(){

}

int SCharacter::serialize(char* buffer){

}

