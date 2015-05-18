#include "RotationAnimation.h"
#include "TimeMilis.h"
#include <math.h>
#include "common.h"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtc/matrix_transform.hpp"

RotationAnimation::RotationAnimation()
{
}


RotationAnimation::RotationAnimation(float aFrom, float aTo,glm::vec3 aAxes, long aTime, int aOptions){
	this->mFinished = false;
	this->mStartTime = TimeMilis::getInstance()->getNow();
	this->mEndTime = mStartTime + aTime;
	this->mTime = aTime;
	this->mFrom = aFrom;
	this->mTo = aTo;
	this->mOptions = aOptions;
	this->mAxes = aAxes;
}

RotationAnimation::RotationAnimation(float aFrom, float aTo, glm::vec3 aAxes, long aTime, int aOptions, AnimationListener* aL, std::string aCB){
	this->mFinished = false;
	this->mStartTime = TimeMilis::getInstance()->getNow();
	this->mEndTime = mStartTime + aTime;
	this->mTime = aTime;
	this->mFrom = aFrom;
	this->mTo = aTo;
	this->mOptions = aOptions;
	this->mAxes = aAxes;
	this->mCallback = aCB;
	this->mListeners.push_back(aL);
}

RotationAnimation::~RotationAnimation()
{
}

void RotationAnimation::addListener(AnimationListener* aL){
	this->mListeners.push_back(aL);
}

void RotationAnimation::setCallback(std::string aS){
	this->mCallback = aS;
}

glm::mat4 RotationAnimation::getModelMatrix(){
	/*if (mFinished == false){
		if (TimeMilis::getInstance()->getNow() < mEndTime){
			long argTime = this->mEndTime - TimeMilis::getInstance()->getNow();
			float argProgress = (float)argTime / (float)mTime;

			if (mOptions == 1){
				argProgress = 0.5 - 0.5*cos(PI * argProgress);
			}

			float dA = mTo + argProgress*(mFrom - mTo);

			return glm::rotate(glm::mat4(), dA, glm::vec3(0.0f, 1.0f, 0.0f));
			//return mModelMatrix;
		}
	}*/

	if (mFinished == false){
		if (TimeMilis::getInstance()->getNow() < mEndTime){
			long argTime = this->mEndTime - TimeMilis::getInstance()->getNow();
			float argProgress = (float)argTime / (float)mTime;

			if (mOptions == 1){
				argProgress = 0.5 - 0.5*cos(PI * argProgress);
			}

			float dA = mTo + argProgress*(mFrom - mTo);

			this->mModelMatrix = glm::rotate(glm::mat4(), dA, mAxes);
			return mModelMatrix;

		}
		else{
			mFinished = true;
			if (mListeners.size() > 0){
				for (int i = 0; i <= mListeners.size() - 1; i++){
					mListeners[i]->AnimationFinished(mCallback);
				}
			}
			return glm::rotate(glm::mat4(), mTo, mAxes);
		}
	}
	else{
		return glm::rotate(glm::mat4(), mTo, mAxes);
	}
	return glm::mat4();
}