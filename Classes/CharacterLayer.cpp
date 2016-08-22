#include "CharacterLayer.h"
USING_NS_CC;
CharacterLayer::CharacterLayer()
{
}
CharacterLayer::~CharacterLayer()
{
}
bool CharacterLayer::init() {
	if (!Layer::init())
	{
		return false;
	}

	player = Sprite::create("img/swordmanStand.png");
	//	player->setPosition(Vec2(640, 200));
	player->setAnchorPoint(Vec2(0.5, 0.5));
	this->addChild(player, 2);

	boss = Sprite::create("img/raDragon.png");
	boss->setPosition(Vec2(620, 400));
	boss->setAnchorPoint(Vec2(0.5, 0.5));
	this->addChild(boss, 2);

	return true;
}

void CharacterLayer::Draw(Player * player)
{
	DrawPlayer(player);
	if (boss->getPositionY() > this->player->getPositionY()) {
		this->player->setLocalZOrder(2);
		boss->setLocalZOrder(1);
	}
	else if (boss->getPositionY() < this->player->getPositionY()) {
		this->player->setLocalZOrder(1);
		boss->setLocalZOrder(2);
	}
}

void CharacterLayer::DrawPlayer(Player * player)
{
	this->player->setPosition(player->GetPositionX(), player->GetPositionY());
	//this->runAction(Follow::create(this->player, Rect(0, 0, 1280, 720)));
	//cocos2d::log("moving background...%d %d",player->GetPositionX(), player->GetPositionY());
}

cocos2d::Sprite * CharacterLayer::GetPlayer()
{
	return player;
}
