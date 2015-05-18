#pragma once
#include "glObjectAnimation.h"
#include "AnimationListener.h"
#include <vector>
#include <string>

class MoveAnimation :
	public glObjectAnimation
{
public:
	const static int SMOOTH = 1;
	const static int LINEAR = 0;
	MoveAnimation();
	~MoveAnimation();
	MoveAnimation(float* aFrom, float* aTo, long aTime, int aOptions);
	MoveAnimation(float* aFrom, float* aTo, long aTime, int aOptions, AnimationListener* aL, std::string aCB);
	virtual glm::mat4 getModelMatrix();
	void addListener(AnimationListener* aL);
	void setCallback(std::string aC);


private:
	bool mFinished;
	int mOptions;
	float* mFrom;
	float* mTo;
	long mStartTime, mEndTime, mTime;
	std::string mCallback;
	
	std::vector< AnimationListener* > mListeners;

};

