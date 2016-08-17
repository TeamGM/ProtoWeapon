#pragma once
#include "cocos2d.h"
#include "Player.h"

class FieldManager {
public:
	FieldManager();
	~FieldManager();
	void Init();
	Player * getPlayer();
	void Update(int moveDirectionX, int moveDirectionY);
private:
	int startPositionX;
	int startPositionY;
	Player * player;
};