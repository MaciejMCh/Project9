#pragma once
#include "SceneFeature.h"
class PointLight
{
public:
	PointLight();
	PointLight(float* aC, float* aP, float* aF, float aS);
	~PointLight();

	float* getColor();
	float* getPosition();
	float* getFunction();
	float getSpecular();

protected:
	float* mColor;
	float* mPosition;
	float* mFunction;
	float mSpecular;
};

