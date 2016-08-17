#include "UIStick.h"

UIStick::UIStick()
{
}

UIStick::~UIStick()
{

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

cocos2d::Vec2 UIStick::GetDirection()
{
	return cocos2d::Vec2(currentPositionX - firstPositionX, currentPositionY - firstPositionY);
}
