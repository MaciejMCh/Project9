#pragma once
#include "glObjectAnimation.h"
class SpinAnimation :
	public glObjectAnimation
{
public:
	SpinAnimation();
	SpinAnimation(float aS, float* aA);
	SpinAnimation(float aS, float* aA, float* aO);
	SpinAnimation(float aS, float* aA, glm::mat4 aM);
	SpinAnimation(float aS, float* aA, glm::vec3 T, float a, glm::vec3 R, glm::vec3 S);
	~SpinAnimation();
	glm::mat4 virtual SpinAnimation::getModelMatrix();
	void Stop(long aT);
	void Start(long aT);
	
private:
	float* mAxes;
	float mSpeed;
	float mDSpeed;
	bool mStop;
	bool mFinished;
	bool mStart;
	long mStopTime;
	long mFinishTime;
	long mTime;
	double mStopAngle;
	double mOffAngle;
	double mResetNow;
};

