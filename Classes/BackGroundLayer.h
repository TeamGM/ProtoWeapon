#pragma once
#ifndef __BACKGROUND_LAYER_H__
#define __BACKGROUND_LAYER_H__

#include "cocos2d.h"

class BackGroundLayer : public cocos2d::Layer
{
public:
	virtual bool init();
	
	CREATE_FUNC(BackGroundLayer);
};

#endif