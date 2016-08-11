#ifndef __MAINSCENE_SCENE_H__
#define __MAINSCENE_SCENE_H__

#include "cocos2d.h"

class MainScene : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	void loopMainScene(float dt);
	
	CREATE_FUNC(MainScene);
};

#endif // __MAINSCENE_SCENE_H__
