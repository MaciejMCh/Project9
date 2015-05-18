#include "AmbientLight.h"

#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "common.h"
#include "glProgram.h"

AmbientLight::AmbientLight()
{
}


AmbientLight::~AmbientLight()
{
}

AmbientLight::AmbientLight(float* aC, float aA){
	this->mColor = aC;
	this->mAmplitude = aA;
}

void AmbientLight::PassData(){
	glUniform1f(glProgram::getInstance()->getHandle("LightAmbient"), this->mAmplitude);
	
	glUniform1f(glProgram::getInstance()->getHandle("AmbLightAmp"), this->mAmplitude);
	glUniform3fv(glProgram::getInstance()->getHandle("AmbLightColor"), 1, glm::value_ptr(glm::vec3(mColor[0], mColor[1], mColor[2])));
}