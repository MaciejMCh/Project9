#include "DirectionalLight.h"

#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "common.h"
#include "glProgram.h"


DirectionalLight::DirectionalLight()
{
}

DirectionalLight::DirectionalLight(float* aD, float* aC, float aA, float aF, float aS){
	this->mAmplitude = aA;
	this->mColor = aC;
	this->mDirection = aD;
	this->mDiffuse = aF;
	this->mSpecular = aS;
};

DirectionalLight::~DirectionalLight()
{
}

void DirectionalLight::PassData(){
	glUniform1f(glProgram::getInstance()->getHandle("DirLightAmp"), this->mAmplitude);
	glUniform3fv(glProgram::getInstance()->getHandle("DirLightColor"), 1, glm::value_ptr(glm::vec3(mColor[0], mColor[1], mColor[2])));
	glUniform3fv(glProgram::getInstance()->getHandle("DirLightDir"), 1, glm::value_ptr(glm::vec3(mDirection[0], mDirection[1], mDirection[2])));
	glUniform1f(glProgram::getInstance()->getHandle("DirLightDiff"), this->mDiffuse);
	glUniform1f(glProgram::getInstance()->getHandle("DirLightSpec"), this->mSpecular);
}
