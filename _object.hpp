#ifndef _OBJECT_HPP
#define _OBJECT_HPP
#include <allegro5/allegro.h>

struct _object{
	ObjectType type;
	float x,y;
	float radius;
	float length, width;
	ALLEGRO_COLOR color;
};

#endif