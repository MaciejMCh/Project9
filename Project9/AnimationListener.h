#pragma once
#include <string>
class AnimationListener
{
public:
	AnimationListener();
	~AnimationListener();

	virtual void AnimationFinished(std::string aCallbackMsg) = 0;
};

