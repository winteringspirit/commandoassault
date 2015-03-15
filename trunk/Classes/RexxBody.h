#ifndef __REXX_BODY_H__
#define __REXX_BODY_H__


#include "cocos2d.h"
#include "AnimatedSprite.h"
USING_NS_CC;

class RexxBody:public AnimatedSprite
{
private:
protected:
public:
	virtual bool init();

	void setAim(Vec2 node);

	CREATE_FUNC(RexxBody);
};

#endif