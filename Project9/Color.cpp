#include "Color.h"

#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "common.h"
#include "glProgram.h"

Color::Color()
{
}

Color::Color(float* aA, float* aD, float* aS){
	this->mDiffuse = aD;
	this->mSpecular = aS;
	this->mAmbient = aA;
}

void Color::PassData(){
	//glUniform1f(glProgram::getInstance()->getHandle("MaterialAmbient"), this->mAmbient);
	glUniform3f(glProgram::getInstance()->getHandle("DiffColor"), mDiffuse[0], mDiffuse[1], mDiffuse[2]);
	glUniform3f(glProgram::getInstance()->getHandle("SpecColor"), mSpecular[0], mSpecular[1], mSpecular[2]);
	glUniform3f(glProgram::getInstance()->getHandle("AmbColor"), mAmbient[0], mAmbient[1], mAmbient[2]);
}

Color::~Color()
{
}
