#pragma once
#include "cocos2d.h"
#include "FieldManager.h"
#include "CharacterLayer.h"


class FieldLayer : public cocos2d::Layer{
public:
	FieldLayer();
	~FieldLayer();
	bool init();
	void Draw(FieldManager * fieldManager);

	CREATE_FUNC(FieldLayer);

private:
	CharacterLayer * characterLayer;
	cocos2d::Sprite * map;
};