#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#include "cocos2d.h"
#include "FileOperation.h"

#define LINK_SPRITE_FILE	"link.txt"

#define PTM_RATIO 32
#define SET_DEBUG 0

#define SCREEN_WIDTH		600
#define SCREEN_HEIGHT		450

#define TAG_ACTION_MOVING	0
#define TAG_ACTION_JUMP		1

#define TAG_OBJECT_PLAYER	0
#define TAG_OBJECT_GROUND	1


#define MOVING_DIRECTION_LEFT	-1
#define MOVING_DIRECTION_RIGHT	1
#define MOVING_DIRECTION_NO		0

class Globals
{
private:
	static bool instanceFlag;
	static Globals* _Globals;

public:
	Globals();
	~Globals(){ instanceFlag = false; };
	static Globals* getInstance();

	CC_SYNTHESIZE(float, _mapWidth, MapWidth);
	CC_SYNTHESIZE(float, _mapHeight, MapHeight);
	CC_SYNTHESIZE(bool, _pause, Pause);
};

#endif // !_GLOBAL_H_
