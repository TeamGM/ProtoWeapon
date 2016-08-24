#include "ResultUILayer.h"


bool ResultUILayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	initResultUI();

	return true;
}

void ResultUILayer::initResultUI()
{
	//임시메뉴코드 시작
	auto item1 = MenuItemFont::create("Close ResultScene", CC_CALLBACK_1(ResultUILayer::resultEnd, this));
	item1->setColor(Color3B(255, 255, 255));

	auto pMenu = Menu::create(item1, NULL);

	pMenu->setPosition(Point(400, 30));
	pMenu->setAnchorPoint(Vec2(0, 0));

	this->addChild(pMenu);
	//임시메뉴코드 끝
}

void ResultUILayer::resultEnd(Ref* pSender)
{
	GameManager::getInstance()->doSoloResultEnd(pSender);
}