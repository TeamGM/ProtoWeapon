#include "Player.h"
#include "math.h"

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
	directionLock = false;
	moveLock = false;
	tumbleLock = false;
	atkLock=false;
	InitAnimations();
	
}

void Player::InitAnimations() {
	animationMaxFrames[atk] = 2;
	animationFrameDelays[atk][1] = 20;
	animationFrameDelays[atk][2] = 20;

	animationMaxFrames[hold] = 1;
	animationFrameDelays[hold][1] = 20;
	
	animationMaxFrames[tumble] = 1;
	animationFrameDelays[tumble][1] = 30;
	
	animationMaxFrames[damaged] = 1;
	animationFrameDelays[damaged][1] = 30;

	animationPlaying = nothing;
	currentAnimationFrame = 0;
	currentFrame = 0;
}

void Player::Move() {
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

void Player::AnimationProcess( )
{
	currentFrame++;
	if (currentFrame > animationFrameDelays[animationPlaying][currentAnimationFrame]) {
		currentAnimationFrame++;
		currentFrame = 0;
	}
	if (currentAnimationFrame > animationMaxFrames[animationPlaying]) {
		currentAnimationFrame = 0;
		isAnimationPlaying = false;
		directionLock = false;
		moveLock = false;
		moveSpeed = 3;
	}

}

void Player::StickProcess(int directionX, int directionY)
{
	if (directionX != 0 && directionY != 0) {
		if (!directionLock) {
			this->directionX = directionX;
			this->directionY = directionY;
		}
		if (!moveLock) {
			SetMove();
		}
	}
	else
		Stay();
}

void Player::SetMove()
{
	float ratio = moveSpeed / sqrtf(directionX * directionX + directionY * directionY);
	nextPositionX = positionX + directionX * ratio ;
	nextPositionY = positionY + directionY * ratio;
	if (nextPositionX > 1280) nextPositionX = 1280;
	if (nextPositionY > 640) nextPositionY = 640;
	if (nextPositionX < 0) nextPositionX = 0;
	if (nextPositionY < 0) nextPositionY = 0;
}

void Player::FireProcess(FireStatus fireStatus)
{
	if (fireStatus == pressed){
		if (!tumbleLock) {
			if (tumbleSwitch){
				tumbleSwitch = false;
				directionLock = true;
				moveLock = false;
				atkLock = true;
				moveSpeed = 5;
				isAnimationPlaying = tumble;
				currentAnimationFrame = 1;
				currentFrame = 0;
			}
			else tumbleSwitch = !tumbleSwitch;
		}
		if (!atkLock) {
			directionLock = true;
			moveLock = true;
			atkLock = true;
			animationPlaying = hold;
			isAnimationPlaying = true;
			currentAnimationFrame = 1;
			currentFrame = 0;
			return;
		}
	}
	else if (fireStatus == released) {
		if (!atkLock) {
			directionLock = true;
			moveLock = true;
			atkLock = true;
			tumbleLock = true;
			animationPlaying = atk;
			isAnimationPlaying = true;
			currentAnimationFrame = 1;
			currentFrame = 0;
			return;
		}
		else
			return;
	}
}

void Player::Update(int directionX, int directionY, FireStatus fireStatus )
{
	this->fireStatus = fireStatus;
	StickProcess(directionX, directionY);
	FireProcess(fireStatus);
	AnimationProcess();
}