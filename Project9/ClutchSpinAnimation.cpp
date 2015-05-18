#include "ClutchSpinAnimation.h"
#include "TimeMilis.h"

#include "glm/gtc/matrix_transform.hpp"
#include "common.h"

ClutchSpinAnimation::ClutchSpinAnimation()
{
}

ClutchSpinAnimation::ClutchSpinAnimation(float aS, float* aA, glm::vec3 T, float a, glm::vec3 R, glm::vec3 S)
{
	mSpeed = aS;
	mStartSpeed = aS;
	mAxes = aA;
	mModelMatrix = glm::mat4();
	mModelMatrix = glm::translate(mModelMatrix, T);
	mModelMatrix = glm::scale(mModelMatrix, S);
	mModelMatrix = glm::rotate(mModelMatrix, a, R);

	mStop = false;
	mStop = false;
	mStopAngle = 0.0f;
	mConstrNow = TimeMilis::getInstance()->getNow();
	mNow = 0;
	mAngle = 0;
}



ClutchSpinAnimation::~ClutchSpinAnimation()
{
}

void ClutchSpinAnimation::Start(long aT){
	mAnimationTime = aT;
	mStart = true;
	mAnimationEnd = mNow + mAnimationTime;
}

void ClutchSpinAnimation::Stop(long aT){
	mAnimationTime = aT;
	mStop = true;
	mAnimationEnd = mNow + mAnimationTime;
}

glm::mat4 ClutchSpinAnimation::getModelMatrix(){
	long now = TimeMilis::getInstance()->getNow() - mConstrNow;

	if (mStop){
		float argProgress = (mAnimationEnd - now) / (float)mAnimationTime;
		mSpeed = mStartSpeed * (argProgress);
		if (argProgress <= 0){
			mStop = false;
			mSpeed = 0.0f;
		}
	}
	if (mStart){
		float argProgress = (mAnimationEnd - now) / (float)mAnimationTime;
		mSpeed = mStartSpeed * (1 - argProgress);
		if (argProgress <= 0){
			mStart = false;
			mSpeed = mStartSpeed;
		}
	}

	mAngle += (now - mNow) * mSpeed;
	mNow = now;
	return glm::rotate(mModelMatrix, (float)mAngle, glm::vec3(mAxes[0], mAxes[1], mAxes[2]));	
}

void ClutchSpinAnimation::setSpeed(float aS){
	mStartSpeed = aS;
}