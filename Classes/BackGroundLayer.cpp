#include "BackGroundLayer.h"

USING_NS_CC;

bool BackGroundLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto sprBG = Sprite::create("img/mainsceneBG.png");
	
	sprBG->setPosition(Vec2(0, 0));
	sprBG->setAnchorPoint(Vec2(0, 0));
	
	this->addChild(sprBG, 0);

	return true;
}