#pragma once
#include "UIStick.h"
#include "UIFire.h"



class UIManager {
public:
	UIManager();
	~UIManager();
	void Update(int bossHPRatio, int playerHPRatio);
	UIStick * GetUIStick();
	UIFire * GetUIFire();
	int GetBossHPRatio();
	int GetPlayerHPRatio();
	struct UIPreset {
		int bossPictureSize;
		int bossPicturePositionX;
		int bossPicturePositionY;
		int bossLifebarSizeX;
		int bossLifebarSizeY;
		int bossLifebarPositionX;
		int bossLifebarPositionY;
		int playerPictureSize;
		int playerPicturePositionX;
		int playerPicturePositionY;
		int playerLifebarSizeX;
		int playerLifebarSizeY;
		int playerLifebarPositionX;
		int playerLifebarPositionY;
	}preset;
private:
	void init();
	int bossHPRatio;
	int playerHPRatio;
	UIStick * stick;
	UIFire * fire;
};