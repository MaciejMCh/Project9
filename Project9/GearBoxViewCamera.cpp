#include "GearBoxViewCamera.h"

#include "common.h"
#include "KeyboardController.h"
#include "MouseController.h"
#include "glProgram.h"
#include "TimerController.h"
#include <math.h>

GearBoxViewCamera::GearBoxViewCamera()
{
	SetCursorPos(300, 300);
	mHAngle = 0.0f;
	mVAngle = 0.0f;
	mZoom = 10.0f;
	mX = 4.0f;
	mY = 1.0f;
	mDrag = false;
	mMove = false;
	mDragStartHA = 0.0f;
	mDragStartVA = 0.0f;
	mMoveStartX = 4.0f;
	mMoveStartY = 1.0f;
	mDragStartX = 300;
	mDragStartY = 300;
}


GearBoxViewCamera::~GearBoxViewCamera()
{
}



void GearBoxViewCamera::onRBDown(int aX, int aY){
	SetCursorPos(300, 300);
	mDragStartX = 300;
	mDragStartY = 300;

	mOffX = aX;
	mOffY = aY;

	mMove = true;
}

void GearBoxViewCamera::onRBUp(int aX, int aY){
	mMove = false;
	mMoveStartX = mX;
	mMoveStartY = mY;
}

void GearBoxViewCamera::onLBDown(int aX, int aY){
	SetCursorPos(300, 300);
	mDragStartX = 300;
	mDragStartY = 300;

	mOffX = aX;
	mOffY = aY;

	mDrag = true;	
}

void GearBoxViewCamera::onLBUp(int aX, int aY){
	mDrag = false;
	mDragStartHA = mHAngle;
	mDragStartVA = mVAngle;
}

void GearBoxViewCamera::onMove(int aX, int aY){
	mMX = aX;
	mMY = aY;
	float dX = aX - 300;
	float dY = aY - 300;

	if (mMove){
		int sgn;
		if (cos(mHAngle) > 0){
			sgn = -1;
		}else{
			sgn = 1;
		}

		mX = mMoveStartX + dX / 100.0f * sgn;
		mY = mMoveStartY + dY / 100.0f;

		if ((abs(dX) + abs(dY))>100){
			mMoveStartX += dX / 100.0f * sgn;
			mMoveStartY += dY / 100.0f;
			SetCursorPos(300, 300);
		}
	}

	if (mDrag){
		mVAngle = mDragStartVA + (dY)/100.0f;
		mHAngle = mDragStartHA + (dX)/100.0f;
		if (mVAngle > PI / 2.1) mVAngle = PI / 2.1;
		if (mVAngle < -PI / 2.1) mVAngle = -PI / 2.1;

		if ((abs(dX) + abs(dY))>100){
			mDragStartHA += dX / 100.0f;
			mDragStartVA += dY / 100.0f;
			SetCursorPos(300, 300);
		}
	}		
}


glm::mat4 GearBoxViewCamera::getViewMatrix(){
	glUniform3fv(glProgram::getInstance()->getHandle("CameraPos"), 1, glm::value_ptr(glm::vec3(
		mX - sin(mHAngle)*cos(mVAngle) * mZoom, 
		mY + sin(mVAngle) * mZoom, 
		-15.0f + cos(mHAngle)*cos(mVAngle) * mZoom)));
	this->mViewMatrix = glm::lookAt(
		glm::vec3(mX - sin(mHAngle)*cos(mVAngle) * mZoom, 
		mY + sin(mVAngle) * mZoom, 
		-15.0f + cos(mHAngle)*cos(mVAngle) * mZoom),
		glm::vec3(mX, mY, -15.0f),		
		glm::vec3(0.0f, 0.1f, 0.0f)
		);

	return this->mViewMatrix;

}


void GearBoxViewCamera::KeyPressed(char aKey){
	switch (aKey)
	{
	case 65:{mX -= 1.0; break; }
	case 68:{mX += 1.0; break; }
	case 37: {mHAngle -= 0.05f; break; }
	case 38: {if(mVAngle+0.05f<=PI/2)mVAngle += 0.05f; break; }
	case 39: {mHAngle += 0.05f; break; }
	case 40: {if(mVAngle-0.05>=-PI/2)mVAngle -= 0.05f; break; }
	case 87: {mZoom+=1.0f; break; } //W
	case 83: {mZoom-=1.0f; break; } //S		
	default:
		break;
	}
}