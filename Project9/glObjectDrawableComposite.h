#pragma once
#include "glObjectDrawable.h"
#include <vector>

class glObjectDrawableComposite :
	public glObjectDraw
{
public:
	glObjectDrawableComposite();
	glObjectDrawableComposite(glObjectAnimation* aA);
	~glObjectDrawableComposite();
	virtual void Draw();
	void addDrawable(glObjectDrawable* aD);
	virtual void setAnimation(glObjectAnimation* aAnimation);
	virtual glObjectAnimation* getAnimation();
private:
	std::vector<glObjectDrawable* > mList;

};

