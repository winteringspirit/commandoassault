#include "GamePlayScene.h"

GamePlayScene::GamePlayScene() 
{
}

Scene* GamePlayScene::create()
{
	auto scene = Scene::createWithPhysics();
#if(SET_DEBUG)
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
#else
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_NONE);
#endif
	scene->getPhysicsWorld()->setGravity(Vect(0, -950));
	auto _gamePlayLayer = GamePlayLayer::create();
	_gamePlayLayer->setWorld(scene->getPhysicsWorld());
	scene->addChild(_gamePlayLayer);
	return scene;
}
