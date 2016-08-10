#include "MainScene.h"

USING_NS_CC;

Scene* MainScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = MainScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

bool MainScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	return true;
}