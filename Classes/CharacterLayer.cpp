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
	
	playerState = nothing;
	player = Sprite::create("img/swordmanStand.png");
	//	player->setPosition(Vec2(640, 200));
	player->setAnchorPoint(Vec2(0.5, 0.5));
	this->addChild(player, 2);


	boss = Sprite::create("img/raDragon.png");
	boss->setPosition(Vec2(620, 400));
	boss->setAnchorPoint(Vec2(0.5, 0.5));
	this->addChild(boss, 2);

	playerWalkAnimation = CreateWalkAnimation();
	playerAttackAnimation = CreateAttackAnimation();
		
	return true;
}

RepeatForever * CharacterLayer::CreateWalkAnimation() {
	
	CCAnimation * playerWalkAnimation = CCAnimation::create();
	playerWalkAnimation->addSpriteFrame(SpriteFrame::create("img/SM_Fwalk1.png", CCRect(0, 0, 100, 100)));
	playerWalkAnimation->addSpriteFrame(SpriteFrame::create("img/SwordmanForward.png", CCRect(0, 0, 100, 100)));
	playerWalkAnimation->addSpriteFrame(SpriteFrame::create("img/SM_Fwalk2.png", CCRect(0, 0, 100, 100)));
	playerWalkAnimation->addSpriteFrame(SpriteFrame::create("img/SwordmanForward.png", CCRect(0, 0, 100, 100)));
	playerWalkAnimation->setDelayPerUnit(0.25f);
	auto result = RepeatForever::create(CCAnimate::create(playerWalkAnimation));
	return result;
}

CCAnimate * CharacterLayer::CreateAttackAnimation() {
	CCAnimation * playerAttackAnimation = CCAnimation::create();
	playerAttackAnimation->addSpriteFrame(SpriteFrame::create("img/SM_Fatk1.png", CCRect(0, 0, 200, 200)));
	playerAttackAnimation->addSpriteFrame(SpriteFrame::create("img/SM_Fatk2.png", CCRect(0, 0, 200, 200)));
	playerAttackAnimation->addSpriteFrame(SpriteFrame::create("img/SM_Fatk3.png", CCRect(0, 0, 200, 200)));
	playerAttackAnimation->setDelayPerUnit(0.33f);
	auto result = CCAnimate::create(playerAttackAnimation);
	return result;

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
	PlayerState newPlayerState = player->GetPlayerState();
	if (newPlayerState !=playerState) {

		if (playerState == move)
			this->player->stopAction(playerWalkAnimation);
		else if (playerState == atk)
			this->player->stopAction(playerAttackAnimation);

		if (newPlayerState == move) {
			this->player->runAction(playerWalkAnimation=CreateWalkAnimation());	
		}
		if (newPlayerState == atk) {
			this->player->runAction(playerAttackAnimation=CreateAttackAnimation());
		}
		playerState = newPlayerState;
	}

}

cocos2d::Sprite * CharacterLayer::GetPlayer()
{
	return player;
}
