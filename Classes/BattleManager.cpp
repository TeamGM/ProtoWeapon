#include "BattleManager.h"
void BattleManager::init() {
	uiManager = new UIManager();
	fieldManager = new FieldManager();
}
BattleManager::BattleManager() {
	init();
}
BattleManager::~BattleManager() {
	delete uiManager;
	delete fieldManager;
}
void BattleManager::Update()
{
	fieldManager->Update(uiManager->GetUIStick()->GetDirection().x, uiManager->GetUIStick()->GetDirection().y, uiManager->GetUIFire()->GetFireStatus() );
	uiManager->Update(100, 100); //юс╫ц 100 100
}

UIManager * BattleManager::GetUIManager()
{
	return uiManager;
}

FieldManager * BattleManager::GetFieldManager()
{
	return fieldManager;
}

void BattleManager::KeyDownProcess(cocos2d::EventKeyboard::KeyCode keyCode)
{
	uiManager->KeyDownProcess(keyCode);
}
void BattleManager::KeyUpProcess(cocos2d::EventKeyboard::KeyCode keyCode)
{
	uiManager->KeyUpProcess(keyCode);
}