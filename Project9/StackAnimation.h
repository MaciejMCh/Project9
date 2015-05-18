#pragma once

#include "glObjectAnimation.h"
#include <vector>

class StackAnimation:
	public glObjectAnimation
{
public:
	StackAnimation();
	~StackAnimation();
	void addAnimation(glObjectAnimation* aA);
	virtual glm::mat4 getModelMatrix();


private: std::vector<glObjectAnimation* > mList;
};

