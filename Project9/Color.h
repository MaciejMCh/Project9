#pragma once
class Color
{
public:
	Color();
	Color(float* aA, float* aD, float* aS);
	~Color();
	void PassData();

private:
	float* mDiffuse;
	float* mSpecular;
	float* mAmbient;

};

