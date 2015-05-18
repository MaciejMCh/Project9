#pragma once
#include "glCamera.h"
class StaticCamera :
	public glCamera
{
public:
	StaticCamera();
	~StaticCamera();
	StaticCamera(float eX, float eY, float eZ, float cX, float cY, float cZ, float uX, float uY, float uZ);
};

