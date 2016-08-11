#ifndef __MAINSCENE_SCENE_H__
#define __MAINSCENE_SCENE_H__

#include "cocos2d.h"
#include "MainUILayer.h"
#include "BackGroundLayer.h"


typedef enum {
	warrior,	//0
	wizard,		//1
	archer		//2
} PCJOB;

typedef enum {
	titleOn,		//0
	pcSelectOn,		//1
	bossSelectOn	//2
} STATMAINSCENE;

typedef struct selectData {
	int pcJobNum;
	int bossNum;
} SELECTDATA;

class MainScene : public cocos2d::Scene
{
private:
	int statMainScene = 0;

public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	void loopMainScene(float dt);

	//MainScene 상태변환함수
	void doTitleOn();
	void doPcSelectOn();
	void doBossSelectOn();
	
	CREATE_FUNC(MainScene);
};

#endif // __MAINSCENE_SCENE_H__
