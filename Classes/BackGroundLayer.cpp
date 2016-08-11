#include "BackGroundLayer.h"

USING_NS_CC;

bool BackGroundLayer::init()
{
	if (!LayerColor::initWithColor(Color4B(120,0,0,120)))
	{
		return false;
	}

	return true;
}