#pragma once

#include "TimerListener.h"
#include <vector>
#include <string>

class TimerController
{
public:
	TimerController();
	~TimerController();

	static TimerController* getInstance();

	void addListener(TimerListener* aL);
	void Update(long aT);

private:
	static TimerController* mInstance;

	std::vector<TimerListener* > mList;

};

