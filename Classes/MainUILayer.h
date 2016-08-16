#ifndef __MAIN_UI_LAYER_H__
#define __MAIN_UI_LAYER_H__

#include "cocos2d.h"
#include "TypeGameData.h"
#include "GameManager.h"

class MainUILayer : public cocos2d::Layer
{
public:
	virtual bool init();

	CREATE_FUNC(MainUILayer);

	void initTitleUI();
	void initPcSelectUI();
	void initBossSelectUI();

	void setSelectedJob(typeGameData::ENUMPCJOB pcJob);
	void setSelectedBoss();

	typeGameData::ENUMBOSS boss;

	void doStartGameSelect(Ref* pSender);
};

#endif