#pragma once
#include "cocos2d.h"
class UIFire {
public:
	UIFire();
	~UIFire();
	void Update();
	void SetFirstPositionXY(int x, int y);
	void SetCurrentPositionXY(int x, int y);

private:
	int PositionX;
	int PositionY;
	float holdingTime;
	bool locked;
};