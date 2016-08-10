#include "TitleLayer.h"
#include "BattleScene.h"

USING_NS_CC;

bool TitleLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto item1 = MenuItemFont::create("startBattleScene", CC_CALLBACK_1(TitleLayer::doStartBattleScene, this));
	item1->setColor(Color3B(255, 255, 255));

	auto pMenu = Menu::create(item1, NULL);

	pMenu->alignItemsVertically();

	this->addChild(pMenu);

	return true;
}

void TitleLayer::doStartBattleScene(Ref* pSender)
{
	auto pScene = BattleScene::createScene();
	Director::getInstance()->replaceScene(pScene);

	//this->setVisible(false);
}