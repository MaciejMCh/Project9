#pragma once

#include "glm/gtc/type_ptr.hpp"

class glObjectAnimation
{
public:
	glObjectAnimation();
	~glObjectAnimation();
	virtual glm::mat4 getModelMatrix() = 0;
protected:
	glm::mat4 mModelMatrix;
};

