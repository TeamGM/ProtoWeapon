#include "BattleScene.h"
#include "ResultScene.h"

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

	//임시메뉴코드 시작
	auto item1 = MenuItemFont::create("Close BattleScene", CC_CALLBACK_1(BattleScene::batlleEnd, this));
	item1->setColor(Color3B(255, 255, 255));

	auto pMenu = Menu::create(item1, NULL);

	pMenu->setPosition(Point(240, 50));

	this->addChild(pMenu);
	//임시메뉴코드 끝

	return true;
}

void BattleScene::batlleEnd(Ref* pSender)
{
	GameManager::getInstance()->doSoloBattleEnd(pSender);
}