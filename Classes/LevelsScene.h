#ifndef __LEVEL_SELECTED_SCENE_H__
#define __LEVEL_SELECTED_SCENE_H__

#include "cocos2d.h"
#include "Globals.h"
#include "GamePlayScene.h"
#include "CharactersScene.h"

USING_NS_CC;

class LevelsScene :public Layer
{
private:
	int _Season;

	void pressLevelButton(Ref* pSender);
	void pressBackButton(Ref* pSender);
	void pressLockButton(Ref* pSender);

public:
	//Constructor
	LevelsScene(int season);
	//Destructor
	~LevelsScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	static Scene* create(int season);
};

#endif