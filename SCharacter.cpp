#include "SCharacter.hpp"

//A lot of work to do

SCharacter::SCharacter(int id){
	velocity=0;
	this->id=id;
	dir=(int16_t)DOWN;
}

SCharacter::~SCharacter(){

}

int SCharacter::serialize(char* buffer){

}

