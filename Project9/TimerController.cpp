#include "TimerController.h"

TimerController* TimerController::mInstance = 0;

TimerController::TimerController()
{
}


TimerController::~TimerController()
{
}

TimerController* TimerController::getInstance(){
	if (mInstance == 0){
		mInstance = new TimerController();
	}
	return mInstance;
}

void TimerController::Update(long aT){
	if (mList.size() > 0){
		for (int i = 0; i <= mList.size() - 1; i++){
			mList[i]->onUpdate(aT);
		}
	}

}