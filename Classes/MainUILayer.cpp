#include "MainUILayer.h"
#include "MainScene.h"
#include "BattleScene.h"

USING_NS_CC;

bool MainUILayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	//UI 기본위치에 생성
	initTitleUI();
	//initPcSelectUI();
	//initBossSelectUI();

	return true;
}

void MainUILayer::initTitleUI()
{
	auto okBtnNormal = Sprite::create("img/TabtoStart.png");
	auto okBtnSelected = Sprite::createWithSpriteFrame(okBtnNormal->getSpriteFrame());
	auto okBtnDisabled = Sprite::createWithSpriteFrame(okBtnNormal->getSpriteFrame());
	okBtnDisabled->setColor(Color3B(50, 50, 50));
	okBtnSelected->setScale(1.1);

	auto StartBtn = MenuItemSprite::create(okBtnNormal, okBtnSelected, okBtnDisabled, CC_CALLBACK_0(MainUILayer::initPcSelectUI,this));
	StartBtn->setPosition(Vec2(0, 0));

	auto pMenu = Menu::create(StartBtn, NULL);
	pMenu->setPosition(Vec2(320, 110));
	pMenu->setName("startBtn");

	this->addChild(pMenu,1);
	//this->addChild(spr);
}

void MainUILayer::initPcSelectUI()
{
	//tabtostart 찾아서 제거
	//auto stBtn = this->getChildByName("startBtn");
	//stBtn->setVisible(false);
	this->removeChildByName("startBtn");

	//셀렉트보드 로드
	auto selectBoard = Sprite::create("img/CharacterSelectBoard.png");
	selectBoard->setPosition(Vec2(320, 180));
	this->addChild(selectBoard, 1);

	//셀렉트 캐릭터 로고 로드
	auto selectPcLogo = Sprite::create("img/selectCharacter_Logo.png");
	selectPcLogo->setPosition(Vec2(80, 265));
	selectPcLogo->setAnchorPoint(Vec2(0, 0));
	selectPcLogo->setName("pcLogo");
	this->addChild(selectPcLogo, 2);

	//캐릭터 로드
	//소드맨
	auto swordmanNormal = Sprite::create("img/swordmanStand.png");
	auto swordmanSelected = Sprite::createWithSpriteFrame(swordmanNormal->getSpriteFrame());
	auto swordmanDisabled = Sprite::createWithSpriteFrame(swordmanNormal->getSpriteFrame());
	auto swordmanSelectedFrame = Sprite::create("img/selectedFrame.png");
	swordmanSelected->setAnchorPoint(Vec2(0, 0));
	swordmanSelected->setScale(0.6);
	swordmanSelectedFrame->setScale(2.0);
	swordmanSelectedFrame->addChild(swordmanSelected,0);
	//아쳐
	auto archerNormal = Sprite::createWithSpriteFrame(swordmanNormal->getSpriteFrame());
	auto archerSelected = Sprite::createWithSpriteFrame(swordmanNormal->getSpriteFrame());
	auto archerDisabled = Sprite::createWithSpriteFrame(swordmanNormal->getSpriteFrame());
	auto archerSelectedFrame = Sprite::createWithSpriteFrame(swordmanSelectedFrame->getSpriteFrame());
	archerSelected->setAnchorPoint(Vec2(0, 0));
	archerSelected->setScale(0.6);
	archerSelectedFrame->setScale(2.0);
	archerSelectedFrame->addChild(archerSelected, 0);
	//위자드
	auto wizardNormal = Sprite::createWithSpriteFrame(swordmanNormal->getSpriteFrame());
	auto wizardSelected = Sprite::createWithSpriteFrame(swordmanNormal->getSpriteFrame());
	auto wizardDisabled = Sprite::createWithSpriteFrame(swordmanNormal->getSpriteFrame());
	auto wizardSelectedFrame = Sprite::createWithSpriteFrame(swordmanSelectedFrame->getSpriteFrame());
	wizardSelected->setAnchorPoint(Vec2(0, 0));
	wizardSelected->setScale(0.6);
	wizardSelectedFrame->setScale(2.0);
	wizardSelectedFrame->addChild(wizardSelected, 0);

	auto pcJob01 = MenuItemSprite::create(swordmanNormal, swordmanSelectedFrame, swordmanDisabled, CC_CALLBACK_0(MainUILayer::initBossSelectUI, this));
	auto pcJob02 = MenuItemSprite::create(archerNormal, archerSelectedFrame, archerDisabled, CC_CALLBACK_0(MainUILayer::initBossSelectUI, this));
	auto pcJob03 = MenuItemSprite::create(wizardNormal, wizardSelectedFrame, wizardDisabled, CC_CALLBACK_0(MainUILayer::initBossSelectUI, this));

	pcJob01->setScale(0.5f);
	pcJob02->setScale(0.5f);
	pcJob03->setScale(0.5f);
	
	pcJob01->setPosition(Vec2(120+50, 180));
	pcJob02->setPosition(Vec2(320, 180));
	pcJob03->setPosition(Vec2(520-50, 180));

	auto pMenu01 = Menu::create(pcJob01, pcJob02, pcJob03, NULL);

	pMenu01->setPosition(Vec2(0, 0));
	pMenu01->setName("pcSelectObj");

	this->addChild(pMenu01,3);
}

void MainUILayer::initBossSelectUI()
{
	//selectPcLogo 찾아서 제거
	this->removeChildByName("pcLogo");
	this->removeChildByName("pcSelectObj");

	//셀렉트로고
	auto selecBossLogo = Sprite::create("img/selectMonster_Logo.png");
	selecBossLogo->setPosition(Vec2(80, 265));
	selecBossLogo->setAnchorPoint(Vec2(0, 0));
	selecBossLogo->setName("bossLogo");
	this->addChild(selecBossLogo, 2);

	auto item1 = MenuItemFont::create("BoooooooooooooooooooSS", CC_CALLBACK_1(MainUILayer::doStartGameSelect, this));
	
	item1->setColor(Color3B(255, 255, 255));
	item1->setPosition(Vec2(300, 100));

	auto pMenu = Menu::create(item1, NULL);
	pMenu->setPosition(Vec2(0, 0));

	this->addChild(pMenu, 2);
}

void MainUILayer::doStartGameSelect(Ref* pSender)
{
	auto pScene = BattleScene::createScene();
	Director::getInstance()->replaceScene(pScene);
}