#ifndef IGOBJECT_HPP
#define IGOBJECT_HPP

#include "Enums.hpp"
#include "_data.hpp"

class IGObject{
public:
	virtual int getId() = 0;
	virtual int getX() = 0;
	virtual int getY() = 0;
	virtual int getVelocity() = 0;
	virtual Team getTeam() = 0;
	virtual Direction getDir() = 0;
	virtual int serialize(char *buffer)=0;
	
	virtual void setX(int x)=0;
	virtual void setY(int y)=0;
	virtual void setTeam(Team team)=0;
	
	virtual ~IGObject(){}
};

#endif