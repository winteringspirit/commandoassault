#include "MainMenuScene.h"
#include "Links.h"
#include "Globals.h"
#include "CharactersScene.h"
#include "AnimatedSprite.h"
#include "GamePlayScene.h"

MainMenuScene::MainMenuScene()
{

}

MainMenuScene::~MainMenuScene()
{
}

Scene* MainMenuScene::createScene()
{
	Scene* scene = Scene::create();
	MainMenuScene* mainMenuLayer = MainMenuScene::create();
	scene->addChild(mainMenuLayer);
	return scene;
}

bool MainMenuScene::init()
{
	//initialize layer
	if (!Layer::init())
	{
		return false;
	}
	Sprite* background = Sprite::create(LINK_MAINMENU_BACKGROUND);
	background->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	
	AnimatedSprite* oldFilmEffect = AnimatedSprite::create(LINK_OLDFILM_EFFECT,1, 5);
	oldFilmEffect->animate(0.1, { 0, 1, 2, 3, 4 });
	oldFilmEffect->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

	cocos2d::MenuItem* _ButtonStart = cocos2d::MenuItemImage::create(LINK_MAINMENU_BUTTON_START_UP, LINK_MAINMENU_BUTTON_START_DOWN, this,
		menu_selector(MainMenuScene::pressStartButton));
	_ButtonStart->setPosition(0,0);

	cocos2d::MenuItem* _ButtonContinue = cocos2d::MenuItemImage::create(LINK_MAINMENU_BUTTON_CONTINUE_UP, LINK_MAINMENU_BUTTON_CONTINUE_DOWN, this,
		menu_selector(MainMenuScene::pressContinueButton));
	_ButtonContinue->setPosition(-130, -50);

	cocos2d::MenuItem* _ButtonHelp = cocos2d::MenuItemImage::create(LINK_MAINMENU_BUTTON_HELP_UP, LINK_MAINMENU_BUTTON_HELP_DOWN, this,
		menu_selector(MainMenuScene::pressHelpButton));
	_ButtonHelp->setPosition(130, -50);

	cocos2d::MenuItem* _ButtonOption = cocos2d::MenuItemImage::create(LINK_MAINMENU_BUTTON_OPTION_UP, LINK_MAINMENU_BUTTON_OPTION_DOWN, this,
		menu_selector(MainMenuScene::pressOptionButton));
	_ButtonOption->setPosition(110,-100);

	cocos2d::MenuItem* _ButtonHighScore = cocos2d::MenuItemImage::create(LINK_MAINMENU_BUTTON_HIGHSCORE_UP, LINK_MAINMENU_BUTTON_HIGHSCORE_DOWN, this,
		menu_selector(MainMenuScene::pressHighscoreButton));
	_ButtonHighScore->setPosition(-110, -100);

	cocos2d::Menu* _Menu = cocos2d::Menu::create(_ButtonStart, _ButtonContinue, _ButtonHelp, _ButtonOption, _ButtonHighScore, NULL);
	_Menu->setPositionY(SCREEN_HEIGHT / 2 - 50);
	this->addChild(background);
	this->addChild(oldFilmEffect);
	this->addChild(_Menu);

	return true;
}

void MainMenuScene::pressStartButton(Ref* pSender)
{
	Scene * scene = GamePlayScene::create();
	TransitionFade* transition = TransitionFade::create(0.5f, scene);
	Director::getInstance()->replaceScene(transition);
}

void MainMenuScene::pressContinueButton(Ref* pSender)
{
}

void MainMenuScene::pressHelpButton(Ref* pSender)
{
}

void MainMenuScene::pressOptionButton(Ref* pSender)
{
}

void MainMenuScene::pressHighscoreButton(Ref* pSender)
{
}

void MainMenuScene::pressExitButton(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	exit(0);
#else
	CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
#endif
}
