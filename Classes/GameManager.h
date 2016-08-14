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

	//��Ʈ��ũ�� �ӽ�
	/* �Լ��� ������ �ٲ� ��
	void setPcJobNum(SELECTPCJOB pcJobN);
	void setBossNum(SELECTBOSS bossN);
	int getPcJobNum();
	int getBossNum();
	*/
private:
	//�ܺο��� �������ٺҰ�
	//@(get/set)Solo(PcJob/Boss)Num ���� ���ٰ���
	SELECTDATA soloSelecDatas;
	
	//��Ʈ��ũ�� �ӽ� �÷��̾� ���� ���� ����
	//SELECTDATA netSelectDatas;
};