#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#include "cocos2d.h"
#include "FileOperation.h"

#define LINK_SPRITE_FILE	"link.txt"

#define PTM_RATIO 32
#define SET_DEBUG 0

#define SCREEN_WIDTH		600
#define SCREEN_HEIGHT		450

#define OBJECT_TYPE_PLAYER_HELICOPTER		-10000
#define OBJECT_TYPE_BLUEBERRY_HELICOPTER	0
#define OBJECT_TYPE_ORANGE_HELICOPTER		1
#define OBJECT_TYPE_STRAWBERRY_HELICOPTER	2
#define OBJECT_TYPE_BULLET					-1

#define BULLET_COLOR_RED	0
#define BULLET_COLOR_BLUE	1
#define BULLET_COLOR_GREEN	2
#define BULLET_COLOR_YELLOW	3
#define BULLET_COLOR_PINK	4
#define BULLET_COLOR_ASDS	5
#define BULLET_COLOR_ORANGE	6

#define ID_TOUCH_MOVE		-10

#define Z_ORDER_ORANGE_HELICOPTER	1

#define TAG_ACTION_MOVING	0
#define TAG_OBJECT_BULLET	1
#define TAG_OBJECT_ENEMY	2
#define TAG_GAMEPLAY_LAYER	3

#define COLLISION_BITMARK_ENEMY	1
#define COLLISION_BITMARK_PLAYER 2

//same group for ignoring collision
#define COLLISION_GROUP_PLAYER	-1
#define COLLISION_GROUP_ENEMY	-2

#define DEFAULT_DISTANCE_BETWEEN_FINGER_AND_PLANE	80

#define DESENTY_ENEMY	100000

#define HELICOPTER_FLY_TYPE_0	0
#define HELICOPTER_FLY_TYPE_1	1
#define HELICOPTER_FLY_TYPE_2	2
#define HELICOPTER_FLY_TYPE_3	3
#define HELICOPTER_FLY_TYPE_4	4

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
