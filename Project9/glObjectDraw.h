#pragma once

#include "glm/gtc/type_ptr.hpp"
#include "globject.h"
#include "glObjectAnimation.h"
#include "Material.h"
#include "Color.h"

class glObjectDraw
{
public:
	glObjectDraw();
	~glObjectDraw();
	virtual void Draw()=0;
	virtual glObjectAnimation* getAnimation() = 0;
	virtual void setAnimation(glObjectAnimation* aA)=0;

protected:
	glm::mat4 mModelMatrix;
	glObject* mObject;
	glObjectAnimation* mAnimation;
	glObjectAnimation* mOwnAnimation;
	Material* mMaterial;
	Color* mColor;

};

