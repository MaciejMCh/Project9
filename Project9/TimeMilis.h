#pragma once
class TimeMilis
{
public:
	TimeMilis();
	~TimeMilis();
	static TimeMilis* getInstance();
	long getNow();

private:
	static TimeMilis* mInstance;
};

