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
	addChild(player, 2);


	monster = Sprite::create("img/raDragon.png");
	//monster->setPosition(Vec2(620, 400));
	monster->setAnchorPoint(Vec2(0.5, 0.5));
	addChild(monster, 2);

	monsterLeftMove = Sprite::create("img/radragon_walk1.png");
	monster->addChild(monsterLeftMove, 2);
	monsterLeftMove->setVisible(false);
	monsterRightMove = Sprite::create("img/radragon_walk2.png");
	monster->addChild(monsterRightMove, 2);
	monsterRightMove->setVisible(false);

	monsterLeftAttack = new Sprite *[4];
	monster->addChild(monsterLeftAttack[0] = Sprite::create("img/RD_DLAtk1.png"),2);
	monster->addChild(monsterLeftAttack[1] = Sprite::create("img/RD_DLAtk2.png"),2);
	monster->addChild(monsterLeftAttack[2] = Sprite::create("img/RD_DLAtk3.png"),2);
	monsterLeftAttack[0]->setVisible(false);
	monsterLeftAttack[1]->setVisible(false);
	monsterLeftAttack[2]->setVisible(false);
	monsterRightAttack = new Sprite *[4];
	monster->addChild(monsterRightAttack[0] = Sprite::create("img/RD_DRAtk1.png"),2);
	monster->addChild(monsterRightAttack[1] = Sprite::create("img/RD_DRAtk2.png"),2);
	monster->addChild(monsterRightAttack[2] = Sprite::create("img/RD_DRAtk3.png"),2);
	monsterRightAttack[0]->setVisible(false);
	monsterRightAttack[1]->setVisible(false);
	monsterRightAttack[2]->setVisible(false);

	playerWalkAnimation = CreateWalkAnimation();
	playerAttackAnimation = CreateAttackAnimation();
		
	return true;
}
CCAnimate * CharacterLayer::CreateMonsterAtkAnimation() {
	CCAnimation * playerAttackAnimation = CCAnimation::create();
	//playerAttackAnimation->addSpriteFrame( (CCSpriteFrame *)monsterLeftAttack->objectAtIndex(1) );
	auto result = CCAnimate::create(playerAttackAnimation);
	return result;

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
	playerAttackAnimation->addSpriteFrame(SpriteFrame::create("img/SM_Fatk2.png", CCRect(0, 0, 200, 200)));
	playerAttackAnimation->addSpriteFrame(SpriteFrame::create("img/SM_Fatk3.png", CCRect(0, 0, 200, 200)));
	playerAttackAnimation->setDelayPerUnit(0.33f);
	auto result = CCAnimate::create(playerAttackAnimation);
	return result;

}

CCAnimate * CharacterLayer::CreateHoldAnimation() {
	CCAnimation * playerAttackAnimation = CCAnimation::create();
	playerAttackAnimation->addSpriteFrame(SpriteFrame::create("img/SM_Fatk1.png", CCRect(0, 0, 200, 200)));
	playerAttackAnimation->setDelayPerUnit(1.0f);
	auto result = CCAnimate::create(playerAttackAnimation);
	return result;

}

void CharacterLayer::Draw(Player * player, Monster * monster)
{
	DrawPlayer(player);
	DrawMonster(monster);
	if (this->monster->getPositionY() > this->player->getPositionY()) {
		this->player->setLocalZOrder(2);
		this->monster->setLocalZOrder(1);
	}
	else if (this->monster->getPositionY() < this->player->getPositionY()) {
		this->player->setLocalZOrder(1);
		this->monster->setLocalZOrder(2);
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
		else if (playerState == hold)
			this->player->stopAction(playerAttackAnimation);

		if (newPlayerState == move) 
			this->player->runAction(playerWalkAnimation=CreateWalkAnimation());	
		else if (newPlayerState == atk) 
			this->player->runAction(playerAttackAnimation=CreateAttackAnimation());
		else if (newPlayerState == hold)
			this->player->runAction(playerAttackAnimation=CreateHoldAnimation());
		
		playerState = newPlayerState;
	}

}

void CharacterLayer::DrawMonster(Monster * monster)
{
	monsterLeftAttack[1]->getDisplayFrame();
	this->monster->setPosition(monster->GetPositionX(), monster->GetPositionY());
	MonsterState newMonsterState = monster->GetMonsterState();
	if (newMonsterState == leftMove)
		this->monster->setSpriteFrame(monsterLeftMove->displayFrame());
	if (newMonsterState == lAttack)
		this->monster->setSpriteFrame(monsterLeftAttack[monster->GetAnimationFrame()]->displayFrame());
	if (newMonsterState == rightMove)
		this->monster->setSpriteFrame(monsterRightMove->displayFrame());
	if (newMonsterState == rAttack)
		this->monster->setSpriteFrame(monsterRightAttack[monster->GetAnimationFrame()]->displayFrame());
	monsterState = newMonsterState;
}

cocos2d::Sprite * CharacterLayer::GetPlayer()
{
	return player;
}
