#pragma once
#include "SceneFeature.h"
class Material
{
public:
	Material();
	~Material();
	Material(float* aA, float* aD, float* aS, float aH);
	void PassData();

private:
	float* mDiffuse;
	float* mSpecular;
	float* mAmbient;
	float mShininess;
};

