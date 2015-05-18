#include "glObjectFactory.h"

glObjectFactory::glObjectFactory()
{
}


glObjectFactory::~glObjectFactory()
{
}

std::vector<glObjectDraw* > glObjectFactory::getObjects(){
	return this->mList;
}