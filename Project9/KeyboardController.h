#pragma once

#include "KeyListener.h"
#include <vector>
class KeyboardController
{
public:
	KeyboardController();
	~KeyboardController();
	void AddListener(KeyListener* aListener);
	void KeyPress(char aKey);

	static KeyboardController* getInstance();

private:
	static KeyboardController* mInstance;
	std::vector<KeyListener* > mList;

};

