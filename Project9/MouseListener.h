#pragma once
class MouseListener
{
public:
	MouseListener();
	~MouseListener();

	virtual void onLBDown(int aX, int aY);
	virtual void onLBUp(int aX, int aY);
	virtual void onRBDown(int aX, int aY);
	virtual void onRBUp(int aX, int aY);
	virtual void onMove(int aX, int aY);
};

