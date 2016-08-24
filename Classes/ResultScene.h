#ifndef __RESULT_SCENE_H__
#define __RESULT_SCENE_H__

#include "cocos2d.h"
#include "GameManager.h"
#include "ResultBGLayer.h"
#include "ResultUILayer.h"

class ResultScene : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(ResultScene);
};

#endif // __RESULT_SCNEN_H__