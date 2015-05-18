#pragma once

#include "glObjectAnimation.h"

class TeleportAnimation: public glObjectAnimation
{
public:
	TeleportAnimation();
	~TeleportAnimation();
	TeleportAnimation(float aX, float aY, float aZ);
	TeleportAnimation(float* Pos, float *Rot, float* Scl);
	virtual glm::mat4 getModelMatrix();
};

