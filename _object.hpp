#ifndef _OBJECT_HPP
#define _OBJECT_HPP
#include <stdint.h>

struct _object{
	int8_t type;
	int16_t x,y;
	int16_t radius;
	int16_t length, width;
	int16_t r;		//Unfortunatly stringstreams do not recognise int8_t
	int16_t g;		//So we are overkilling using int16_t
	int16_t b;	
};

#endif