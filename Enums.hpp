#ifndef ENUMS_HPP
#define ENUMS_HPP

enum ObjectType {
	CIRCLE=1,
	RECTANGLE=2,
	NONE=0
};

enum Direction {
	UP,
	DOWN,
	LEFT,
	RIGHT,
	STOPED,
	UL,		//Up and left		//We dind't implement this yet
	UR,		//Up and right
	DL,		//Down and left
	DR		//Down and right
};

enum Team{
	RED=0x1,
	BLUE=0x2,
	TNONE=0x3
};

enum Weapon{
	RIFLE,
	PISTOL
};

#endif
