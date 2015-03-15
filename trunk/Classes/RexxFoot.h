#ifndef __REXX_FOOT_H__
#define __REXX_FOOT_H__

#include "cocos2d.h"
#include "AnimatedSprite.h"

USING_NS_CC;

class RexxFoot : public AnimatedSprite
{
private:
	bool _isJumping;
	float getMovingAnimationDelay();
protected:
public:
	//initialize this object
	virtual bool init();

	//object action
	void stand();
	void moveLeft();
	void moveRight();
	void jump();
	//sit down
	void crouch();

	void update(float delta);

	//moving speed
	CC_SYNTHESIZE(float, _movingSpeed, MovingSpeed);
	//Jump force
	CC_SYNTHESIZE(float, _jumpForce, JumpForce);
	//moving direction
	CC_SYNTHESIZE(int, _movingDirection, MovingDirection);
	//times per jump without landed, example double jump, tripple jump, default once jump
	CC_SYNTHESIZE(int, _jumpTimes, JumpTime);
	CREATE_FUNC(RexxFoot);
};

#endif