#include "LevelsScene.h"
#include "CharactersScene.h"

LevelsScene::LevelsScene(int season)
{
	_Season = season;
}

LevelsScene::~LevelsScene()
{
}

Scene* LevelsScene::create(int season)
{
	Scene*_Scene = Scene::create();
	LevelsScene* _LevelSelectedScene = new LevelsScene(season);
	_LevelSelectedScene->init();
	_LevelSelectedScene->autorelease();
	_Scene->addChild(_LevelSelectedScene);
	return _Scene;
}

bool LevelsScene::init()
{
	//initialize layer
	if (!Layer::init())
	{
		return false;
	}
	/*
	Sprite* _Background = Sprite::create(LINK_MAINMENU_BACKGROUND);
	_Background->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT/ 2);

	Vector<MenuItem*> _MenuItems;

	MenuItem* _ButtonBack = MenuItemImage::create(LINK_COMMON_BUTTON_BACK_UP, LINK_COMMON_BUTTON_BACK_DOWN, this,
		menu_selector(LevelsScene::pressBackButton));
	_ButtonBack->setPosition(-200, 240);
	_ButtonBack->setTag(-1);

	for (int i = 0; i < 15; i++)
	{
		MenuItem* _ButtonSeason = MenuItemImage::create(LINK_COMMON_BUTTON_UNLOCKED_LEVEL_UP, LINK_COMMON_BUTTON_UNLOCKED_LEVEL_DOWN, this,
			menu_selector(LevelsScene::pressLevelButton));
		_ButtonSeason->setPosition((i % 3) * 200 - 140, (3 - (i / 3)) * 230 - 250);
		_ButtonSeason->setScale(1.6);
		_ButtonSeason->setTag(i);
		_MenuItems.pushBack(_ButtonSeason);
	}

	cocos2d::Menu* _Menu = cocos2d::Menu::createWithArray(_MenuItems);
	_Menu->setPosition(294, SCREEN_HEIGHT / 2);
	this->addChild(_Background);
	this->addChild(_Menu);
	*/
}

void LevelsScene::pressLockButton(Ref* pSender)
{
}

void LevelsScene::pressLevelButton(Ref* pSender)
{
	MenuItemImage* itemmenu = (MenuItemImage*)pSender;
	auto playscene =  GamePlayScene::create();
	auto transition = TransitionFade::create(0.5f, playscene);
	Director::getInstance()->replaceScene(transition);
}

void LevelsScene::pressBackButton(Ref* pSender)
{
	Scene * scene = CharactersScene::createScene();
	auto transition = TransitionProgressOutIn::create(0.25f, scene);
	Director::getInstance()->replaceScene(transition);
}