#pragma once
#include "cocos2d.h"
class UIFire {
public:
	UIFire();
	~UIFire();
	void Init();
	void Update();

	int GetFireStatus();
	
	void SetFirstPositionXY(int x, int y);
	void SetCurrentPositionXY(int x, int y);
	cocos2d::Vec2 GetPositionXY();

	void KeyDownProcess(cocos2d::EventKeyboard::KeyCode keyCode);
	void KeyUpProcess(cocos2d::EventKeyboard::KeyCode keyCode);
private:
	int positionX;
	int positionY;
	int holdFrame;
	bool isHolding;
	bool locked;
	bool firePressed;
	bool fireReleased;
};