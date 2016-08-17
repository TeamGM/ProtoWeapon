#pragma once
#include "cocos2d.h"
#include "FieldManager.h"
class FieldLayer : public cocos2d::Layer{
public:
	FieldLayer();
	~FieldLayer();
	bool init();
	void Draw(FieldManager * fieldManager);
	void DrawPlayer(Player * player);

	CREATE_FUNC(FieldLayer);

private:
	cocos2d::Sprite * map;
	cocos2d::Sprite * player;
};