#pragma once
class TimerListener
{
public:
	TimerListener();
	~TimerListener();

	virtual void onUpdate(long aT);
};

