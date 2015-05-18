#pragma once
#include "SceneFeature.h"
class DirectionalLight :
	public SceneFeature
{
public:
	DirectionalLight();
	DirectionalLight(float* aD, float* aC, float aA, float aF, float aS);
	~DirectionalLight();
	virtual void PassData();

protected:
	float* mDirection;
	float* mColor;
	float mAmplitude;
	float mDiffuse;
	float mSpecular;
};

