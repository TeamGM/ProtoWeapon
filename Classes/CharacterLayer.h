#pragma once
#include "cocos2d.h"
#include "Player.h"
#include "PlayerState.h"
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
	//void CreateAnimations();
	cocos2d::RepeatForever * CreateWalkAnimation();
	cocos2d::CCAnimate * CreateAttackAnimation();

	cocos2d::CCAnimate * CreateHoldAnimation();

	PlayerState playerState;

	cocos2d::Sprite * player;
	cocos2d::CCAnimation * playerWalk;
	cocos2d::CCAction * playerAttack;

	cocos2d::CCArray * playerWalkFrames;
	cocos2d::CCArray * playerAttackFrames;

	cocos2d::RepeatForever * playerWalkAnimation;
	cocos2d::CCAnimate * playerAttackAnimation;

	cocos2d::Sprite * boss;
}; 
