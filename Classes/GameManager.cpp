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

void GameManager::setSoloPcJobNum(typeGameData::ENUMPCJOB pcJobN)
{
	soloSelecDatas.pcJobNum = pcJobN;
}

void GameManager::setSoloBossNum(typeGameData::ENUMBOSS bossN)
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

void GameManager::startSoloBattleScene(Ref* pSender)
{
	CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("soundBG/Destruction.mp3");
	auto pScene = BattleScene::createScene();
	Director::getInstance()->replaceScene(pScene);
}

void GameManager::startSoloResultScene(Ref* pSender)
{
	CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("soundBG/Another_time.mp3");
	auto pScene = ResultScene::createScene();
	Director::getInstance()->replaceScene(pScene);
}

void GameManager::startSoloMainScene(Ref* pSender)
{
	CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
	auto pScene = MainScene::createScene();
	Director::getInstance()->replaceScene(pScene);
}

void GameManager::setSoloBattleResult(bool battleResult)
{
	soloBattleResult = battleResult;
}

bool GameManager::getSoloBattleResult()
{
	return soloBattleResult;
}
//*** Solo플레이 함수 목록 끝


GameManager::~GameManager()
{

}

bool GameManager::init()
{
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("soundEffect/SEmenuSelect.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("soundBG/Neo_Space.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("soundBG/Destruction.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("soundBG/Another_time.mp3");

	return true;
}