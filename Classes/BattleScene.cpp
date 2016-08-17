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
	if (!Layer::init())
	{
		return false;
	}

	battleManager = new BattleManager();

	fieldLayer = FieldLayer::create();
	this->addChild(fieldLayer);

	uiLayer = UILayer::create();
	uiLayer->init(battleManager->GetUIManager());
	this->addChild(uiLayer);
	this->scheduleUpdate();


	InitKeyboardListener();
	return true;
}

void BattleScene::update(float dt)
{
	battleManager->Update();
	uiLayer->Draw(battleManager->GetUIManager());
	fieldLayer->Draw(battleManager->GetFieldManager());
}

void BattleScene::batlleEnd(Ref* pSender)
{
	GameManager::getInstance()->doSoloBattleEnd(pSender);
}

void BattleScene::InitKeyboardListener()
{
	
	auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = CC_CALLBACK_2(BattleScene::onKeyPressed, this);
	listener->onKeyReleased = CC_CALLBACK_2(BattleScene::onKeyReleased, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	// Implementation of the keyboard event callback function prototype
}
void BattleScene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	battleManager->KeyDownProcess(keyCode);
}
void BattleScene::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
	battleManager->KeyUpProcess(keyCode);
}

