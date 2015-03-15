#ifndef __WEAPON_H__
#define __WEAPON_H__

#include "cocos2d.h"
#include "AnimatedSprite.h"

USING_NS_CC;

class Weapon:public AnimatedSprite
{
private:
protected:
public:
	virtual void setAim(Vec2 aim){};
};

#endif