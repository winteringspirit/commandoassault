#ifndef __GAME_PLAY_LAYER__
#define __GAME_PLAY_LAYER__

#include "cocos2d.h"
#include "Globals.h"
#include "AnimatedSprite.h"
#include "PlistAnimatedSprite.h"
#include "FileOperation.h"

#define GAME_STATUS_WAITING 0
#define GAME_STATUS_RUNNING 2

class GamePlayLayer : public Layer
{
private:
	Size visibleSize;
	//store list key press
	std::vector<EventKeyboard::KeyCode> heldKeys;
	//physics world
	PhysicsWorld* _World;
	Node *n;
public:
	//Constructor 
	GamePlayLayer();
	//Destructor
	~GamePlayLayer();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

	//load map file
	void loadFile();

	//update this scene
	void update(float delta);
	//Touch event
	void onTouchesBegan(const std::vector<Touch*>& touches, cocos2d::Event  *event);
	void onTouchesMoved(const std::vector<Touch*>& touches, cocos2d::Event  *event);
	void onTouchesEnded(const std::vector<Touch*>& touches, cocos2d::Event  *event);
	void onTouchesCancelled(const std::vector<Touch*>& touches, cocos2d::Event  *event);

	//Keyboard event
	void onKeyHold(float interval);
	void keyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);
	void keyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);

	//collect contact
	bool onContactBegin(PhysicsContact& contact);
	void onContactSeperate(PhysicsContact& contact);

	void setPhyWorld(PhysicsWorld* world){ _World = world; }
	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);

	CC_SYNTHESIZE(int, _gameStatus, _GameStatus);

	CREATE_FUNC(GamePlayLayer);
};

#endif // __HELLOWORLD_SCENE_H__