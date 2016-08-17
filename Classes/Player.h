#pragma once
class Player {
public:
	Player();
	~Player();
	void Init();
	void Update( int directionX, int directionY );
	void Move();
	void Stay();
	int GetPositionX();
	int GetPositionY();
private:
	float HP;
	int positionX;
	int positionY;
	int moveSpeed;
	int directionX;
	int directionY;
	int nextPositionX;
	int nextPositionY;
};