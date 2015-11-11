//Struct that defines how data will be send between the client and the server

#ifndef DATA_HPP
#define DATA_HPP

#include "stdint.h"
#define BUFFER_SIZE 1024

struct Data{
	int8_t type;
	char buffer[BUFFER_SIZE];
};

#endif