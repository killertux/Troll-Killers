/*
 * MapEditor.hpp
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
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <cstring>

class Map{
private:
	std::string name;
	_object *objects;
	int length, width;
	int max_objects;
	int n_object;
public:
	Map(std::string name,int max_objects,int length,int width);
	Map();
	void new_object(_object object);
	void destroy_object(float x,float y);
	void draw_map();
	virtual bool save_map(std::string pathname);
	virtual bool load_map(std::string pathname);
	~Map();
};


#endif