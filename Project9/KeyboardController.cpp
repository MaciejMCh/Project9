#include "KeyboardController.h"
#include "scene.h"
KeyboardController* KeyboardController::mInstance = 0;

KeyboardController::KeyboardController()
{
}


KeyboardController::~KeyboardController()
{
}

KeyboardController* KeyboardController::getInstance(){
	if (mInstance == 0){
		mInstance = new KeyboardController();
	}
	return mInstance;
}

void KeyboardController::AddListener(KeyListener* aListener){
	this->mList.push_back(aListener);
}

void KeyboardController::KeyPress(char aKey){
	for (int i = 0; i <= this->mList.size()-1;i++){
		this->mList[i]->KeyPressed(aKey);
	}
}