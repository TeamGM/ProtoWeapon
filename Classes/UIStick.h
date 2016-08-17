#pragma once
#include "cocos2d.h"
class UIStick : public cocos2d::Object{
public:
	UIStick();
	~UIStick();
	void init();
	void Update();
	void SetFirstPositionXY(int x, int y);
	void SetCurrentPositionXY(int x, int y);
	cocos2d::Vec2 GetCurrentPosition();
	cocos2d::Vec2 GetDirection();
	bool GetIsPressing();
	void KeyProcess();
	void KeyDownProcess(cocos2d::EventKeyboard::KeyCode keyCode);
	void KeyUpProcess(cocos2d::EventKeyboard::KeyCode keyCode);

private:
	int startPositionX;
	int startPositionY;
	int currentPositionX;
	int currentPositionY;
	bool key_w;
	bool key_a;
	bool key_s;
	bool key_d;
	bool isMoving;
	bool locked;
	bool isPressing;
};