#ifndef __RESULT_SCENE_H__
#define __RESULT_SCENE_H__

#include "cocos2d.h"
#include "GameManager.h"

class ResultScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(ResultScene);

	void resultEnd(Ref* pSender);
};

#endif // __RESULT_SCNEN_H__