/*
 * Map.hpp -- Thats the clietn map class
 *
 *  Created on: 7 de nov de 2015
 *      Author: clemente
 */

#ifndef MAP_HPP
#define MAP_HPP

#include "Enums.hpp"
#include "_object.hpp"
#include "_data.hpp"
#include <sstream>
#include "Defines.hpp"
#include <arpa/inet.h>

#include <fstream>

struct _nMap{
	int8_t type;			//Reserved to network usage
	char name[50];			//We are not using std::String to be portable.
	_object *objects;
	int16_t length, width;
	int16_t max_objects;
	int16_t n_object;
};

class Map{
protected:
	int8_t type;			//Reserved to network usage
	char name[50];			//We are not using std::String to be portable.
	_object *objects;
	int16_t length, width;
	int16_t max_objects;
	int16_t n_object;
public:
	Map();
	virtual bool save_map(std::string pathname);
	virtual bool load_map(std::string pathname);
	
	virtual int serielize(char *buffer);
	virtual void deserielize(char *buffer);
	
	std::string getName(){return name;}
	~Map();
};


#endif