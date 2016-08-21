#include "MainUILayer.h"


bool MainUILayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto* pageview = ui::PageView::create();

	//UI 기본위치에 생성
	initMainUI();
	//initPcSelectUI();
	//initBossSelectUI();

	return true;
}

void MainUILayer::initMainUI()
{
	ui::PageView* pageview = ui::PageView::create();
	//pageview->setSize()

	initTitleUI(pageview);
}

void MainUILayer::initTitleUI(ui::PageView* pageview)
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
}

void MainUILayer::initPcSelectUI(/*ui::PageView* pageview*/)
{
	int soundID_temp = CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("soundEffect/SEmenuSelect.mp3");
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

	//캐릭터 스프라이트 로드
	//소드맨
	auto swordmanNormal = Sprite::create("img/swordmanStand.png");
	auto swordmanSelected = Sprite::createWithSpriteFrame(swordmanNormal->getSpriteFrame());
	auto swordmanDisabled = Sprite::createWithSpriteFrame(swordmanNormal->getSpriteFrame());
	auto swordmanSelectedFrame = Sprite::create("img/selectedFrame.png");
	swordmanSelected->setAnchorPoint(Vec2(0, 0));
	swordmanSelectedFrame->addChild(swordmanSelected,0);
	//아쳐
	auto archerNormal = Sprite::createWithSpriteFrame(swordmanNormal->getSpriteFrame());
	auto archerSelected = Sprite::createWithSpriteFrame(swordmanNormal->getSpriteFrame());
	auto archerDisabled = Sprite::createWithSpriteFrame(swordmanNormal->getSpriteFrame());
	auto archerSelectedFrame = Sprite::createWithSpriteFrame(swordmanSelectedFrame->getSpriteFrame());
	archerSelected->setAnchorPoint(Vec2(0, 0));
	archerSelectedFrame->addChild(archerSelected, 0);
	//위자드
	auto wizardNormal = Sprite::createWithSpriteFrame(swordmanNormal->getSpriteFrame());
	auto wizardSelected = Sprite::createWithSpriteFrame(swordmanNormal->getSpriteFrame());
	auto wizardDisabled = Sprite::createWithSpriteFrame(swordmanNormal->getSpriteFrame());
	auto wizardSelectedFrame = Sprite::createWithSpriteFrame(swordmanSelectedFrame->getSpriteFrame());
	wizardSelected->setAnchorPoint(Vec2(0, 0));
	wizardSelectedFrame->addChild(wizardSelected, 0);

	auto pcJob01 = MenuItemSprite::create(swordmanNormal, swordmanSelectedFrame, swordmanDisabled, CC_CALLBACK_0(MainUILayer::setSelectedJob, this, typeGameData::SWORDMNAN));
	auto pcJob02 = MenuItemSprite::create(archerNormal, archerSelectedFrame, archerDisabled, CC_CALLBACK_0(MainUILayer::setSelectedJob, this, typeGameData::ARCHER));
	auto pcJob03 = MenuItemSprite::create(wizardNormal, wizardSelectedFrame, wizardDisabled, CC_CALLBACK_0(MainUILayer::setSelectedJob, this, typeGameData::WIZARD));
		
	pcJob01->setPosition(Vec2(120+50, 180));
	pcJob02->setPosition(Vec2(320, 180));
	pcJob03->setPosition(Vec2(520-50, 180));

	auto pSelectPcObj = Menu::create(pcJob01, pcJob02, pcJob03, NULL);

	pSelectPcObj->setPosition(Vec2(0, 0));
	pSelectPcObj->setName("selectPcObj");

	this->addChild(pSelectPcObj,2);
}

void MainUILayer::initBossSelectUI(/*ui::PageView* pageview*/)
{
	//selectPcLogo 찾아서 제거
	this->removeChildByName("pcLogo");
	this->removeChildByName("selectPcObj");

	//셀렉트로고
	auto selecBossLogo = Sprite::create("img/selectMonster_Logo.png");
	selecBossLogo->setPosition(Vec2(80, 265));
	selecBossLogo->setAnchorPoint(Vec2(0, 0));
	selecBossLogo->setName("bossLogo");
	this->addChild(selecBossLogo, 2);

	//보스 스프라이트 로드
	//베히
	auto behimothNormal = Sprite::create("img/behimoth.png");
	auto behimothSelected = Sprite::createWithSpriteFrame(behimothNormal->getSpriteFrame());
	auto behimothDisabled = Sprite::createWithSpriteFrame(behimothNormal->getSpriteFrame());
	auto behimothSelectedFrame = Sprite::create("img/selectMonsterFrame.png");
	behimothSelected->setAnchorPoint(Vec2(0, 0));
	behimothSelected->setScale(0.5);
	behimothSelectedFrame->setScale(2.0);
	behimothSelectedFrame->addChild(behimothSelected, 0);
	//레비
	auto LeviathanNormal = Sprite::create("img/Leviathan.png");
	auto LeviathanSelected = Sprite::createWithSpriteFrame(LeviathanNormal->getSpriteFrame());
	auto LeviathanDisabled = Sprite::createWithSpriteFrame(LeviathanNormal->getSpriteFrame());
	auto LeviathanSelectedFrame = Sprite::createWithSpriteFrame(behimothSelectedFrame->getSpriteFrame());
	LeviathanSelected->setAnchorPoint(Vec2(0, 0));
	LeviathanSelected->setScale(0.5);
	LeviathanSelectedFrame->setScale(2.0);
	LeviathanSelectedFrame->addChild(LeviathanSelected, 0);
	//라드
	auto radragonNormal = Sprite::create("img/radragon.png");
	auto radragonSelected = Sprite::createWithSpriteFrame(radragonNormal->getSpriteFrame());
	auto radragonDisabled = Sprite::createWithSpriteFrame(radragonNormal->getSpriteFrame());
	auto radragonSelectedFrame = Sprite::createWithSpriteFrame(behimothSelectedFrame->getSpriteFrame());
	radragonSelected->setAnchorPoint(Vec2(0, 0));
	radragonSelected->setScale(0.5);
	radragonSelectedFrame->setScale(2.0);
	radragonSelectedFrame->addChild(radragonSelected, 0);

	auto boss01 = MenuItemSprite::create(behimothNormal, behimothSelectedFrame, behimothDisabled, CC_CALLBACK_0(MainUILayer::setSelectedBoss, this,typeGameData::BEHIMOTH));
	auto boss02 = MenuItemSprite::create(LeviathanNormal, LeviathanSelectedFrame, LeviathanDisabled, CC_CALLBACK_0(MainUILayer::setSelectedBoss, this,typeGameData::LEVIATHAN));
	auto boss03 = MenuItemSprite::create(radragonNormal, radragonSelectedFrame, radragonDisabled, CC_CALLBACK_0(MainUILayer::setSelectedBoss, this,typeGameData::RADRAGON));

	boss01->setPosition(Vec2(320, 180));
	boss02->setPosition(Vec2(470, 180));
	boss03->setPosition(Vec2(150, 180));

	boss01->setScale(0.5);
	boss02->setScale(0.5);
	boss03->setScale(0.5);

	auto pSelectBossObj = Menu::create(boss01, boss02, boss03, NULL);
	pSelectBossObj->setPosition(Vec2(0, 0));

	this->addChild(pSelectBossObj, 2);
}

//********************************
//데이터 세팅함수
//********************************
void MainUILayer::setSelectedJob(typeGameData::ENUMPCJOB pcJob)
{
	int soundID_temp = CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("soundEffect/SEmenuSelect.mp3");
	GameManager::getInstance()->setSoloPcJobNum(pcJob);
	int a = GameManager::getInstance()->getSoloPcJobNum();
	CCLOG("selected job : %d", a);
	initBossSelectUI();
}
void MainUILayer::setSelectedBoss(typeGameData::ENUMBOSS boss)
{
	int soundID_temp = CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("soundEffect/SEmenuSelect.mp3");
	GameManager::getInstance()->setSoloBossNum(boss);
	int a = GameManager::getInstance()->getSoloBossNum();
	CCLOG("selected job : %d", a);
	doStartGameSelect(this);
}

//****************************
/* 연출 함수 따로 만들 것 */
//****************************

void MainUILayer::doStartGameSelect(Ref* pSender)
{
	GameManager::getInstance()->doSoloStartBattleScene(pSender);
}