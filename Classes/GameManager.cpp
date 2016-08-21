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
//**** Solo�÷��� �Լ� ���
//*********************
// ������ �÷��̾����� ���ӸŴ����� Set
void GameManager::setSoloPcJobNum(typeGameData::ENUMPCJOB pcJobN)
{
	soloSelecDatas.pcJobNum = pcJobN;
}
// ������ ����ĳ���� ���ӸŴ����� Set
void GameManager::setSoloBossNum(typeGameData::ENUMBOSS bossN)
{
	soloSelecDatas.bossNum = bossN;
}
// ���ӸŴ����� set�Ǿ��ִ� �÷��̾����� ���� �ҷ���
int GameManager::getSoloPcJobNum()
{
	return soloSelecDatas.pcJobNum;
}
// ���ӸŴ����� set�Ǿ��ִ� ����ĳ���� ���� �ҷ���
int GameManager::getSoloBossNum()
{
	return soloSelecDatas.bossNum;
}
// ��Ʋ�� ����
void GameManager::doSoloStartBattleScene(Ref* pSender)
{
	auto pScene = BattleScene::createScene();
	Director::getInstance()->replaceScene(pScene);
}
// ��Ʋ�� ����
void GameManager::doSoloBattleEnd(Ref* pSender)
{
	auto pScene = ResultScene::createScene();
	Director::getInstance()->replaceScene(pScene);
}
// ����� ����
void GameManager::doSoloResultEnd(Ref* pSender)
{
	auto pScene = MainScene::createScene();
	Director::getInstance()->replaceScene(pScene);
}
//*** Solo�÷��� �Լ� ��� ��


GameManager::~GameManager()
{

}

bool GameManager::init()
{
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("soundEffect/SEmenuSelect.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("soundBG/Neo_Space.mp3");

	return true;
}