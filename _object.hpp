#ifndef _OBJECT_HPP
#define _OBJECT_HPP
#include <stdint.h>

struct _object{
	int8_t type;
	int16_t x,y;
	int16_t radius;
	int16_t length, width;
	int8_t r;
	int8_t g;
	int8_t b;
};

#endif