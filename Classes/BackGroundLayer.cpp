#include "BackGroundLayer.h"
#include <string.h>
#include <stdlib.h>

USING_NS_CC;

bool BackGroundLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	//auto sprBG = Sprite::createWithSpriteFrameName("mainsceneBG");
	auto sprBG = Sprite::create("img/mainsceneBG.png");
	
	sprBG->setPosition(Vec2(0, 0));
	sprBG->setAnchorPoint(Vec2(0, 0));
	
	this->addChild(sprBG, 0);

	return true;
}