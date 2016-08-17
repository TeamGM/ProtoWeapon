#ifndef __BATTLE_SCENE_H__
#define __BATTLE_SCENE_H__

#include "cocos2d.h"
#include "GameManager.h"
#include "BattleManager.h"
#include "UILayer.h"

USING_NS_CC;

class BattleScene : public cocos2d::LayerColor
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	virtual void update(float dt);
	
	CREATE_FUNC(BattleScene);

	void batlleEnd(Ref* pSender);
	UILayer * uiLayer;
private:
	BattleManager * battleManager;
	void InitKeyboardListener();
	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
	void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);
};

#endif // __BATTLE_SCNEN_H__