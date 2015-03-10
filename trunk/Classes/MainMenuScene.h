#ifndef __MAIN_MENU_SCENE_H__
#define __MAIN_MENU_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class MainMenuScene :public Layer
{
private:
	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	void pressStartButton(Ref* pSender);
	void pressContinueButton(Ref* pSender);
	void pressHelpButton(Ref* pSender);
	void pressOptionButton(Ref* pSender);
	void pressHighscoreButton(Ref* pSender);
	void pressExitButton(Ref* pSender);
public:
	MainMenuScene();
	//Destructor
	~MainMenuScene();

	static Scene* createScene();

	CREATE_FUNC(MainMenuScene);
};

#endif