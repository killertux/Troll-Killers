#include "CCharacter.hpp"

//A lot of work to do

CCharacter::CCharacter(Weapon myWeapon){
	player.radius=GRID/2-2;
	dir=(int16_t) STOPED;
	velocity=PLAYER_VELOCITY;
	this->myWeapon=(int16_t)myWeapon;
	if(myWeapon==PISTOL)
		weapon = new Pistol;
	else if(myWeapon == RIFLE)
		weapon = new Rifle;
	weapon->setRadius(player.radius);
}

CCharacter::~CCharacter(){
	delete weapon;
}

void CCharacter::serialize(char* buffer){
	std::stringstream stream;
	stream << player.x << " " << player.y << " "<< dir << " " << weapon->getAngle() << " ";
	std::sprintf(buffer,"%s",stream.str().c_str());
}

void CCharacter::setTeam(Team team){
	this->team=(int16_t)team;
	if(team==RED){
		player.r=255;
		player.g=0;
		player.b=0;
	} else if(team==BLUE){
		player.r=0;
		player.g=0;
		player.b=255;
	}
}


void CCharacter::draw(int x,int y){
	al_draw_filled_circle(player.x-x,player.y-y,player.radius,al_map_rgb(player.r,player.g,player.b));
	weapon->draw(x,y);
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
	weapon->setX(player.x);
	weapon->setY(player.y);
}

void CCharacter::colision(_object *objects,int n){
	int centerX;
	int centerY;
	int hDistance;
	int vDistance;
	bool done=false;
	for(int i=0;i<n;i++){
		centerX=objects[i].x+objects[i].length/2;
		centerY=objects[i].y+objects[i].width/2;
		hDistance=objects[i].length/2+player.radius;
		vDistance=objects[i].width/2+player.radius;
		if(objects[i].type==RECTANGLE && distance(centerX,player.x)<hDistance&& 
			distance(centerY,player.y)<vDistance){
			while(!done){
				if(dir==(int16_t)UP)
					player.y++;
				else if(dir==(int16_t)DOWN)
					player.y--;
				else if(dir==(int16_t)LEFT)
					player.x++;
				else if(dir==(int16_t)RIGHT)
					player.x--;
				
				if(!(distance(centerX,player.x)<hDistance && distance(centerY,player.y)<vDistance)){
					done=true;
					weapon->setX(player.x);
					weapon->setY(player.y);
					dir=(int16_t)STOPED;
				}
			}
		}
		if(done)
			break;
	}
}

float CCharacter::distance(int x1, int x2){
	return sqrt(pow(x1-x2,2));
}

void CCharacter::weaponAngle(int mapX,int mapY,int mouseX, int mouseY){
	weapon->calculateAngle(mapX,mapY,mouseX,mouseY);
}

