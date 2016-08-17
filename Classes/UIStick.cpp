#include "UIStick.h"

USING_NS_CC;

UIStick::UIStick()
{
	init();
}

UIStick::~UIStick()
{

}
void UIStick::init() {
	startPositionX = 100;
	startPositionY = 100;
	currentPositionX = 100;
	currentPositionY = 100;
	key_w = key_a = key_s = key_d = false;
}
void UIStick::Update()
{
}

void UIStick::SetFirstPositionXY(int x, int y)
{
}

void UIStick::SetCurrentPositionXY(int x, int y)
{
}

cocos2d::Vec2 UIStick::GetCurrentPosition()
{
	return cocos2d::Vec2(currentPositionX, currentPositionY);
}

cocos2d::Vec2 UIStick::GetDirection()
{
	return cocos2d::Vec2(currentPositionX - startPositionX, currentPositionY - startPositionY);
}

bool UIStick::GetIsPressing()
{
	return isPressing;
}

void UIStick::KeyProcess()
{
	if (key_w || key_a || key_s || key_d)
	{
		if (key_w) currentPositionY = startPositionY + 50;
		else if (key_s) currentPositionY = startPositionY - 50;
		else currentPositionY = startPositionY;

		if (key_a) currentPositionX = startPositionX - 50;
		else if (key_d) currentPositionX = startPositionX + 50;
		else currentPositionX = startPositionX;
		isMoving = true;
		isPressing = true;
	}
	else {
		currentPositionY = startPositionY;
		currentPositionX = startPositionX;
		isMoving = false;
		isPressing = false;
	}
}

void UIStick::KeyDownProcess(cocos2d::EventKeyboard::KeyCode keyCode)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_W)
	{
		key_w = true;
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_A)
	{
		key_a = true;
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_S)
	{
		key_s = true;
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_D)
	{
		key_d = true;
	}

	KeyProcess();
}
void UIStick::KeyUpProcess(cocos2d::EventKeyboard::KeyCode keyCode)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_W)
	{
		key_w = false;
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_A)
	{
		key_a = false;
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_S)
	{
		key_s = false;
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_D)
	{
		key_d = false;
	}

	KeyProcess();
}
