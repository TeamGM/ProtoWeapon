#include "UIManager.h"

void UIManager::Update() {
	stick->Update();
	fire->Update();
}

UIFire* UIManager::GetUIFire() {
	return fire;
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
}

UIManager::~UIManager() {
	delete stick;
	delete fire;
}