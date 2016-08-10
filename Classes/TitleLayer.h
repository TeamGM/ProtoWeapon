#ifndef __TITLE_LAYER_H__
#define __TITLE_LAYER_H__

#include "cocos2d.h"

class TitleLayer : public cocos2d::Layer
{
public:
	virtual bool init();

	//static cocos2d::Scene* createScene();

	CREATE_FUNC(TitleLayer);

	void doStartBattleScene(Ref* pSender);
};

#endif