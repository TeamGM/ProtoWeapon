#pragma once
#include "cocos2d.h"
#include "MonsterState.h"
class Monster {
public:
	Monster();
	~Monster();
	void Update(int playerX, int playerY);
	void Init();
	int GetPositionX();
	int GetPositionY();
	int GetAnimationFrame();
	
	MonsterState GetMonsterState();
private:
	MonsterState monsterState;
	void Move();
	void Attack();
	void NextActivity(int playerX, int playerY);
	

	float HP;
	int stepDistance;
	int positionX;
	int positionY;
	int nextPositionX;
	int nextPositionY;
	int hp;
	int atkPower;
	int range;
	int frameCount;
	int animationFrame;
	cocos2d::Rect * collisionBox;
	cocos2d::CCArray * hitBoxs;
	cocos2d::CCArray * atkBoxs;
};