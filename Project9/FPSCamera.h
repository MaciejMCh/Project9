#pragma once
#include "glCamera.h"
#include "KeyListener.h"
class FPSCamera :
	public glCamera,
	public KeyListener
{
public:
	FPSCamera();
	~FPSCamera();

	virtual glm::mat4 getViewMatrix();
	virtual void KeyPressed(char aKey);

protected:
	float* mPosition;
	float mHAngle;
	float mVAngle;


	glm::vec3 mEye;
	glm::vec3 mCenter;
	glm::vec3 mUp;

	float mX;
	float mZoom;

};

