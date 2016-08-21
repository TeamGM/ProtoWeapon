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
// 선택한 플레이어직업 게임매니저에 Set
void GameManager::setSoloPcJobNum(typeGameData::ENUMPCJOB pcJobN)
{
	soloSelecDatas.pcJobNum = pcJobN;
}
// 선택한 보스캐릭터 게임매니저에 Set
void GameManager::setSoloBossNum(typeGameData::ENUMBOSS bossN)
{
	soloSelecDatas.bossNum = bossN;
}
// 게임매니저에 set되어있는 플레이어직업 종류 불러옴
int GameManager::getSoloPcJobNum()
{
	return soloSelecDatas.pcJobNum;
}
// 게임매니저에 set되어있는 보스캐릭터 종류 불러옴
int GameManager::getSoloBossNum()
{
	return soloSelecDatas.bossNum;
}
// 배틀씬 시작
void GameManager::doSoloStartBattleScene(Ref* pSender)
{
	auto pScene = BattleScene::createScene();
	Director::getInstance()->replaceScene(pScene);
}
// 배틀씬 종료
void GameManager::doSoloBattleEnd(Ref* pSender)
{
	auto pScene = ResultScene::createScene();
	Director::getInstance()->replaceScene(pScene);
}
// 결과씬 종료
void GameManager::doSoloResultEnd(Ref* pSender)
{
	auto pScene = MainScene::createScene();
	Director::getInstance()->replaceScene(pScene);
}
//*** Solo플레이 함수 목록 끝


GameManager::~GameManager()
{

}

bool GameManager::init()
{
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("soundEffect/SEmenuSelect.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("soundBG/Neo_Space.mp3");

	return true;
}