#include "MainScene.h"


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

	CocosDenshion::SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(0.3f);
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("soundBG/Neo_Space.mp3");

	// return the scene
	return scene;
}

bool MainScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	CocosDenshion::SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(0.3f);
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("soundBG/Neo_Space.mp3");
	//this->schedule(schedule_selector(MainScene::loopMainScene), 1.0);

	return true;
}

void MainScene::loadSprites()
{
	/*plist ���� �ۼ��� �ٽ� �õ�*/

	//��渮�ҽ� �ε�
	//auto sprTemp = Sprite::create("HelloWorld.png");
	//auto frameTemp = sprTemp->getSpriteFrame();
	//SpriteFrameCache::getInstance()->addSpriteFrame(frameTemp, "mainsceneBG");

	//����ĳ���͸��ҽ� �ε�
	//SpriteFrameCache::getInstance()->addSpriteFrame(Sprite::create("img/behimoth.png")->getDisplayFrame(), "behimoth");
	//SpriteFrameCache::getInstance()->addSpriteFrame(Sprite::create("img/Leviathan.png")->getDisplayFrame(), "Leviathan");
	//SpriteFrameCache::getInstance()->addSpriteFrame(Sprite::create("img/radragon.png")->getDisplayFrame(), "radragon");

	//�ӽ�
	//SpriteFrameCache::getInstance()->addSpriteFrame(Sprite::create("img/tree.png")->getDisplayFrame(), "tree");
	//SpriteFrameCache::getInstance()->addSpriteFrame(Sprite::create("img/swordmanStand.png")->getDisplayFrame(), "swordmanStand");

	//UI���ҽ� �ε�
	//SpriteFrameCache::getInstance()->addSpriteFrame(Sprite::create("img/CharacterSelectBoard.png")->getDisplayFrame(), "CharacterSelectBoard");
	//SpriteFrameCache::getInstance()->addSpriteFrame(Sprite::create("img/okbutton.png")->getDisplayFrame(), "okButton");
	//SpriteFrameCache::getInstance()->addSpriteFrame(Sprite::create("img/selectCharacter_Logo.png")->getDisplayFrame(), "selectCharacter_Logo");
	//SpriteFrameCache::getInstance()->addSpriteFrame(Sprite::create("img/selectedFrame.png")->getDisplayFrame(), "selectedFrame");
	//SpriteFrameCache::getInstance()->addSpriteFrame(Sprite::create("img/selectMonster_Logo.png")->getDisplayFrame(), "selectMonster_Logo");
	//SpriteFrameCache::getInstance()->addSpriteFrame(Sprite::create("img/selectMonsterFrame.png")->getDisplayFrame(), "selectMonsterFrame");
	//SpriteFrameCache::getInstance()->addSpriteFrame(Sprite::create("img/TabToStart.png")->getDisplayFrame(), "TabToStart");
	//SpriteFrameCache::getInstance()->addSpriteFrame(Sprite::create("img/titleLogo.png")->getDisplayFrame(), "titleLogo");

	
}