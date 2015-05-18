#include "PointLight.h"

#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "common.h"
#include "glProgram.h"

PointLight::PointLight()
{
}

PointLight::PointLight(float* aC, float* aP, float* aF, float aS)
{
	this->mColor = aC;
	this->mPosition = aP;
	this->mFunction = aF;
	this->mSpecular = aS;
}

float* PointLight::getColor(){
	return mColor;
}
float* PointLight::getPosition(){
	return mPosition;
}
float* PointLight::getFunction(){
	return mFunction;
}
float PointLight::getSpecular(){
	return mSpecular;
}

PointLight::~PointLight()
{
}