#ifndef __GUN_0_h__
#define __GUN_0_h__

#include "cocos2d.h"
#include "Weapon.h"

USING_NS_CC;

class Gun0 : public Weapon{
private:
protected:
public:
	virtual bool init();
	virtual void setAim(Vec2 aim);
	CREATE_FUNC(Gun0);
};

#endif