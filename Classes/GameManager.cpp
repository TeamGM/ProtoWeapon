#include "GameManager.h"

USING_NS_CC;

static GameManager *theGameManager = NULL;

GameManager* GameManager::getInstance()
{
	if (!theGameManager)
	{
		theGameManager = new GameManager();
		theGameManager->init();
	}

	return theGameManager;
}

//*********************
//**** Solo플레이 함수 목록
//*********************
void GameManager::setSoloPcJobNum(SELECTPCJOB pcJobN)
{
	soloSelecDatas.pcJobNum = pcJobN;
}
void GameManager::setSoloBossNum(SELECTBOSS bossN)
{
	soloSelecDatas.bossNum = bossN;
}
int GameManager::getSoloPcJobNum()
{
	return soloSelecDatas.pcJobNum;
}
int GameManager::getSoloBossNum()
{
	return soloSelecDatas.bossNum;
}
void GameManager::doSoloStartBattleScene(Ref* pSender)
{
	auto pScene = BattleScene::createScene();
	Director::getInstance()->replaceScene(pScene);
}
//*** Solo플레이 함수 목록 끝


GameManager::~GameManager()
{

}

bool GameManager::init()
{
	return true;
}