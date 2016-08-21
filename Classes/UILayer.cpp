#include "UILayer.h"

USING_NS_CC;
bool UILayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	return true;
}
bool UILayer::init(UIManager * uiManager)
{
	if (!Layer::init())
	{
		return false;
	}

	monsterPicture = Sprite::create("img/UI_RDFace.png");
	monsterPicture->setPosition(uiManager->preset.bossPicturePositionX, uiManager->preset.bossPicturePositionY);
	monsterPicture->setAnchorPoint(Vec2(0, 0));
	this->addChild(monsterPicture, 0);

	playerPicture = Sprite::create("img/UI_PlayerFace.png");
	playerPicture->setPosition(uiManager->preset.playerPicturePositionX, uiManager->preset.playerPicturePositionY);
	playerPicture->setAnchorPoint(Vec2(0, 0));
	this->addChild(playerPicture, 0);

	playerHP = Sprite::create("img/UI_PlayerHP.png");
	playerHP->setPosition(uiManager->preset.playerLifebarPositionX, uiManager->preset.playerLifebarPositionY);
	playerHP->setAnchorPoint(Vec2(0, 1));
	this->addChild(playerHP);

	bossHP = Sprite::create("img/UI_MonsterHP.png");
	bossHP->setPosition(uiManager->preset.bossLifebarPositionX, uiManager->preset.bossLifebarPositionY);
	bossHP->setAnchorPoint(Vec2(0, 0));
	this->addChild(bossHP);

	stickBG = Sprite::create("img/UI_Stick_BG.png");
	stickBG->setAnchorPoint(Vec2(0.5, 0.5));
	stickBG->setPosition(Vec2(100, 100));
	this->addChild(stickBG);

	stickPoint = Sprite::create("img/UI_Stick.png");
	stickPoint->setAnchorPoint(Vec2(0.5, 0.5));
	stickPoint->setPosition(Vec2(100, 100));
	this->addChild(stickPoint);
	
	fireBG = Sprite::create("img/UI_Fire_BG.png");
	fireBG->setAnchorPoint(Vec2(0.5, 0.5));
	fireBG->setPosition(Vec2(540, 100));
	firePoint = Sprite::create("img/UI_Fire.png");
	firePoint->setAnchorPoint(Vec2(0.5, 0.5));
	firePoint->setPosition(Vec2(540, 100));
	this->addChild(fireBG);
	this->addChild(firePoint);

	return true;
}

void UILayer::Draw(UIManager * uiManager)
{
	DrawBossHP(uiManager->GetBossHPRatio());
	DrawPlayerHP(uiManager->GetPlayerHPRatio());
	DrawStick(uiManager->GetUIStick());
	DrawFire(uiManager->GetUIFire());
}

void UILayer::DrawBossHP(int bossHPRatio)
{
}

void UILayer::DrawPlayerHP(int playerHPRatio)
{
}

void UILayer::DrawStick(UIStick * stick)
{
	stickPoint->setPosition(stick->GetCurrentPosition());
	if (stick->GetIsPressing() == false) {
		stickBG->setVisible(false);
		stickPoint->setVisible(false);
	}
	else {
		stickBG->setVisible(true);
		stickPoint->setVisible(true);
	}
	
}

void UILayer::DrawFire(UIFire * fire)
{
	
	if (fire->GetIsHolding()) {
		fireBG->setVisible(true);
		firePoint->setVisible(true);
	}
	else  { 
		fireBG->setVisible(false);
		firePoint->setVisible(false);
	}
	int holdFrame = fire->GetFireHoldFrame();
	if (holdFrame > 30)holdFrame = 30;
		float ratio = (30.0 + 1 * holdFrame) / 30.0;
	firePoint->setScale(ratio);
}
