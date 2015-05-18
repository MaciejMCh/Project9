#pragma once
#include "glObjectAnimation.h"
class ClutchSpinAnimation :
	public glObjectAnimation
{
public:
	ClutchSpinAnimation();
	ClutchSpinAnimation(float aS);
	ClutchSpinAnimation(float aS, float* aA, glm::vec3 T, float a, glm::vec3 R, glm::vec3 S);
	~ClutchSpinAnimation();

	virtual glm::mat4 getModelMatrix();
	void Start(long aT);
	void Stop(long aT);
	void setSpeed(float aS);

private:
	float* mAxes;
	float mSpeed;
	float mStartSpeed;
	bool mStop;
	bool mStart;
	float mStopAngle;
	long mNow;
	double mAngle;
	long mConstrNow;
	long mAnimationEnd;
	long mAnimationTime;
};

