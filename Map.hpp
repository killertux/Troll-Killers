/*
 * Map.hpp -- Thats the client map class
 *
 *  Created on: 7 de nov de 2015
 *      Author: clemente
 */

#ifndef MAP_HPP
#define MAP_HPP

#include <fstream>
#include <sstream>
#include "Enums.hpp"
#include "_object.hpp"
#include "_data.hpp"
#include "Defines.hpp"


struct _nMap{				//Last edit: IS a bad idea to use this...
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

	virtual int serialize(char *buffer);
	virtual void deserialize(char *buffer);
	_object *getObjects(){return objects;}

	//std::string getName(){return name;}
	~Map();
};


#endif
