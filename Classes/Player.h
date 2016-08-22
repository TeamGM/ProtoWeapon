#pragma once
#include "cocos2d.h"
#include "PlayerState.h"
class Player {
public:
	Player();
	~Player();
	enum FireStatus 
	{
		none = 0,
		pressed,
		released,
		holding
	};
	PlayerState GetPlayerState();
	void Update(int directionX, int directionY, int fireStatus );
	
	void Move();
	void Stay();
	int GetPositionX();
	int GetPositionY();
private:
	void Init();
	void InitAnimations();
	void AnimationProcess();
	void ClearAnimation();
	void StickProcess(int directionX, int directionY);
	void SetMove();
	void StartTumbleAnimation();
	void StartHoldAnimation();
	void StartATKAnimation();
	void FireProcess();

	float HP;
	int positionX;
	int positionY;
	int moveSpeed;
	int directionX;
	int directionY;
	int nextPositionX;
	int nextPositionY;
	bool directionLock;
	bool moveLock;
	bool tumbleLock;
	bool isHolding;
	
	bool atkLock;
	bool isAnimationPlaying;
	bool tumbleSwitch;
	int tumbleSwitchFrame;
	int fireStatus;
	PlayerState animationPlaying;
	int currentFrame;
	int currentAnimationFrame;
	
	int animationMaxFrames[50];
	int animationFrameDelays[50][50];
};