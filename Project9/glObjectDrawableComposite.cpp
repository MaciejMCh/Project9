#include "glObjectDrawableComposite.h"
#include "StackAnimation.h"

glObjectDrawableComposite::glObjectDrawableComposite()
{
}

glObjectDrawableComposite::glObjectDrawableComposite(glObjectAnimation* aA)
{
	this->mAnimation = aA;
}

glObjectDrawableComposite::~glObjectDrawableComposite()
{
}

void glObjectDrawableComposite::Draw(){
	for (int i = 0; i <= mList.size() - 1; i++){
		mList[i]->Draw();
	}

}
void glObjectDrawableComposite::addDrawable(glObjectDrawable* aD){
	glObjectAnimation* animation = new StackAnimation();
	
	((StackAnimation*)animation)->addAnimation(mAnimation);
	((StackAnimation*)animation)->addAnimation(aD->getAnimation());
	
	aD->setAnimation(animation);
	this->mList.push_back(aD);
}

glObjectAnimation* glObjectDrawableComposite::getAnimation(){
	return this->mAnimation;
}

void glObjectDrawableComposite::setAnimation(glObjectAnimation* aAnimation){
	this->mAnimation = aAnimation;

	glObjectAnimation* animation;

	for (int i = 0; i <= mList.size() - 1; i++){
		animation = new StackAnimation();

		((StackAnimation*)animation)->addAnimation(mAnimation);
		((StackAnimation*)animation)->addAnimation(mList[i]->getAnimation());

		mList[i]->setAnimation(animation);
	}

}

