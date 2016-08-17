#pragma once
class Monster {
public:
	Monster();
	~Monster();
	void Update();
private:
	float HP;
	int positionX;
	int positionY;
	int nextPositionX;
	int nextPositionY;
};