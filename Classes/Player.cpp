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
	isHolding = false;
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
	if (!isAnimationPlaying) return;
	currentFrame++;
//	cocos2d::log("%d animation currentAnimationframe : %d current frame : %d, tumbleSwitch = %d, tumbleFrame = %d",animationPlaying,currentAnimationFrame,currentFrame,tumbleSwitch,tumbleSwitchFrame);
	if (currentAnimationFrame<=animationMaxFrames[animationPlaying] && currentFrame > animationFrameDelays[animationPlaying][currentAnimationFrame]) {
		currentAnimationFrame++;
		currentFrame = 0;
	}
	if (animationPlaying == tumble) {
		if (currentFrame < 25 && currentFrame>5)moveSpeed = 5;
		else moveSpeed = 3;
	}
	if (currentAnimationFrame > animationMaxFrames[animationPlaying]) {
		if (animationPlaying == hold) {
			atkLock = false;
			if (currentFrame > 60) fireStatus=released;
			return;
		}
		currentAnimationFrame = 0;
		animationPlaying = nothing;
		isAnimationPlaying = false;
		directionLock = false;
		moveLock = false;
		atkLock = false;
		tumbleLock = false;
		moveSpeed = 3;
	}
	if (tumbleSwitch && currentFrame < tumbleSwitchFrame || (tumbleSwitchFrame + 15 < currentFrame))
		tumbleSwitch = false;
}

void Player::StickProcess(int directionX, int directionY)
{
	if (directionX != 0 || directionY != 0) {
		if (!directionLock) {
			this->directionX = directionX;
			this->directionY = directionY;
		}
		if (!moveLock) {
			SetMove();
		}
		else
			Stay();
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
void Player::StartTumbleAnimation() {
	tumbleSwitch = false;
	directionLock = true;
	moveLock = false;
	atkLock = true;
	animationPlaying = tumble;
	isAnimationPlaying = true;
	currentAnimationFrame = 1;
	currentFrame = 0;
	cocos2d::log("Tumble animation start");
} 
void Player::StartHoldAnimation()
{
	directionLock = true;
	moveLock = true;
	atkLock = true;
	animationPlaying = hold;
	isAnimationPlaying = true;
	currentAnimationFrame = 1;
	currentFrame = 0;
	cocos2d::log("Hold animation start");
}
void Player::StartATKAnimation()
{
	directionLock = true;
	moveLock = true;
	atkLock = true;
	tumbleLock = true;
	animationPlaying = atk;
	isAnimationPlaying = true;
	currentAnimationFrame = 1;
	currentFrame = 0;
	cocos2d::log("ATK animation start");
	fireStatus = none;
}
void Player::FireProcess()
{
	if (fireStatus == pressed){
		if (!tumbleLock && !isHolding) {
			if (tumbleSwitch){
				StartTumbleAnimation();
			}
			else {
				tumbleSwitch = true;
				tumbleSwitchFrame = currentFrame;
			}
		}
		if (!atkLock)
			StartHoldAnimation();
		isHolding = true;
	}
	else if (fireStatus == released) {
		//cocos2d::log("fire released");
		if (!atkLock && animationPlaying==hold) {
			StartATKAnimation();
		}
		else if(animationPlaying==tumble)
			fireStatus=none;
		isHolding = false;
	}
}

void Player::Update(int directionX, int directionY, int fireStatus )
{
	if(fireStatus!=0) 
		this->fireStatus = fireStatus;
	StickProcess(directionX, directionY);
	FireProcess();
	AnimationProcess();
}