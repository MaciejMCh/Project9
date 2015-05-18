#pragma once
#include "SceneFeature.h"
class AmbientLight :
	public SceneFeature
{
public:
	AmbientLight();
	~AmbientLight();
	AmbientLight(float* aC, float aA);
	virtual void PassData();

private:
	float* mColor;
	float mAmplitude;
};

