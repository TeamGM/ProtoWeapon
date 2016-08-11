#include "MainUILayer.h"
#include "MainScene.h"

USING_NS_CC;

bool MainUILayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto item1 = MenuItemFont::create("Start", CC_CALLBACK_1(MainUILayer::doStartGameSelect, this));
	item1->setColor(Color3B(255, 255, 255));

	auto pMenu = Menu::create(item1, NULL);

	pMenu->alignItemsVertically();

	this->addChild(pMenu);

	return true;
}

void MainUILayer::doStartGameSelect(Ref* pSender)
{
	//auto pScene = BattleScene::createScene();
	//Director::getInstance()->replaceScene(pScene);
		
	this->setVisible(false);
}