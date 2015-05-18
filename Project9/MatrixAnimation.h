#pragma once
#include "glObjectAnimation.h"
class MatrixAnimation :
	public glObjectAnimation
{
public:
	MatrixAnimation();
	MatrixAnimation(glm::mat4 aM);
	~MatrixAnimation();

	virtual glm::mat4 getModelMatrix();
};

