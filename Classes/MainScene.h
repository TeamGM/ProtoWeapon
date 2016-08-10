#ifndef __MAINSCENE_SCENE_H__
#define __MAINSCENE_SCENE_H__

#include "cocos2d.h"
#include "BattleScene.h"
#include "ResultScene.h"

class MainScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	
	// implement the "static create()" method manually
	CREATE_FUNC(MainScene);

	void doStartBattleScene(Ref* pSender);
	//void doPushSceneTran(Ref* pSender);
	//void doReplaceScene(Ref* pSender);
	//void doReplaceSceneTran(Ref* pSender);
};

#endif // __MAINSCENE_SCENE_H__
