#include "UIManager.h"

void UIManager::Update(int bossHPRatio, int playerHPRatio) {
	this->playerHPRatio = playerHPRatio;
	this->bossHPRatio = bossHPRatio;
	stick->Update();
	fire->Update();
}

UIFire* UIManager::GetUIFire() {
	return fire;
}

int UIManager::GetBossHPRatio()
{
	return bossHPRatio;
}

int UIManager::GetPlayerHPRatio()
{
	return playerHPRatio;
}

void UIManager::KeyDownProcess(cocos2d::EventKeyboard::KeyCode keyCode)
{
	stick->KeyDownProcess(keyCode);
	fire->KeyDownProcess(keyCode);
}
void UIManager::KeyUpProcess(cocos2d::EventKeyboard::KeyCode keyCode)
{
	stick->KeyUpProcess(keyCode);
	fire->KeyUpProcess(keyCode);
}
UIStick* UIManager::GetUIStick() {
	return stick;
}

UIManager::UIManager() {
	init();
}

void UIManager::init() {
	stick = new UIStick();
	fire = new UIFire();

	preset.bossPictureSize = 50;
	preset.bossPicturePositionX = 25;
	preset.bossPicturePositionY = 300;
	preset.bossLifebarSizeX = 540;
	preset.bossLifebarSizeY = 25;
	preset.bossLifebarPositionX = 75;
	preset.bossLifebarPositionY = 325;

	preset.playerPictureSize = 50;
	preset.playerPicturePositionX = 25;
	preset.playerPicturePositionY = 250;
	preset.playerLifebarSizeX = 25;
	preset.playerLifebarSizeY = 240;
	preset.playerLifebarPositionX = 25;
	preset.playerLifebarPositionY = 250;
}

UIManager::~UIManager() {
	delete stick;
	delete fire;
}