#pragma once
#include "cocos2d.h"
#include "UIManager.h"
#include "FieldManager.h"
#include "Player.h"
#include "Monster.h"
class BattleManager {
public:
	BattleManager();
	~BattleManager();
	void Update();
	UIManager * GetUIManager();
private:
	void init();
	
	UIManager * uiManager;
	FieldManager * fieldManager;
	Player * player;
	Monster * monster;
};