#ifndef _OBJECT_HPP
#define _OBJECT_HPP
#include <stdint.h>

struct _object{
	int8_t type;
	int16_t x,y;
	int16_t radius;
	int16_t length, width;
	int16_t r;
	int16_t g;
	int16_t b;
};

#endif