#include "UIFire.h"

UIFire::UIFire()
{
	Init();
}

UIFire::~UIFire()
{
}

void UIFire::Init() {
	positionX = 260;
	positionY = 100;
	isHolding = false;
	holdFrame = 0;
	firePressed = false;
	fireReleased = false;
}

void UIFire::Update()
{
	if (isHolding) {
		holdFrame++;
		if (holdFrame > 60) {
			firePressed = false;
			fireReleased = true;
			isHolding = false;
		}
	}
}

int UIFire::GetFireStatus() {
	if (firePressed)return 1;
	else if (fireReleased)return 2;
	else return 0;
}

int UIFire::GetFireHoldFrame()
{
	return holdFrame;
}

bool UIFire::GetIsHolding()
{
	return isHolding;
}

void UIFire::SetFirstPositionXY(int x, int y)
{
}

void UIFire::SetCurrentPositionXY(int x, int y)
{
}

cocos2d::Vec2 UIFire::GetPositionXY()
{
	return cocos2d::Vec2(positionX,positionY);
}

void UIFire::KeyDownProcess(cocos2d::EventKeyboard::KeyCode keyCode)
{
	if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_SPACE) {
		firePressed = true;
		fireReleased = false;
		isHolding = true;
		holdFrame = 0;
	}
}
void UIFire::KeyUpProcess(cocos2d::EventKeyboard::KeyCode keyCode)
{
	if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_SPACE) {
		firePressed = false;
		fireReleased = true;
		isHolding = false;
		holdFrame = 0;
	}
}