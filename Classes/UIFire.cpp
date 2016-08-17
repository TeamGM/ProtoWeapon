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
}

void UIFire::Update()
{
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
}
void UIFire::KeyUpProcess(cocos2d::EventKeyboard::KeyCode keyCode)
{
}