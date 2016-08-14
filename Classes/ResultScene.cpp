#include "ResultScene.h"
#include "MainScene.h"

USING_NS_CC;

Scene* ResultScene::createScene()
{
	auto scene = Scene::create();

	auto layer = ResultScene::create();

	scene->addChild(layer);

	return scene;
}

bool ResultScene::init()
{
	LayerColor* initBGColor = new LayerColor();
	if (!initBGColor->initWithColor(Color4B(120, 120, 0, 120)))
	{
		return false;
	}

	//임시메뉴코드 시작
	auto item1 = MenuItemFont::create("Close ResultScene", CC_CALLBACK_1(ResultScene::resultEnd, this));
	item1->setColor(Color3B(255, 255, 255));

	auto pMenu = Menu::create(item1, NULL);

	pMenu->setPosition(Point(240, 250));

	this->addChild(pMenu);
	//임시메뉴코드 끝

	return true;
}

void ResultScene::resultEnd(Ref* pSender)
{
	GameManager::getInstance()->doSoloResultEnd(pSender);
}