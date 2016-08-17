#pragma once
#include "cocos2d.h"
#include "UIManager.h"
class UILayer : public cocos2d::Layer
{
public:
	virtual bool init();
	virtual bool init(UIManager * uiManager);
	
	CREATE_FUNC(UILayer);

	void Draw(UIManager * uiManager);
	
private:
	cocos2d::Sprite * monsterPicture;
	cocos2d::Sprite * playerPicture;
	cocos2d::Sprite * bossHP;
	cocos2d::Sprite * playerHP;

	void DrawBossHP(int bossHPRatio);
	void DrawPlayerHP(int playerHPRatio);
	void DrawStick(UIStick * stick);
	void DrawFire(UIFire * fire);
};
