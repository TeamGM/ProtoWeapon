#pragma once
class Player {
public:
	Player();
	~Player();
	enum FireStatus 
	{
		none = 0,
		pressed,
		released
	};
	enum AnimationPlaying {
		nothing=0,
		hold,
		atk,
		tumble,
		damaged
	};
	void Update(int directionX, int directionY, FireStatus fireStatus );
	
	void Move();
	void Stay();
	int GetPositionX();
	int GetPositionY();
private:
	void Init();
	void InitAnimations();
	void AnimationProcess();
	void StickProcess(int directionX, int directionY);
	void SetMove();
	void FireProcess(FireStatus fireStatus);

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
	bool atkLock;
	bool isAnimationPlaying;
	bool tumbleSwitch;
	FireStatus fireStatus;
	AnimationPlaying animationPlaying;
	int currentFrame;
	int currentAnimationFrame;
	
	int animationMaxFrames[50];
	int animationFrameDelays[50][50];
};