#include "MainScene.h"
#include "TitleLayer.h"

USING_NS_CC;

Scene* MainScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = TitleLayer::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

bool MainScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	return true;
}
