#pragma once
#include "cocos2d.h"
#include "Player.h"
#include "Monster.h"
#include "PlayerState.h"
#include "MonsterState.h"
class CharacterLayer : public cocos2d::Layer {
public:
	CharacterLayer();
	~CharacterLayer();
	bool init();
	void DrawPlayer(Player * player);
	void DrawMonster(Monster * monster);
	cocos2d::Sprite * GetPlayer();
	
	CREATE_FUNC(CharacterLayer);
	void Draw(Player * player, Monster * monster);

private:
	//void CreateAnimations();
	cocos2d::RepeatForever * CreateWalkAnimation();
	cocos2d::CCAnimate * CreateAttackAnimation();

	cocos2d::CCAnimate * CreateHoldAnimation();
	cocos2d::CCAnimate * CreateMonsterAtkAnimation();
	PlayerState playerState;
	MonsterState monsterState;

	cocos2d::Sprite * player;
	cocos2d::CCAnimation * playerWalk;
	cocos2d::CCAction * playerAttack;

	cocos2d::CCArray * playerWalkFrames;
	cocos2d::CCArray * playerAttackFrames;

	cocos2d::RepeatForever * playerWalkAnimation;
	cocos2d::CCAnimate * playerAttackAnimation;

	cocos2d::Sprite * monster;
	cocos2d::Sprite * monsterLeftMove;
	cocos2d::Sprite * monsterRightMove;
	cocos2d::Sprite ** monsterLeftAttack;
	cocos2d::Sprite ** monsterRightAttack;

}; 
