#pragma once

#include "glm/gtc/type_ptr.hpp"
#include "globject.h"
#include "glObjectAnimation.h"
#include "Material.h"
#include "glObjectDraw.h"
#include "Color.h"

class glObjectDrawable:
public glObjectDraw
{
public:
	glObjectDrawable();
	~glObjectDrawable();
	glObjectDrawable(glObject* aObject, glObjectAnimation* aAnimation, Material* aMaterial);
	virtual void setAnimation(glObjectAnimation* aAnimation);
	virtual glObjectAnimation* getAnimation();
	virtual void Draw();
	virtual void Draw(glObjectAnimation* aAnimation);

private:
	glObjectAnimation* mOwnAnimation;

};

