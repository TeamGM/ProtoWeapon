#include "MainScene.h"

USING_NS_CC;

Scene* MainScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = MainScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

bool MainScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto item1 = MenuItemFont::create("startBattleScene", CC_CALLBACK_1(MainScene::doStartBattleScene, this));
	item1->setColor(Color3B(255, 255, 255));

	//auto item2 = 

	auto pMenu = Menu::create(item1, NULL);

	pMenu->alignItemsVertically();

	this->addChild(pMenu);

	return true;
}

void MainScene::doStartBattleScene(Ref* pSender)
{
	auto pScene = BattleScene::createScene();
	Director::getInstance()->replaceScene(pScene);
}