#include "AppDelegate.h"
#include "cocos2d.h"
#include "Globals.h"
#include "MainmenuScene.h"
#include "GamePlayScene.h"

USING_NS_CC;
AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview)
    {
		glview = GLViewImpl::create("Helicopter Force");
        director->setOpenGLView(glview);
		glview->setFrameSize(600, 450);
    }
	//add search path
	FileUtils::getInstance()->addSearchPath("sounds");
	FileUtils::getInstance()->addSearchPath("musics");
	FileUtils::getInstance()->addSearchPath("spines");
	FileUtils::getInstance()->addSearchPath("sprites");
	FileUtils::getInstance()->addSearchPath("fonts");
	FileUtils::getInstance()->addSearchPath("maps");
	FileUtils::getInstance()->addSearchPath("particles");

	glview->setDesignResolutionSize(SCREEN_WIDTH, SCREEN_HEIGHT, ResolutionPolicy::EXACT_FIT);
	director->setDisplayStats(true);

    // create a scene. it's an autorelease object
	auto scene = GamePlayScene::create();
	//auto scene = MainMenuScene::createScene();
	TransitionFade* transition = TransitionFade::create(0.5f, scene);
	director->runWithScene(transition);
    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    //SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    //SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
