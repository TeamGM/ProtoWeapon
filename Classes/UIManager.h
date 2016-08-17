#pragma once
#include "UIStick.h"
#include "UIFire.h"
class UIManager {
public:
	UIManager();
	~UIManager();
	void Update();
	UIStick * GetUIStick();
	UIFire * GetUIFire();
private:
	void init();
	UIStick * stick;
	UIFire * fire;
};