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
	FieldManager * GetFieldManager();
	void KeyDownProcess(cocos2d::EventKeyboard::KeyCode keyCode);
	void KeyUpProcess(cocos2d::EventKeyboard::KeyCode keyCode);
private:
	void init();
	
	UIManager * uiManager;
	FieldManager * fieldManager;
	Player * player;
	Monster * monster;
};