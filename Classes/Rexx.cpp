#include "Rexx.h"
#include "Gun0.h"

#define REXX_PHYSICS_BODY_WIDTH			25
#define REXX_PHYSICS_BODY_HEIGHT		60
#define REXX_PHYSICS_BODY_DENSITY		0.0f
#define REXX_PHYSICS_BODY_RESTITUTION	0.0f
#define REXX_PHYSICS_BODY_FRICTION		0.0f

bool Rexx::init()
{
	//create body and foot
	_rexxFoot = RexxFoot::create();
	_rexxBody = RexxBody::create();
	_rexxWeapon = Gun0::create();
	this->addChild(_rexxFoot);
	this->addChild(_rexxBody);
	this->addChild(_rexxWeapon);

	//create custom physics body
	auto physicsBody = PhysicsBody::createBox(Size(REXX_PHYSICS_BODY_WIDTH, REXX_PHYSICS_BODY_HEIGHT),
		PhysicsMaterial( 0, 0, 0));
	physicsBody->setMass(0);
	physicsBody->setDynamic(true);
	this->setPhysicsBody(physicsBody);

	return true;
}

void Rexx::setMovingSpeed(float speed)
{
	_rexxFoot->setMovingSpeed(speed);
}

void Rexx::setAim(Vec2 aim)
{
	_rexxBody->setAim(aim);
	_rexxWeapon->setAim(aim);
}

void Rexx::moveLeft()
{
	_rexxFoot->moveLeft();
}

void Rexx::crouch()
{
	_rexxFoot->crouch();
}

void Rexx::jump()
{
	_rexxFoot->jump();
}

void Rexx::stand()
{
	_rexxFoot->stand();
}

void Rexx::moveRight()
{
	_rexxFoot->moveRight();
}

void Rexx::fire()
{
}