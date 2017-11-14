#ifndef __MAIN_UI_LAYER_H__
#define __MAIN_UI_LAYER_H__

#include "cocos2d.h"
#include "ui/UIPageView.h"
#include "TypeGameData.h"
#include "GameManager.h"
#include "MainScene.h"
#include "simpleAudioEngine.h"

USING_NS_CC;

class MainUILayer : public cocos2d::Layer
{
public:
	virtual bool init();

	CREATE_FUNC(MainUILayer);

	void initMainUI();
	void initTitleUI(ui::PageView* pageview);
	void initModeSelctUI(); //싱글,멀티 플레이 선택 UI
	void initHostResgistUI(); //호스트 등록 UI
	void initRoomUI(); //룸UI
	void initRoomListUI(); //게스트용 룸리스트 UI
	void initPcSelectUI(/*ui::PageView* pageview*/);
	void initBossSelectUI(/*ui::PageView* pageview*/);

	void setSelectedJob(typeGameData::ENUMPCJOB pcJob);
	void setSelectedBoss(typeGameData::ENUMBOSS boss);

	void startSoloGame(Ref* pSender);

	typeGameData::SELECTEDDATA mainSceneDataSet;
};

#endif