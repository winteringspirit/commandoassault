#include "GamePlayLayer.h"
USING_NS_CC;

GamePlayLayer::GamePlayLayer()
{

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	{
		//register keyboard listener
		auto keyboardListener = EventListenerKeyboard::create();
		keyboardListener->onKeyPressed = CC_CALLBACK_2(GamePlayLayer::keyPressed, this);
		keyboardListener->onKeyReleased = CC_CALLBACK_2(GamePlayLayer::keyReleased, this);
		//this function only for cocos 3.1 or later
		_eventDispatcher->addEventListenerWithSceneGraphPriority(keyboardListener, this);
	}
#endif

	//register touchlistener
	auto touchlistener = EventListenerTouchAllAtOnce::create();
	touchlistener->onTouchesBegan = CC_CALLBACK_2(GamePlayLayer::onTouchesBegan, this);
	touchlistener->onTouchesMoved = CC_CALLBACK_2(GamePlayLayer::onTouchesMoved, this);
	touchlistener->onTouchesEnded = CC_CALLBACK_2(GamePlayLayer::onTouchesEnded, this);
	touchlistener->onTouchesCancelled = CC_CALLBACK_2(GamePlayLayer::onTouchesCancelled, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchlistener, this);


	_gameStatus = GAME_STATUS_WAITING;
	scheduleUpdate();
	srand(time(NULL));
}

GamePlayLayer::~GamePlayLayer()
{
}

// on "init" you need to initialize your instance
bool GamePlayLayer::init()
{
	visibleSize = Director::getInstance()->getVisibleSize();

	/*
	 //create a TMX map
	TMXTiledMap* map = TMXTiledMap::create("0.tmx");
	this->addChild(map, -1, -1000);
	Globals::getInstance()->setMapWidth(map->getMapSize().width * map->getTileSize().width);
	Globals::getInstance()->setMapHeight(map->getMapSize().height* map->getTileSize().height);

	for (const auto& child : map->getChildren())
	{
		static_cast<SpriteBatchNode*>(child)->getTexture()->setAntiAliasTexParameters();
	}
	
	// Object layers of tile map
	for (const auto& child : map->getObjectGroups())
	{
		for (const auto& childofchild : child->getObjects())
		{
			//list object in tilemap editor
		}
	}
	*/

	//register physics contacts listener
	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(GamePlayLayer::onContactBegin, this);
	contactListener->onContactSeperate = CC_CALLBACK_1(GamePlayLayer::onContactSeperate, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener,  this);

	return true;
}

void GamePlayLayer::loadFile()
{

}

#pragma region touch region

void GamePlayLayer::onTouchesBegan(const std::vector<Touch*>& touches, cocos2d::Event  *event)
{
	//if game is pause
	if (!Globals::getInstance()->getPause())
	{
		for (auto &item : touches)
		{
			
		}
	}
}

void GamePlayLayer::onTouchesMoved(const std::vector<Touch*>& touches, cocos2d::Event  *event)
{
	if (!Globals::getInstance()->getPause())
	{
		for (auto &item : touches)
		{
			
		}
	}
}

void GamePlayLayer::onTouchesEnded(const std::vector<Touch*>& touches, cocos2d::Event  *event)
{
	for (auto &item : touches)
	{
		
	}
}

void GamePlayLayer::onTouchesCancelled(const std::vector<Touch*>& touches, cocos2d::Event  *event)
{
	for (auto &item : touches)
	{
		
	}
}
#pragma endregion

#pragma region Keyboard region

void GamePlayLayer::onKeyHold(float interval)
{
}

//this function is used for key press
void GamePlayLayer::keyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
{
	if (!Globals::getInstance()->getPause())
	{
		switch (keyCode)
		{
		case EventKeyboard::KeyCode::KEY_UP_ARROW:
			break;
		case EventKeyboard::KeyCode::KEY_SPACE:
			break;
		}

		if (std::find(heldKeys.begin(), heldKeys.end(), keyCode) == heldKeys.end())
		{
			heldKeys.push_back(keyCode);
		}
	}
}

void GamePlayLayer::keyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
{
	switch (keyCode)
	{
	default:
		break;
	}
	heldKeys.erase(std::remove(heldKeys.begin(), heldKeys.end(), keyCode), heldKeys.end());
}

#pragma endregion

#pragma region collision and response

bool GamePlayLayer::onContactBegin(PhysicsContact& contact)
{
	auto nodeA = contact.getShapeA()->getBody()->getNode();
	auto nodeB = contact.getShapeB()->getBody()->getNode();
	bool isFirstCheck = false;
	while (nodeA && nodeB)
	{
		//doing somethings here for object's collision
	}
	return true;
}

void GamePlayLayer::onContactSeperate(PhysicsContact& contact)
{
}

#pragma endregion

void GamePlayLayer::update(float delta)
{
	if (!Globals::getInstance()->getPause())
	{
		//update speed for all kid
		switch (_gameStatus)
		{
		case GAME_STATUS_WAITING:
			//loading game
			break;
		case GAME_STATUS_RUNNING:
			//real game loop here, update camera, update game board,....
			onKeyHold(delta);
			break;
		}
	}
}

//menu call back event
void GamePlayLayer::menuCloseCallback(Ref* pSender)
{
	exit(0);
}
