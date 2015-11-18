#include "CCharacter.hpp"

//A lot of work to do

CCharacter::CCharacter(){
	player.radius=GRID/2-2;
	dir=(int16_t) STOPED;
	velocity=PLAYER_VELOCITY;
}

CCharacter::~CCharacter(){
	
}

int CCharacter::serialize(char* buffer)
{
	std::stringstream stream;
	stream << player.x << player.y << dir << " ";
	return stream.str().size();
}

void CCharacter::draw(int x,int y){
	al_draw_filled_circle(player.x-x,player.y-y,player.radius,al_map_rgb(player.r,player.g,player.b));
}

void CCharacter::move(){
	if(dir==UP)
		player.y-=velocity;
	if(dir==DOWN)
		player.y+=velocity;
	if(dir==LEFT)
		player.x-=velocity;
	if(dir==RIGHT)
		player.x+=velocity;
}
