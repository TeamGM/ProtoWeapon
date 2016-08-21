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
	cocos2d::Sprite * boss;
	cocos2d::Sprite * playerWalkAnimation[5];
	cocos2d::Sprite * playerAttackAnimation[5];
	cocos2d::CCAnimation * playerWalk;
	cocos2d::CCAction * playerAttack;
};