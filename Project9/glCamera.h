#pragma once

#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

class glCamera
{
public:
	glCamera();
	~glCamera();

	virtual glm::mat4 getViewMatrix()=0;

protected:
	glm::mat4 mViewMatrix;
};

