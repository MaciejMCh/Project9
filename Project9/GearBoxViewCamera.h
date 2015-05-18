#pragma once
#include "glCamera.h"
#include "KeyListener.h"
#include "MouseListener.h"


class GearBoxViewCamera :
	public glCamera,
	public KeyListener,
	public MouseListener
{
public:
	GearBoxViewCamera();
	~GearBoxViewCamera();

	virtual glm::mat4 getViewMatrix();
	virtual void KeyPressed(char aKey);
	virtual void onLBDown(int aX, int aY);
	virtual void onLBUp(int aX, int aY);
	virtual void onRBDown(int aX, int aY);
	virtual void onRBUp(int aX, int aY);
	virtual void onMove(int aX, int aY);

protected:
	glm::vec3 mEye;
	glm::vec3 mCenter;
	glm::vec3 mUp;

	float mX;
	float mY;
	float mMY;
	float mMX;
	float mZoom;
	float mHAngle;
	float mVAngle;

	float mDragStartHA;
	float mDragStartVA;

	float mMoveStartX;
	float mMoveStartY;

	int mOffX;
	int mOffY;

	int mDragStartX, mDragStartY;
	bool mDrag;
	bool mMove;
};

