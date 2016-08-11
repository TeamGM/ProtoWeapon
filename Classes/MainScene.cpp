#include "MainScene.h"

USING_NS_CC;

Scene* MainScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layBackGround = BackGroundLayer::create();
	auto layMainUI = MainUILayer::create();

	// add layer as a child to scene
	scene->addChild(layBackGround);
	scene->addChild(layMainUI);

	// return the scene
	return scene;
}

void MainScene::loopMainScene(float dt)
{
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

void MainScene::doTitleOn()
{
	statMainScene = titleOn;	//enum 0
}

void MainScene::doPcSelectOn()
{
	statMainScene = pcSelectOn;	//enum 1
}
void MainScene::doBossSelectOn()
{
	statMainScene = bossSelectOn; //enum 2
}
