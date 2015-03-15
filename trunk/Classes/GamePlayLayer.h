#ifndef __GAME_PLAY_LAYER__
#define __GAME_PLAY_LAYER__

#include "cocos2d.h"
#include "Globals.h"
#include "AnimatedSprite.h"
#include "FileOperation.h"
#include "Rexx.h"

#define GAME_STATUS_WAITING 0
#define GAME_STATUS_RUNNING 2

class GamePlayLayer : public Layer
{
private:
	//store list key press
	std::vector<EventKeyboard::KeyCode> heldKeys;
public:
	//Constructor 
	GamePlayLayer( );
	//Destructor
	~GamePlayLayer( );

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init( );

	//load map file
	void loadFile( );

	//update this scene
	void update( float delta);

	//Touch event
	void onTouchesBegan( const std::vector<Touch*>& touches, Event  *event);
	void onTouchesMoved( const std::vector<Touch*>& touches, Event  *event);
	void onTouchesEnded( const std::vector<Touch*>& touches, Event  *event);
	void onTouchesCancelled( const std::vector<Touch*>& touches, cocos2d::Event  *event);

	//Keyboard event
	void onKeyHold( float delta);
	void keyPressed( EventKeyboard::KeyCode keyCode, Event *event);
	void keyReleased( EventKeyboard::KeyCode keyCode, Event *event);

	//Physics event
	bool onContactBegin( PhysicsContact& contact);
	bool onContactPreSolve( PhysicsContact& contact, PhysicsContactPreSolve &preSolve );
	void onContactPostSolve( PhysicsContact& contact, const PhysicsContactPostSolve &postSolve);
	void onContactSeperate( PhysicsContact& contact);

	//mouse event
	void onMouseDown(Event *event);
	void onMouseUp(Event *event);
	void onMouseMove( Event *event);
	void onMouseScroll( Event *event);

	CC_SYNTHESIZE( int, _gameStatus, _GameStatus);
	CC_SYNTHESIZE( PhysicsWorld*, _World, World);
	CC_SYNTHESIZE_READONLY( Size, _visibleSize, VisibleSize);
	CC_SYNTHESIZE( Rexx*, _player, Player);

	CREATE_FUNC( GamePlayLayer);

	// a selector callback
	void menuCloseCallback( cocos2d::Ref* pSender);
};

#endif // __HELLOWORLD_SCENE_H__