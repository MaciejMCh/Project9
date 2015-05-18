#pragma once
#include "Application.h"
#include "KeyListener.h"
#include "AnimationListener.h"
#include <string>
#include "MouseListener.h"

class GearChangeApplication :
	public KeyListener,
	public AnimationListener
{
public:
	GearChangeApplication();
	GearChangeApplication(std::vector<glObjectDraw* > aM);
	~GearChangeApplication();
	virtual void KeyPressed(char aKey);
	virtual void AnimationFinished(std::string aC);


private:
	std::vector<glObjectDraw* > mList;
	int mGear;
	bool mInput;
	bool mClutch;
	int mManChange;
	float mMan1;
	float mMan2;
	float mMan0;
	float mManX;
	float mManY;
	float mAngle;
};

