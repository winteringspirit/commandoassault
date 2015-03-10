#include "CharactersScene.h"
#include "LevelsScene.h"
#include "MainMenuScene.h"
#include "Globals.h"

CharactersScene::CharactersScene()
{
}

CharactersScene::~CharactersScene()
{
}

Scene* CharactersScene::createScene()
{
	Scene* _Scene = Scene::create();
	CharactersScene* selectseasonlayer = CharactersScene::create();
	_Scene->addChild(selectseasonlayer);
	return _Scene;
}

bool CharactersScene::init()
{
	//initialize layer
	if (!Layer::init())
	{
		return false;
	}
	const Texture2D::TexParams tp = { GL_LINEAR, GL_LINEAR, GL_REPEAT, GL_REPEAT };
	/*
	_Background = Sprite::create(LINK_WORLD_MAP_BACKGROUND);
	_Background->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	this->addChild(_Background);

	MenuItem* _ButtonBack = MenuItemImage::create(LINK_COMMON_BUTTON_BACK_UP, LINK_COMMON_BUTTON_BACK_DOWN, this,
		menu_selector(CharactersScene::pressBackButton));
	_ButtonBack->setScale(1.8);
	cocos2d::Menu* _OptionMenu = cocos2d::Menu::createWithItem(_ButtonBack);
	_OptionMenu->setPosition(120, 1200);
	this->addChild(_OptionMenu);

	MenuItem* _ButtonChapter1 = MenuItemImage::create(LINK_CHAPTER_BUTTON_1, LINK_CHAPTER_BUTTON_1, this,
		menu_selector(CharactersScene::pressChapterButton));
	cocos2d::Menu* _MenuChapter = cocos2d::Menu::createWithItem(_ButtonChapter1);
	this->addChild(_MenuChapter);
	*/
	return true;
}

void CharactersScene::pressCharactersButton(Ref* pSender)
{
	MenuItemImage* itemmenu = (MenuItemImage*)pSender;
	Scene* _LevelSelectedScene = LevelsScene::create(itemmenu->getTag());
	Director::getInstance()->replaceScene(_LevelSelectedScene);
}

void CharactersScene::pressBackButton(Ref* pSender)
{
	Scene* scene = MainMenuScene::createScene();
	auto transition = TransitionFade::create(0.5f, scene);
	Director::getInstance()->replaceScene(transition);
}


void CharactersScene::update(float delta)
{
	if (_Background->getPositionX() > 290)
		_Background->setPositionX(_Background->getPositionX() - 0.07);
}