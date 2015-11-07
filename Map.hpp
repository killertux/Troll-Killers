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
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

class Map{
private:
	std::string Name;
	_object *objects;
	int length, width;
	int max_objects;
	int n_object;
public:
	Map(std::string Name,int max_objects,int length,int width);
	Map(std::string path);
	void new_object(_object object);
	void destroy_object(float x,float y);
	void draw_map();
	~Map();
};

#endif