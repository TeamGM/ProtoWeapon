#pragma once
#include "cocos2d.h"
class FieldManager {
public:
	FieldManager();
	~FieldManager();
	void Update();
private:
	int startPositionX;
	int startPositionY;
};