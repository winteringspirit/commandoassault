#include "GamePlayLayer.h"
USING_NS_CC;

GamePlayLayer::GamePlayLayer()
{

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	{
		//register keyboard listener
		auto keyboardListener				= EventListenerKeyboard::create();
		keyboardListener->onKeyPressed		= CC_CALLBACK_2(GamePlayLayer::keyPressed, this);
		keyboardListener->onKeyReleased		= CC_CALLBACK_2(GamePlayLayer::keyReleased, this);
		_eventDispatcher->addEventListenerWithSceneGraphPriority(keyboardListener, this);

		//register mouse listener
		auto mouseListener				= EventListenerMouse::create();
		mouseListener->onMouseDown		= CC_CALLBACK_1(GamePlayLayer::onMouseDown, this);
		mouseListener->onMouseUp		= CC_CALLBACK_1(GamePlayLayer::onMouseUp, this);
		mouseListener->onMouseMove		= CC_CALLBACK_1(GamePlayLayer::onMouseMove, this);
		mouseListener->onMouseScroll	= CC_CALLBACK_1(GamePlayLayer::onMouseScroll, this);
		_eventDispatcher->addEventListenerWithSceneGraphPriority(mouseListener, this);
	}
#else
	//register touchlistener
	auto touchlistener					= EventListenerTouchAllAtOnce::create();
	touchlistener->onTouchesBegan		= CC_CALLBACK_2(GamePlayLayer::onTouchesBegan, this);
	touchlistener->onTouchesMoved		= CC_CALLBACK_2(GamePlayLayer::onTouchesMoved, this);
	touchlistener->onTouchesEnded		= CC_CALLBACK_2(GamePlayLayer::onTouchesEnded, this);
	touchlistener->onTouchesCancelled	= CC_CALLBACK_2(GamePlayLayer::onTouchesCancelled, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchlistener, this);
#endif

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
	_visibleSize = Director::getInstance()->getVisibleSize();

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
			//list object in tiled map editor
		}
	}*/
	
	_player = Rexx::create();
	_player->setPosition(_visibleSize.width / 2, _visibleSize.height-100);
	_player->getPhysicsBody()->setCategoryBitmask(1);    // 0010
	_player->getPhysicsBody()->setCollisionBitmask(2);   // 0001
	_player->getPhysicsBody()->setContactTestBitmask(2);
	_player->getPhysicsBody()->applyImpulse(Vect(0, -100));
	_player->setTag(TAG_OBJECT_PLAYER);
	this->addChild(_player);


	auto ground = Node::create();
	//create custom physics body
	auto physicsBody = PhysicsBody::createBox(Size(800, 50),
		PhysicsMaterial(0, 0, 0));
	physicsBody->setDynamic(false);
	physicsBody->setContactTestBitmask(1);
	ground->setPhysicsBody(physicsBody);
	ground->setPosition(SCREEN_WIDTH / 2, 100);
	ground->getPhysicsBody()->setCategoryBitmask(2);    // 0010
	ground->getPhysicsBody()->setCollisionBitmask(1);   // 0001
	ground->getPhysicsBody()->setContactTestBitmask(1);
	ground->setTag(TAG_OBJECT_GROUND);
	this->addChild(ground);
	

	//register physics contacts listener
	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin		= CC_CALLBACK_1(GamePlayLayer::onContactBegin, this);
	contactListener->onContactPreSolve	= CC_CALLBACK_2(GamePlayLayer::onContactPreSolve, this);
	contactListener->onContactPostSolve = CC_CALLBACK_2(GamePlayLayer::onContactPostSolve, this);
	contactListener->onContactSeperate	= CC_CALLBACK_1(GamePlayLayer::onContactSeperate, this);
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

void GamePlayLayer::onKeyHold(float delta)
{
}

//this function is used for key press
void GamePlayLayer::keyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
{
	if (!Globals::getInstance()->getPause())
	{
		switch (keyCode)
		{
		case EventKeyboard::KeyCode::KEY_A:
			if (std::find(heldKeys.begin(), heldKeys.end(), EventKeyboard::KeyCode::KEY_D) != heldKeys.end())
			{
				_player->moveLeft();
			}
			else
				_player->moveLeft();
			break;
		case EventKeyboard::KeyCode::KEY_D:
			if (std::find(heldKeys.begin(), heldKeys.end(), EventKeyboard::KeyCode::KEY_A) != heldKeys.end())
			{
				_player->moveRight();
			}
			else
				_player->moveRight();
			break;
		case EventKeyboard::KeyCode::KEY_S:
			_player->crouch();
			break;
		case EventKeyboard::KeyCode::KEY_W:
			_player->jump();
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
	case EventKeyboard::KeyCode::KEY_A:
		if (std::find(heldKeys.begin(), heldKeys.end(), EventKeyboard::KeyCode::KEY_D) != heldKeys.end())
		{
			_player->moveRight();
		}
		else
			_player->stand();
		break;
	case EventKeyboard::KeyCode::KEY_D:
		if (std::find(heldKeys.begin(), heldKeys.end(), EventKeyboard::KeyCode::KEY_A) != heldKeys.end())
		{
			_player->moveLeft();
		}
		else
			_player->stand();
		break;
	default:
		break;
	}
	heldKeys.erase(std::remove(heldKeys.begin(), heldKeys.end(), keyCode), heldKeys.end());
}

#pragma endregion

#pragma region Mouse region

void GamePlayLayer::onMouseDown(Event *event)
{
	EventMouse* mouseEvent = dynamic_cast<EventMouse*>(event);
	if (mouseEvent->getMouseButton())
	{
	}
}

void GamePlayLayer::onMouseUp(Event *event)
{
	
}

void GamePlayLayer::onMouseMove(Event *event)
{
	if (!Globals::getInstance()->getPause())
	{
		EventMouse* mouseEvent = dynamic_cast<EventMouse*>(event);
		_player->setAim(mouseEvent->getLocationInView());
	}
}

void GamePlayLayer::onMouseScroll(Event *event)
{
}

#pragma endregion

#pragma region collision and response

bool GamePlayLayer::onContactBegin(PhysicsContact& contact)
{
	auto nodeA = contact.getShapeA()->getBody()->getNode();
	auto nodeB = contact.getShapeB()->getBody()->getNode();
	if (nodeA && nodeB)
	{
		//doing somethings here for object's collision
	}
	//one way collision between Player and ground
	if (nodeA->getTag() == TAG_OBJECT_PLAYER && nodeB->getTag() == TAG_OBJECT_GROUND)
	{
		if (contact.getContactData()->normal.y < 0)
		{
			_player->collidedGrounds.pushBack(nodeB);
			return true;
		}
	}
	else
		if (nodeB->getTag() == TAG_OBJECT_PLAYER && nodeA->getTag() == TAG_OBJECT_GROUND)
		{
		if (contact.getContactData()->normal.y > 0)
		{
			_player->collidedGrounds.pushBack(nodeA);
			return true;
		}
		}

	return false;
}


bool GamePlayLayer::onContactPreSolve(PhysicsContact& contact, PhysicsContactPreSolve &preSolve)
{
	return true;
}

void GamePlayLayer::onContactPostSolve(PhysicsContact& contact, const PhysicsContactPostSolve &postSolve)
{
}

void GamePlayLayer::onContactSeperate(PhysicsContact& contact)
{
	auto nodeA = contact.getShapeA()->getBody()->getNode();
	auto nodeB = contact.getShapeB()->getBody()->getNode();
	//one way collision between Player and ground
	if (nodeA->getTag() == TAG_OBJECT_PLAYER && nodeB->getTag() == TAG_OBJECT_GROUND)
	{
		_player->collidedGrounds.eraseObject(nodeB);
	}
	else
		if (nodeB->getTag() == TAG_OBJECT_PLAYER && nodeA->getTag() == TAG_OBJECT_GROUND)
		{
		_player->collidedGrounds.eraseObject(nodeA);
		}

}

#pragma endregion

void GamePlayLayer::update(float delta)
{
	if (!Globals::getInstance()->getPause())
	{
		this->onKeyHold(delta);
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
	Director::getInstance()->end();
}
