#include "SMap.hpp"

void SMap::calculateSpawn(){
	nSpawn=0;
	spawnCounter=0;
	int c=0;
	for(int i=0;i<n_object;i++)
		if(objects[i].type==CIRCLE)
				nSpawn++;
	spawnList=new _object*[nSpawn];
	inUse=new bool[nSpawn];
	for(int i=0;i<n_object;i++)
		if(objects[i].type==CIRCLE){
			spawnList[c]=&objects[i];
			inUse[c]=false;
			c++;
		}
}

_object* SMap::getSpaw(){
	_object *rtrn=spawnList[spawnCounter];
	spawnCounter++;
	if(spawnCounter>=nSpawn)
		spawnCounter=0;
	return rtrn;
}

bool SMap::useSpawn(_object *spawn){
	for(int i=0;i<nSpawn;i++)
		if(spawn==spawnList[i])
			if(inUse[i])
				return false;
			else
				inUse[i]=true;
}
