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

#include <string>
#include <fstream>

class Map{
protected:
	std::string name;
	_object *objects;
	int length, width;
	int max_objects;
	int n_object;
public:
	Map();
	virtual bool save_map(std::string pathname);
	virtual bool load_map(std::string pathname);
	~Map();
};


#endif