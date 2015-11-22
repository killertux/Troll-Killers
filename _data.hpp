//Struct that defines how data will be send between the client and the server

#ifndef _DATA_HPP
#define _DATA_HPP

#include "stdint.h"
#include "cstring"
#define BUFFER_SIZE 2048

struct _data{
	int8_t type;
	char buffer[BUFFER_SIZE];
};
#endif