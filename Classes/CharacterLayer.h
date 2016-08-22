#pragma once
#include "cocos2d.h"
#include "Player.h"
class CharacterLayer : public cocos2d::Layer {
public:
	CharacterLayer();
	~CharacterLayer();
	bool init();
	void DrawPlayer(Player * player);
	cocos2d::Sprite * GetPlayer();

	CREATE_FUNC(CharacterLayer);
	void Draw(Player * player);

private:
	cocos2d::Sprite * player;
	cocos2d::Sprite * playerWalkAnimation[5];
	cocos2d::Sprite * playerAttackAnimation[5];
	cocos2d::CCAnimation * playerWalk;
	cocos2d::CCAction * playerAttack;


	cocos2d::Sprite * boss;
}; 
