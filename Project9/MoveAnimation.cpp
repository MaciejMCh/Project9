#include "MoveAnimation.h"
#include <windows.h>
#include "TimeMilis.h"

#include "TeleportAnimation.h"
#include "glm/gtc/matrix_transform.hpp"
#include "common.h"

#include <string>
#include "scene.h"

#include <math.h>

MoveAnimation::MoveAnimation()
{
}


MoveAnimation::~MoveAnimation()
{
}

MoveAnimation::MoveAnimation(float* aFrom, float* aTo, long aTime, int aOptions){
	this->mFinished = false;
	this->mStartTime = TimeMilis::getInstance()->getNow();
	this->mEndTime = mStartTime + aTime;
	this->mTime = aTime;
	this->mFrom = aFrom;
	this->mTo = aTo;
	this->mOptions = aOptions;
}

MoveAnimation::MoveAnimation(float* aFrom, float* aTo, long aTime, int aOptions, AnimationListener* aL, std::string aCB){
	this->mFinished = false;
	this->mStartTime = TimeMilis::getInstance()->getNow();
	this->mEndTime = mStartTime + aTime;
	this->mTime = aTime;
	this->mFrom = aFrom;
	this->mTo = aTo;
	this->mOptions = aOptions;
	this->mCallback = aCB;
	this->mListeners.push_back(aL);
}

void MoveAnimation::addListener(AnimationListener* aL){
	mListeners.push_back(aL);
}

void MoveAnimation::setCallback(std::string aC){
	mCallback = aC;
}


glm::mat4 MoveAnimation::getModelMatrix(){
	if (mFinished == false){
		if (TimeMilis::getInstance()->getNow() < mEndTime){
			long argTime = this->mEndTime - TimeMilis::getInstance()->getNow();
			float argProgress = (float)argTime / (float)mTime;

			if (mOptions == 1){
				argProgress = 0.5 - 0.5*cos(PI * argProgress);
			}

			float dX, dY, dZ;
			dX = mTo[0] + argProgress*(mFrom[0] - mTo[0]);
			dY = mTo[1] + argProgress*(mFrom[1] - mTo[1]);
			dZ = mTo[2] + argProgress*(mFrom[2] - mTo[2]);

			std::string ss = std::to_string(dY);
			char* cc = new char[ss.length()];

			for (int i = 0; i <= ss.length() - 1; i++){
				cc[i] = ss[i];
			}




			this->mModelMatrix = glm::translate(glm::mat4(1.f), glm::vec3(dX, dY, dZ));
			return glm::translate(glm::mat4(1.f), glm::vec3(dX, dY, dZ));

		}
		else{
			mFinished = true;
			if (mListeners.size() > 0){
				for (int i = 0; i <= mListeners.size() - 1; i++){
					mListeners[i]->AnimationFinished(mCallback);
				}
			}
			return glm::translate(glm::mat4(), glm::vec3(mTo[0], mTo[1], mTo[2]));
		}
	}
	else{
		return glm::translate(glm::mat4(), glm::vec3(mTo[0], mTo[1], mTo[2]));
	}
	
}