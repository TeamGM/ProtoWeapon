#include "BattleManager.h"
void BattleManager::init() {
	uiManager = new UIManager();
	fieldManager = new FieldManager();
	player = new Player();
	monster = new Monster();
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
	uiManager->Update(100, 100); //юс╫ц 100 100
	fieldManager->Update();
	player->Update();
	monster->Update();
}

UIManager * BattleManager::GetUIManager()
{
	return uiManager;
}
