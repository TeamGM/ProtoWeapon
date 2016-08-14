#pragma once
#include "cocos2d.h"
#include "BattleScene.h"
#include "MainScene.h"
#include "ResultScene.h"

typedef enum {
	WARRIOR,	//0
	WIZARD,		//1
	ARCHER,		//2
	UNkNOWNJOB	//3
} SELECTPCJOB;

typedef enum {
	BEHIMOTH,	//0
	LEVIATHAN,	//1
	RADRAGON,	//2
	UNKNOWNBOSS	//3
} SELECTBOSS;

typedef struct selectData {
	int pcJobNum = UNkNOWNJOB;
	int bossNum= UNKNOWNBOSS;
} SELECTDATA;

class GameManager :public cocos2d::Object
{
public:
	static GameManager* getInstance();

	virtual ~GameManager();
	bool init();

	void setSoloPcJobNum(SELECTPCJOB pcJobN);
	void setSoloBossNum(SELECTBOSS bossN);
	int getSoloPcJobNum();
	int getSoloBossNum();

	void doSoloStartBattleScene(Ref* pSender);
	void doSoloBattleEnd(Ref* pSender);
	void doSoloResultEnd(Ref* pSender);

	//네트워크용 임시
	/* 함수명 적절히 바꿀 것
	void setPcJobNum(SELECTPCJOB pcJobN);
	void setBossNum(SELECTBOSS bossN);
	int getPcJobNum();
	int getBossNum();
	*/
private:
	//외부에서 임의접근불가
	//@(get/set)Solo(PcJob/Boss)Num 으로 접근가능
	SELECTDATA soloSelecDatas;
	
	//네트워크용 임시 플레이어 수에 따라 조정
	//SELECTDATA netSelectDatas;
};