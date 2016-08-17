#pragma once
#include "cocos2d.h"
class UIStick {
public:
	UIStick();
	~UIStick();
	void Update();
	void SetFirstPositionXY(int x, int y);
	void SetCurrentPositionXY(int x, int y);
	
private:
	int FirstPositionX;
	int FirstPositionY;
	int currentPositionX;
	int currentPositionY;
	bool locked;
};