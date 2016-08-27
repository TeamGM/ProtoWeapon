#include "Monster.h"
#include "math.h"
USING_NS_CC;


Monster::Monster()
{
	Init();
}
Monster::~Monster()
{
}


void Monster::Init() {
	monsterState = leftMove;
	positionX = 620;
	positionY = 800;
	nextPositionX = 620;
	nextPositionY = 800;
	hp = 200;
	atkPower = 20;
	collisionBox = new cocos2d::CCRect(-100, 40, 130, 110);
	range = 250;
	stepDistance= 80;
	frameCount = 0;
	animationFrame = 1;
}

int Monster::GetPositionX()
{
	return positionX;
}

int Monster::GetPositionY()
{
	return positionY;
}

int Monster::GetAnimationFrame()
{
	return animationFrame;
}

MonsterState Monster::GetMonsterState()
{
	return monsterState;
}

void Monster::Move()
{
	positionX = nextPositionX;
	positionY = nextPositionY;
}

void Monster::Attack()
{
}

void Monster::NextActivity(int playerX, int playerY)
{
	int directionX = playerX - positionX;
	int directionY = playerY - positionY;
	int distance = sqrtf(directionX*directionX + directionY * directionY);

	if (distance > range) {
		if (monsterState == leftMove) monsterState = rightMove;
		else monsterState = leftMove;
		nextPositionX = positionX + directionX * stepDistance / distance;
		nextPositionY = positionY + directionY  * stepDistance / distance;
	}
	else {
		if (directionX > 0)monsterState = rAttack;
		else monsterState = lAttack;
	}
}

void Monster::Update( int playerX, int playerY)
{
	frameCount++;
	if (monsterState == lAttack || monsterState == rAttack) {
		
		if (frameCount > 120) {
			frameCount -= 90;
			monsterState = leftMove;
			NextActivity(playerX, playerY);
		}
		if(frameCount<60) animationFrame=0;
		else if (frameCount < 80)animationFrame = 1;
		else animationFrame = 2;
	}
	else if (frameCount > 30) {
		NextActivity(playerX,playerY);
		frameCount -= 30;
	}
	Move();
}