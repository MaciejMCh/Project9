#pragma once
#include "glObjectAnimation.h"
#include "AnimationListener.h"
#include <string>
#include <vector>

class RotationAnimation :
	public glObjectAnimation
{
public:
	RotationAnimation();
	RotationAnimation(float aFrom, float aTo, glm::vec3 mAxes , long aTime, int aOptions);
	RotationAnimation(float aFrom, float aTo, glm::vec3 mAxes, long aTime, int aOptions, AnimationListener* aL, std::string aCB);
	~RotationAnimation();
	virtual glm::mat4 getModelMatrix();
	void addListener(AnimationListener* aL);
	void setCallback(std::string aC);

private:
	int mOptions;
	bool mFinished;
	float mFrom;
	float mTo;
	glm::vec3 mAxes;
	long mStartTime, mEndTime, mTime;
	std::string mCallback;
	std::vector< AnimationListener* > mListeners;
};

