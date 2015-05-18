#pragma once
#include "glObjectAnimation.h"
class FreezeAnimation :
	public glObjectAnimation
{
public:
	FreezeAnimation();
	FreezeAnimation(glm::mat4 aM);
	~FreezeAnimation();
	virtual glm::mat4 getModelMatrix();
};

