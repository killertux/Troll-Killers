#include "_data.hpp"
#include "stdio.h"

#define BYTE 8

void data::int_copy(char *buffer,int n1,int bytesI,int nBytes){
	for(int i=bytesI;i<bytesI+nBytes;i++){
		buffer[i]=n1 & 0xff;
		n1 = n1 >> BYTE;
	}
}

int data::int_get(char *buffer,int bytesI,int nBytes){
	int rtrn=0;
	for(int i=bytesI;i<bytesI+nBytes;i++){
		rtrn = buffer[i];
		rtrn = rtrn << BYTE;
	}
	return rtrn;
}
