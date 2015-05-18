#include "TimeMilis.h"
#include "windows.h"

TimeMilis* TimeMilis::mInstance = 0;

TimeMilis::TimeMilis()
{
}


TimeMilis::~TimeMilis()
{
}

TimeMilis* TimeMilis::getInstance(){
	if (mInstance == 0){
		mInstance = new TimeMilis();
	}
	return mInstance;
}

long TimeMilis::getNow(){
	SYSTEMTIME time;
	GetSystemTime(&time);
	WORD millis = (time.wHour * 60 * 60 * 1000) + (time.wMinute * 60000) + (time.wSecond * 1000) + time.wMilliseconds;
	return millis;
}