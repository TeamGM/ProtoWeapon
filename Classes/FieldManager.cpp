#include "FieldManager.h"
FieldManager::FieldManager() {
	Init();
	player = new Player();
	monster = new Monster();
}

FieldManager::~FieldManager()
{
}

void FieldManager::Init()
{
	player = new Player();
	monster = new Monster();
}

Player * FieldManager::GetPlayer()
{
	return player;
}

Monster * FieldManager::GetMonster() {
	return monster;
}

void FieldManager::Update(int moveDirectionX, int moveDirectionY, int fireStatus)
{
	player->Update(moveDirectionX, moveDirectionY, fireStatus );
	player->Move();
	monster->Update(player->GetPositionX(), player->GetPositionY());
}
