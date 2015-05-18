#include "SpinAnimation.h"

#include "glm/gtc/matrix_transform.hpp"
#include "common.h"
#include "TimeMilis.h"


SpinAnimation::SpinAnimation()
{
}

SpinAnimation::SpinAnimation(float aS, float* aA){
	this->mAxes = aA;
	this->mSpeed = aS;
	this->mModelMatrix = glm::mat4();
}

SpinAnimation::SpinAnimation(float aS, float* aA, float* aO){
	this->mSpeed = aS;
	this->mAxes = aA;
	//mModelMatrix = glm::mat4();
	//mModelMatrix = glm::translate(mModelMatrix, glm::vec3(aO[0], aO[1], aO[2]));
	//mModelMatrix = glm::rotate(mModelMatrix, aO[3], glm::vec3(aO[4], aO[5], aO[6]));
	//mModelMatrix = glm::scale(mModelMatrix, glm::vec3(aO[7], aO[8], aO[9]));
	mModelMatrix = glm::mat4();
}

SpinAnimation::SpinAnimation(float aS, float* aA, glm::mat4 aM){
	this->mSpeed = aS;
	this->mAxes = aA;
	this->mModelMatrix = aM;
}

SpinAnimation::SpinAnimation(float aS, float* aA, glm::vec3 T, float a, glm::vec3 R, glm::vec3 S){
	this->mSpeed = aS;
	this->mAxes = aA;
	mModelMatrix = glm::mat4();
	mModelMatrix = glm::translate(mModelMatrix, T);
	mModelMatrix = glm::scale(mModelMatrix, S);
	mModelMatrix = glm::rotate(mModelMatrix, a, R);
	mStop = false;
	mFinished = false;
	mOffAngle = 0;
	mResetNow = TimeMilis::getInstance()->getNow()*mSpeed;
}

SpinAnimation::~SpinAnimation()
{
}

glm::mat4 SpinAnimation::getModelMatrix(){
	long now = TimeMilis::getInstance()->getNow();
	float argProgress;
	long argTime;

	if (mStart){
		argTime = this->mFinishTime - now;
		argProgress = (float)argTime / (float)mTime;

		if (argProgress <= 0.5f){
			mStart = false;
			mOffAngle = mStopAngle + (mDSpeed * (now - mStopTime));
			mResetNow = TimeMilis::getInstance()->getNow()*mSpeed;
		}

		mDSpeed = mSpeed*(1-argProgress);
		double angle = mStopAngle + (mDSpeed * (now - mStopTime));
		return glm::rotate(mModelMatrix, (float)(angle + mOffAngle), glm::vec3(mAxes[0], mAxes[1], mAxes[2]));
	}


	if (mFinished){
		return glm::rotate(mModelMatrix, (float)(mStopAngle + mOffAngle), glm::vec3(mAxes[0], mAxes[1], mAxes[2]));
	}
	if (mStop){
		argTime = this->mFinishTime - now;
		argProgress = (float)argTime / (float)mTime;
		mDSpeed = mSpeed*(argProgress);
		if (argProgress>0.5f){
			double angle = mStopAngle + (mDSpeed * (now - mStopTime));
			return glm::rotate(mModelMatrix, (float)(angle + mOffAngle), glm::vec3(mAxes[0], mAxes[1], mAxes[2]));
		}
		else{
			float argProgress = (float)argTime / (float)mTime;
			mDSpeed = mSpeed*(argProgress);
			mStopAngle = mStopAngle + (mDSpeed * (now - mStopTime));
			mFinished = true;
			return glm::rotate(mModelMatrix, (float)(mStopAngle + mOffAngle), glm::vec3(mAxes[0], mAxes[1], mAxes[2]));
		}
	}

	double angle = now * mSpeed;
	return glm::rotate(mModelMatrix, (float)(angle + mOffAngle-mResetNow), glm::vec3(mAxes[0], mAxes[1], mAxes[2]));
}

void SpinAnimation::Stop(long aT){
	mStopAngle = TimeMilis::getInstance()->getNow() * mSpeed;
	mStopTime = TimeMilis::getInstance()->getNow();
	mFinishTime = mStopTime + aT;
	mStop = true;
	mDSpeed = mSpeed;
	mTime = aT;
}

void SpinAnimation::Start(long aT){
	mFinished = false;
	mStop = false;
	mStart = true;
	mTime = aT;
	mStopTime = TimeMilis::getInstance()->getNow();
	mFinishTime = mStopTime + aT;
}