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
namespace data{
	void int_copy(char *buffer,int n1,int bytesI,int nBytes);
	int int_get(char *buffer,int bytesI,int nBytes);
}
#endif