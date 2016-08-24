#pragma once
#include "cocos2d.h"
#include "Player.h"
#include "Monster.h"

class FieldManager {
public:
	FieldManager();
	~FieldManager();
	void Init();
	Player * GetPlayer();
	Monster * GetMonster();
	void Update(int moveDirectionX, int moveDirectionY, int fireStatus);
private:
	int startPositionX;
	int startPositionY;
	Player * player;
	Monster * monster;
};