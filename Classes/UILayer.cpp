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
}

void UILayer::DrawFire(UIFire * fire)
{
}
