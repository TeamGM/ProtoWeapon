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
	//�ӽø޴��ڵ� ����
	auto item1 = MenuItemFont::create("Close ResultScene", CC_CALLBACK_1(ResultUILayer::endResultScene, this));
	item1->setColor(Color3B(255, 255, 255));

	auto pMenu = Menu::create(item1, NULL);

	pMenu->setPosition(Point(400, 30));
	pMenu->setAnchorPoint(Vec2(0, 0));

	this->addChild(pMenu,2);
	//�ӽø޴��ڵ� ��

	auto sprSceneLogo = Sprite::create("img/Result_Logo.png");
	auto sprBoard = Sprite::create("img/CharacterSelectBoard.png");

	this->addChild(sprBoard, 1);
	this->addChild(sprSceneLogo, 2);
	
	if (winGame)
	{
		auto sprBtlResultLogo = Sprite::create("img/Succeed_Logo.png");
		this->addChild(sprBtlResultLogo, 2);
	} 
	else
	{
		auto sprBtlResultLogo = Sprite::create("img/FAILED_LOGO.png");
		this->addChild(sprBtlResultLogo, 2);
	}
}

void ResultUILayer::endResultScene(Ref* pSender)
{
	GameManager::getInstance()->startSoloMainScene(pSender);
}