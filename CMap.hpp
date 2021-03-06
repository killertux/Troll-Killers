/*
 * CMap.hpp -- Thats the client map class
 *
 *  Created on: 11 de nov de 2015
 *      Author: clemente
 */

#ifndef CMAP_HPP
#define CMAP_HPP

#include "Enums.hpp"
#include "_object.hpp"
#include "Map.hpp"

#include <string>
#include <fstream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <cstring>

class CMap:public Map{
	bool drawCircles;		//So we don't draw the spawn areas
public:
	CMap(std::string name,int max_objects,int length,int width);
	CMap();
	void new_object(_object object);
	void destroy_object(int x,int y);
	void draw_map(int x,int y);
	void setDrawCircles(bool drawCircles){this->drawCircles=drawCircles;}
	_object *getObjects(){return this->objects;}
	int getNobject(){return n_object;}
	~CMap();
};


#endif