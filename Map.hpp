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
#include "cstdio"
#include <sstream>
#include "Defines.hpp"

#include <string>
#include <fstream>

class Map{
protected:
	std::string name;
	_object *objects;
	int16_t length, width;
	int16_t max_objects;
	int16_t n_object;
public:
	Map();
	virtual bool save_map(std::string pathname);
	virtual bool load_map(std::string pathname);
	
	virtual _data send_serial();
	virtual void get_serial(_data &buffer);
	
	std::string getName(){return name;}
	~Map();
};


#endif