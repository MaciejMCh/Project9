#ifndef glObjectFactory_H
#define glObjectFactory_H

#include "common.h"
#include "globject.h"
#include "glObjectDraw.h"
#include <vector>


class glObjectFactory
{
public:
	glObjectFactory();
	~glObjectFactory();
	std::vector <glObjectDraw* > getObjects();

protected:
	std::vector <glObjectDraw* > mList;
};

#endif