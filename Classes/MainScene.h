#ifndef __MAINSCENE_SCENE_H__
#define __MAINSCENE_SCENE_H__

#include "cocos2d.h"
#include "MainUILayer.h"
#include "BackGroundLayer.h"

class MainScene : public cocos2d::Scene
{
private:
	int statMainScene = 0;

public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	void loadSprites();
		
	CREATE_FUNC(MainScene);
};

#endif // __MAINSCENE_SCENE_H__
