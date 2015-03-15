#include "RexxFoot.h"
#include "Links.h"
#include "Globals.h"
#include "Rexx.h"

bool RexxFoot::init()
{
	AnimatedSprite::init(LINK_REXX_FOOT, 19, 1);
	this->_movingSpeed		= 180;
	this->_jumpForce		= 480;
	this->_isJumping		= false;
	this->_jumpTimes		= 1;
	this->setPosition(3, -20);
	this->scheduleUpdate();
	return true;
}

float RexxFoot::getMovingAnimationDelay()
{
	return 10 / _movingSpeed;
}

void RexxFoot::stand()
{
	this->getParent()->stopActionByTag( TAG_ACTION_MOVING);
	this->_movingDirection = MOVING_DIRECTION_NO;
	if (!_isJumping)
	{
		this->setFrame(0);
	}
}

void RexxFoot::moveLeft()
{
	//if (_movingDirection != MOVING_DIRECTION_LEFT)
	{
		this->getParent()->stopActionByTag(TAG_ACTION_MOVING);
		auto movingAction = RepeatForever::create(MoveBy::create(1, Vec2(-_movingSpeed, 0)));
		movingAction->setTag(TAG_ACTION_MOVING);
		this->getParent()->runAction(movingAction);
		this->_movingDirection = MOVING_DIRECTION_LEFT;

		this->setFlipX(false);
		if (!_isJumping)
		{
			this->animate(this->getMovingAnimationDelay(), { 1, 2, 3, 4, 5, 6, 7, 8 });
		}
	}
}

void RexxFoot::moveRight()
{
	//if (_movingDirection != MOVING_DIRECTION_RIGHT)
	{
		this->getParent()->stopActionByTag(TAG_ACTION_MOVING);
		auto movingAction = RepeatForever::create(MoveBy::create(1, Vec2(_movingSpeed, 0)));
		movingAction->setTag(TAG_ACTION_MOVING);
		this->getParent()->runAction(movingAction);
		this->_movingDirection = MOVING_DIRECTION_RIGHT;

		this->setFlipX(true);
		if (!_isJumping)
		{
			
			this->animate(this->getMovingAnimationDelay(), { 1, 2, 3, 4, 5, 6, 7, 8 });
		}
	}
}

void RexxFoot::jump()
{
	//set jump force
	this->getParent()->getPhysicsBody()->setVelocity( Vec2(0, _jumpForce));
}

void RexxFoot::crouch()
{
	//play crouch animation
	this->animate( 0.1, { 14, 15, 16, 17, 18 }, 1);
}

void RexxFoot::update(float delta)
{
	int totalCollidedGround = (( Rexx*)this->getParent())->collidedGrounds.size();

	//if rexx is on land
	if ( totalCollidedGround > 0 && _isJumping)
	{
		_isJumping = false;
		//check current direction for play animation
		if ( _movingDirection == MOVING_DIRECTION_LEFT)
		{
			this->setFlipX( false);
			this->animate( this->getMovingAnimationDelay(), { 1, 2, 3, 4, 5, 6, 7, 8 });
		}
		else
			if (_movingDirection == MOVING_DIRECTION_RIGHT)
			{
				this->setFlipX( true);
				this->animate( this->getMovingAnimationDelay(), { 1, 2, 3, 4, 5, 6, 7, 8 });
			}
		//if rexx is stand
			else
			{
				this->setFrame( 0 );
			}
	}
	else
		//if rexx is on air
		if ( totalCollidedGround == 0 && !_isJumping)
	{
		_isJumping = true;
		//play jump animation
		this->animate( 0.17, { 9, 10, 11, 12, 13 });
		//check current direction for flip animation
		if ( _movingDirection == MOVING_DIRECTION_LEFT)
		{
			this->setFlipX(false);
		}
		else
			if ( _movingDirection == MOVING_DIRECTION_RIGHT)
			{
			this->setFlipX(true);
			}
	}

	//check animation bug that cant' handle on code
	if ( !_isJumping && !_movingDirection && this->getParent()->getActionByTag(TAG_ACTION_MOVING))
	{
		if ( _movingDirection == MOVING_DIRECTION_LEFT)
		{
			this->setFlipX( false);
			this->animate( this->getMovingAnimationDelay(), { 1, 2, 3, 4, 5, 6, 7, 8 });
		}
		else
			if ( _movingDirection == MOVING_DIRECTION_RIGHT)
			{
			this->setFlipX( true);
			this->animate( this->getMovingAnimationDelay(), { 1, 2, 3, 4, 5, 6, 7, 8 });
			}
	}
}
