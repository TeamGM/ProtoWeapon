#pragma once
#ifndef __BACKGROUND_LAYER_H__
#define __BACKGROUND_LAYER_H__

#include "cocos2d.h"

class BackGroundLayer : public cocos2d::LayerColor
{
public:
	virtual bool init();

	//static cocos2d::Scene* createScene();

	CREATE_FUNC(BackGroundLayer);
};

#endif