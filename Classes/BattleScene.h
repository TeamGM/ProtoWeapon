#ifndef __BATTLE_SCENE_H__
#define __BATTLE_SCENE_H__

#include "cocos2d.h"

class BattleScene : public cocos2d::LayerColor
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(BattleScene);

	void batlleEnd(Ref* pSender);
};

#endif // __BATTLE_SCNEN_H__