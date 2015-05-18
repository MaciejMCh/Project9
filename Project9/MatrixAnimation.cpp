#include "MatrixAnimation.h"


MatrixAnimation::MatrixAnimation()
{
}

MatrixAnimation::MatrixAnimation(glm::mat4 aM)
{
	this->mModelMatrix = aM;
}


MatrixAnimation::~MatrixAnimation()
{
}

glm::mat4 MatrixAnimation::getModelMatrix(){
	return mModelMatrix;
}