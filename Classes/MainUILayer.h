#ifndef __MAIN_UI_LAYER_H__
#define __MAIN_UI_LAYER_H__

#include "cocos2d.h"

class MainUILayer : public cocos2d::Layer
{
public:
	virtual bool init();

	CREATE_FUNC(MainUILayer);

	void initTitleUI();
	void initPcSelectUI();
	void initBossSelectUI();
	void doStartGameSelect(Ref* pSender);
};

#endif