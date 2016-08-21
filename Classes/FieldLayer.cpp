#include "FieldLayer.h"
USING_NS_CC;
FieldLayer::FieldLayer()
{
}
FieldLayer::~FieldLayer()
{
}
bool FieldLayer::init(){
	if (!Layer::init())
	{
		return false;
	}

	map = Sprite::create("img/field.png");
	map->setPosition(Vec2(0, 0));
	map->setAnchorPoint(Vec2(0, 0));
	
	this->addChild(map, 0);

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

void FieldLayer::Draw(FieldManager * fieldManager)
{
	DrawPlayer(fieldManager->getPlayer());
	if (boss->getPositionY() > player->getPositionY()) {
		player->setLocalZOrder(2);
		boss->setLocalZOrder(1);
	}
	else if (boss->getPositionY() < player->getPositionY()) {
		player->setLocalZOrder(1);
		boss->setLocalZOrder(2);
	}
	this->runAction(Follow::create(player, Rect(0, 0, 1280, 720)));
}

void FieldLayer::DrawPlayer(Player * player)
{
	this->player->setPosition(player->GetPositionX(), player->GetPositionY());
	//this->runAction(Follow::create(this->player, Rect(0, 0, 1280, 720)));
	//cocos2d::log("moving background...%d %d",player->GetPositionX(), player->GetPositionY());
}
