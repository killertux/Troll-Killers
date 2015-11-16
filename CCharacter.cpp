#include "CCharacter.hpp"

//A lot of work to do

CCharacter::CCharacter(){
	player.radius=GRID/2-2;
}

CCharacter::~CCharacter(){
	
}

int CCharacter::serialize(char* buffer)
{

}

void CCharacter::draw(int x,int y){
	al_draw_filled_circle(player.x-x,player.y-y,player.radius,al_map_rgb(player.r,player.g,player.b));
}
