#ifndef SMAP_HPP
#define SMAP_HPP

#include "Map.hpp"

class SMap : public Map{
private:
	int spawnCounter;
	_object **spawnList;
	bool *inUse;
	int nSpawn;
public:
	void calculateSpawn();
	_object *getSpaw();
	bool useSpawn(_object *spawn);
	//void freeSpawn(_object spawn);		//I need to implement his...
};

#endif