#pragma once
#include "cocos2d.h"
#include "BattleScene.h"
#include "MainScene.h"
#include "ResultScene.h"
#include "TypeGameData.h"
#include "simpleAudioEngine.h"


class GameManager :public cocos2d::Object
{
public:
	static GameManager* getInstance();

	virtual ~GameManager();
	bool init();

	void setSoloPcJobNum(typeGameData::ENUMPCJOB pcJobN);
	void setSoloBossNum(typeGameData::ENUMBOSS bossN);
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
	typeGameData::SELECTEDDATA soloSelecDatas;
	
	//��Ʈ��ũ�� �ӽ� �÷��̾� ���� ���� ����
	//SELECTDATA netSelectDatas;
};