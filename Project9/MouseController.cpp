#include "MouseController.h"

MouseController* MouseController::mInstance = 0;

MouseController::MouseController()
{
}


MouseController::~MouseController()
{
}

MouseController* MouseController::getInstance(){
	if (mInstance == 0){
		mInstance = new MouseController();
	}
	return mInstance;
}

void MouseController::addListener(MouseListener* aL){
	this->mList.push_back(aL);
}

void MouseController::LBDown(int aX, int aY){
	if (mList.size() > 0){
		for (int i = 0; i <= mList.size() - 1; i++){
			mList[i]->onLBDown(aX, aY);
		}
	}
}

void MouseController::RBUp(int aX, int aY){
	if (mList.size() > 0){
		for (int i = 0; i <= mList.size() - 1; i++){
			mList[i]->onRBUp(aX, aY);
		}
	}
}

void MouseController::RBDown(int aX, int aY){
	if (mList.size() > 0){
		for (int i = 0; i <= mList.size() - 1; i++){
			mList[i]->onRBDown(aX, aY);
		}
	}
}

void MouseController::LBUp(int aX, int aY){
	if (mList.size() > 0){
		for (int i = 0; i <= mList.size() - 1; i++){
			mList[i]->onLBUp(aX, aY);
		}
	}
}

void MouseController::Move(int aX, int aY){
	if (mList.size() > 0){
		for (int i = 0; i <= mList.size() - 1; i++){
			mList[i]->onMove(aX, aY);
		}
	}
}