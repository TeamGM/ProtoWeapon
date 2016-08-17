#include "BattleScene.h"

USING_NS_CC;

Scene* BattleScene::createScene()
{
	auto scene = Scene::create();
	auto layer = BattleScene::create();
	scene->addChild(layer);
	return scene;
}

bool BattleScene::init()
{
	//LayerColor* initBGColor = new LayerColor();
	if (!LayerColor::initWithColor(Color4B(0, 120, 0, 120)))
	{
		return false;
	}


	battleManager = new BattleManager();
	uiLayer = UILayer::create();
	uiLayer->init(battleManager->GetUIManager());
	this->addChild(uiLayer);
	this->scheduleUpdate();
	return true;
}

void BattleScene::update(float dt)
{
	battleManager->Update();
	uiLayer->Draw(battleManager->GetUIManager());
}

void BattleScene::batlleEnd(Ref* pSender)
{
	GameManager::getInstance()->doSoloBattleEnd(pSender);
}
