#pragma once

#include "cocos2d.h"
#include "TypeGameData.h"
#include "GameManager.h"

USING_NS_CC;

class ResultUILayer : public cocos2d::Layer
{
public:
	virtual bool init();

	CREATE_FUNC(ResultUILayer);

	void initResultUI();

	//get ��Ʋ���������

	void resultEnd(Ref* pSender);
};