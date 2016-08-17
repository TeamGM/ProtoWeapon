#pragma once
#include "cocos2d.h"
class UIStick {
public:
	UIStick();
	~UIStick();
	void Update();
	void SetFirstPositionXY(int x, int y);
	void SetCurrentPositionXY(int x, int y);
	cocos2d::Vec2 GetDirection();

private:
	int firstPositionX;
	int firstPositionY;
	int currentPositionX;
	int currentPositionY;
	bool locked;
};