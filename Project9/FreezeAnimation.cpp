#include "FreezeAnimation.h"


FreezeAnimation::FreezeAnimation()
{
}

FreezeAnimation::FreezeAnimation(glm::mat4 aM){
	this->mModelMatrix = aM;
}


FreezeAnimation::~FreezeAnimation()
{
}

glm::mat4 FreezeAnimation::getModelMatrix(){
	return this->mModelMatrix;
}