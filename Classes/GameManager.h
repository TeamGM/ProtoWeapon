#pragma once
#include "cocos2d.h"
#include "BattleScene.h"
#include "MainScene.h"
#include "ResultScene.h"

typedef enum {
	WARRIOR,	//0
	WIZARD,		//1
	ARCHER		//2
} SELECTPCJOB;

typedef enum {
	BEHIMOTH,	//0
	LEVIATHAN,		//1
	RADRAGON		//2
} SELECTBOSS;

typedef struct selectData {
	int pcJobNum;
	int bossNum;
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

	//��Ʈ��ũ�� �ӽ�
	/* �Լ��� ������ �ٲ� ��
	void setPcJobNum(SELECTPCJOB pcJobN);
	void setBossNum(SELECTBOSS bossN);
	int getPcJobNum();
	int getBossNum();
	*/
private:
	SELECTDATA soloSelecDatas;
	
	//��Ʈ��ũ�� �ӽ� �÷��̾� ���� ���� ����
	//SELECTDATA netSelectDatas;
};