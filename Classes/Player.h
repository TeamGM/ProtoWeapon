#pragma once
class Player {
public:
	Player();
	~Player();
	void Update();
private:
	float HP;
	int positionX;
	int positionY;
	int nextPositionX;
	int nextPositionY;
};