#include "MainScene.h"
#include "TitleLayer.h"
#include "BackGroundLayer.h"

USING_NS_CC;

Scene* MainScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layBackGround = BackGroundLayer::create();
	auto layTitle = TitleLayer::create();

	// add layer as a child to scene
	scene->addChild(layBackGround);
	scene->addChild(layTitle);

	// return the scene
	return scene;
}

void MainScene::loopMainScene(float dt)
{
	//
}

bool MainScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	this->schedule(schedule_selector(MainScene::loopMainScene), 1.0);

	return true;
}
