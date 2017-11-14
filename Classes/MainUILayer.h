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
	void initModeSelctUI(); //�̱�,��Ƽ �÷��� ���� UI
	void initHostResgistUI(); //ȣ��Ʈ ��� UI
	void initRoomUI(); //��UI
	void initRoomListUI(); //�Խ�Ʈ�� �븮��Ʈ UI
	void initPcSelectUI(/*ui::PageView* pageview*/);
	void initBossSelectUI(/*ui::PageView* pageview*/);

	void setSelectedJob(typeGameData::ENUMPCJOB pcJob);
	void setSelectedBoss(typeGameData::ENUMBOSS boss);

	void startSoloGame(Ref* pSender);

	typeGameData::SELECTEDDATA mainSceneDataSet;
};

#endif