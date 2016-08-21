#include "FieldManager.h"
FieldManager::FieldManager() {
	Init();
}

FieldManager::~FieldManager()
{
}

void FieldManager::Init()
{
	player = new Player();
}

Player * FieldManager::getPlayer()
{
	return player;
}

void FieldManager::Update(int moveDirectionX, int moveDirectionY)
{
	player->Update(moveDirectionX, moveDirectionY, Player::FireStatus::none );
	player->Move();
}
