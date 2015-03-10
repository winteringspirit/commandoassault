#ifndef __SEASONS_SCENE_H__
#define __SEASONS_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class CharactersScene : public Layer
{
private:
	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	void pressCharactersButton(Ref* pSender);
	void pressBackButton(Ref* pSender);

	Sprite* _Background;

public:
	//Constructor
	CharactersScene();
	//Destructor
	~CharactersScene();

	static Scene* createScene();
	void update(float delta);

	CREATE_FUNC(CharactersScene);
};

#endif