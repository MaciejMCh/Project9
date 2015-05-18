#include "Material.h"

#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "common.h"
#include "glProgram.h"

Material::Material()
{
}

Material::Material(float* aA, float* aD, float* aS, float aH){
	this->mAmbient = aA;
	this->mDiffuse = aD;
	this->mSpecular = aS;
	this->mShininess = aH;
}

Material::~Material()
{
}

void Material::PassData(){
	glUniform3f(glProgram::getInstance()->getHandle("DiffColor"), mDiffuse[0], mDiffuse[1], mDiffuse[2]);
	glUniform3f(glProgram::getInstance()->getHandle("SpecColor"), mSpecular[0], mSpecular[1], mSpecular[2]);
	glUniform3f(glProgram::getInstance()->getHandle("AmbColor"), mAmbient[0], mAmbient[1], mAmbient[2]);
	glUniform1f(glProgram::getInstance()->getHandle("MaterialShininess"), this->mShininess);
}