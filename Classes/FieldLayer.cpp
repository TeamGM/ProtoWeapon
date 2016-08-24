#include "FieldLayer.h"
USING_NS_CC;
FieldLayer::FieldLayer()
{
}
FieldLayer::~FieldLayer()
{
}
bool FieldLayer::init(){
	if (!Layer::init())
	{
		return false;
	}

	map = Sprite::create("img/field.png");
	map->setPosition(Vec2(0, 0));
	map->setAnchorPoint(Vec2(0, 0));
	
	this->addChild(map, 0);

	characterLayer = CharacterLayer::create();
	this->addChild(characterLayer, 0);

	return true;
}

void FieldLayer::Draw(FieldManager * fieldManager)
{
	characterLayer->Draw(fieldManager->GetPlayer(), fieldManager->GetMonster());
	this->runAction(Follow::create(this->characterLayer->GetPlayer(), Rect(0, 0, 1280, 720)));
}
