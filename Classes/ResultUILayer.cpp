#include "ResultUILayer.h"


bool ResultUILayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	
	winGame = GameManager::getInstance()->getSoloBattleResult();
	initResultUI();

	return true;
}

void ResultUILayer::initResultUI()
{
	//임시메뉴코드 시작
	auto item1 = MenuItemFont::create("Close ResultScene", CC_CALLBACK_1(ResultUILayer::endResultScene, this));
	item1->setColor(Color3B(255, 255, 255));

	auto pMenu = Menu::create(item1, NULL);

	pMenu->setPosition(Vec2(400, 30));
	pMenu->setAnchorPoint(Vec2(0, 0));

	this->addChild(pMenu,2);
	//임시메뉴코드 끝

	auto sprSceneLogo = Sprite::create("img/result_Logo.png");
	sprSceneLogo->setAnchorPoint(Vec2(0, 0));
	sprSceneLogo->setPosition(Vec2(60, 295));

	auto sprBoard = Sprite::create("img/CharacterSelectBoard.png");
	sprBoard->setAnchorPoint(Vec2(0.5, 0.5));
	sprBoard->setPosition(Vec2(320, 180));

	this->addChild(sprBoard, 1);
	this->addChild(sprSceneLogo, 2);
	
	if (winGame)
	{
		auto sprBtlResultLogo = Sprite::create("img/succed_logo.png");
		sprBtlResultLogo->setAnchorPoint(Vec2(0.5, 0.5));
		sprBtlResultLogo->setPosition(Vec2(320, 180));
		this->addChild(sprBtlResultLogo, 2);
	} 
	else
	{
		auto sprBtlResultLogo = Sprite::create("img/FAILED_logo.png");
		sprBtlResultLogo->setAnchorPoint(Vec2(0.5, 0.5));
		sprBtlResultLogo->setPosition(Vec2(320, 180));
		this->addChild(sprBtlResultLogo, 2);
	}
}

void ResultUILayer::endResultScene(Ref* pSender)
{
	GameManager::getInstance()->startSoloMainScene(pSender);
}