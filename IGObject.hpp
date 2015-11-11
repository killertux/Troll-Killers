#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

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
	virtual _data serialize()=0;
	
	virtual ~IGObject(){}
};

#endif