#include "StackAnimation.h"


StackAnimation::StackAnimation()
{
}


StackAnimation::~StackAnimation()
{
}

void StackAnimation::addAnimation(glObjectAnimation* aA){
	this->mList.push_back(aA);
}

glm::mat4 StackAnimation::getModelMatrix(){
	glm::mat4 model = glm::mat4();
	for (int i = 0; i <= mList.size() - 1; i++){
		model = model * mList[i]->getModelMatrix();
	}
	return model;
}