#include "Player.h"

Player::Player()
{
	Init();
}

Player::~Player()
{
}

void Player::Init()
{
	positionX = 640;
	positionY = 250;
	directionX = 0;
	directionY = 0;
	moveSpeed = 3;
}
void Player::Move() {
	if (nextPositionX > 1280 || nextPositionX < 0 || nextPositionY > 640 || nextPositionY < 0){
		Stay();
		return;
	}
	positionX = nextPositionX;
	positionY = nextPositionY;
}
void Player::Stay() {
	nextPositionX = positionX;
	nextPositionY = positionY;
}

int Player::GetPositionX()
{
	return positionX;
}
int Player::GetPositionY()
{
	return positionY;
}

void Player::Update(int directionX, int directionY)
{
	this->directionX = directionX;
	this->directionY = directionY;
	nextPositionX = positionX + directionX*moveSpeed;
	nextPositionY = positionY + directionY*moveSpeed;
	if (nextPositionY < 0) {
		;
	}
}
