#pragma once
#include "MouseListener.h"
#include <vector>

class MouseController
{
public:
	MouseController();
	~MouseController();

	static MouseController* getInstance();

	void addListener(MouseListener* mL);
	void LBDown(int aX, int aY);
	void LBUp(int aX, int aY);
	void RBDown(int aX, int aY);
	void RBUp(int aX, int aY);
	void Move(int aX, int aY);

private:
	static MouseController* mInstance;
	std::vector<MouseListener* > mList;

};

