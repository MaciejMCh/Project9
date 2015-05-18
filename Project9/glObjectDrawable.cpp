#include "glObjectDrawable.h"
#include "scene.h"
#include "TimeMilis.h"

glObjectDrawable::glObjectDrawable()
{
}

glObjectDrawable::glObjectDrawable(glObject* aObject, glObjectAnimation* aAnimation, Material* aMaterial){
	this->mObject = aObject;
	this->mAnimation = aAnimation;
	this->mOwnAnimation = aAnimation;
	this->mMaterial = aMaterial;
}

glObjectDrawable::~glObjectDrawable()
{
}

glObjectAnimation* glObjectDrawable::getAnimation(){
	return this->mOwnAnimation;
}

void glObjectDrawable::Draw(){
	this->mMaterial->PassData();
	this->mObject->Draw(this->mAnimation->getModelMatrix());
}

void glObjectDrawable::Draw(glObjectAnimation* aAnimation){
	this->mMaterial->PassData();
	this->mColor->PassData();
	this->mObject->Draw(aAnimation->getModelMatrix() * this->mAnimation->getModelMatrix());
}

void glObjectDrawable::setAnimation(glObjectAnimation* aAnimation){
	this->mAnimation = aAnimation;
}