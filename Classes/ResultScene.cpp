#include "ResultScene.h"

USING_NS_CC;

Scene* ResultScene::createScene()
{
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layResultBG = ResultBGLayer::create();
	auto layResultUI = ResultUILayer::create();

	// add layer as a child to scene
	scene->addChild(layResultBG);
	scene->addChild(layResultUI);

	return scene;
}

bool ResultScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	return true;
}