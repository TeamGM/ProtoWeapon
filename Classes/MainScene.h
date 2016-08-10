#ifndef __MAINSCENE_SCENE_H__
#define __MAINSCENE_SCENE_H__

#include "cocos2d.h"

class MainScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	
	// implement the "static create()" method manually
	CREATE_FUNC(MainScene);
};

#endif // __MAINSCENE_SCENE_H__
