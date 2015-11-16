#ifndef IGOBJECT_HPP
#define IGOBJECT_HPP

#include "Enums.hpp"
#include "_data.hpp"

class IGObject{
public:
	virtual int16_t getId() = 0;
	virtual int16_t getX() = 0;
	virtual int16_t getY() = 0;
	virtual int16_t getVelocity() = 0;
	virtual Team getTeam() = 0;
	virtual Direction getDir() = 0;
	virtual int serialize(char *buffer)=0;
	
	virtual void setX(int16_t x)=0;
	virtual void setY(int16_t y)=0;
	virtual void setTeam(Team team)=0;
	
	virtual ~IGObject(){}
};

#endif