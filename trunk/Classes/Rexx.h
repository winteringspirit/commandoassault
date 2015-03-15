#ifndef __REXX_H__
#define __REXX_H__

#include "cocos2d.h"
#include "RexxFoot.h"
#include "RexxBody.h"
#include "Weapon.h"

USING_NS_CC;

class Rexx :public Node
{
private:
	RexxFoot* _rexxFoot;
	RexxBody* _rexxBody;
	Weapon* _rexxWeapon;
protected:
public:
	virtual bool init();
	void stand();
	void moveLeft();
	void moveRight();
	void crouch();
	void jump();
	void fire();

	//set moving speed pixel/second
	void setMovingSpeed(float speed);
	//set target for firing
	void setAim(Vec2 aim);

	Vector<Node*> collidedGrounds;

	CREATE_FUNC(Rexx);
};

#endif