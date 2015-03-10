#ifndef __PLIST_ANIMATED_SPRITE_H__
#define __PLIST_ANIMATED_SPRITE_H__

#include "cocos2d.h"
#include "Globals.h"
#include "AnimatedSprite.h"

USING_NS_CC;

class PlistAnimatedSprite : public AnimatedSprite
{
private:

	Vector<SpriteFrame*> _AnimationFrames;
	std::map<std::string, int> _FrameNames;
public:
	//Constructor & Destructor
	PlistAnimatedSprite();

	//initialize this sprite
	static PlistAnimatedSprite* create();
	static PlistAnimatedSprite* create(std::string frame);
	static PlistAnimatedSprite* create(float animationdelay, std::string frames[]);
	static PlistAnimatedSprite* create(float animationdelay, std::vector<std::string> frames);

	static PlistAnimatedSprite* createWithPhysics();
	static PlistAnimatedSprite* createWithPhysics(std::string frame);
	static PlistAnimatedSprite* createWithPhysics(float animationdelay, std::string frames[]);
	static PlistAnimatedSprite* createWithPhysics(float animationdelay, std::vector<std::string> frames);

	void initAnimation(float animationdelay, std::vector<std::string> frames);
	//function
	void animate(float animationdelay, std::string frames[]);
	void animate(float animationdelay, std::vector<std::string> frames);
	void animate(float animationdelay, std::vector<std::string> frames, int looptime);

	void addFrames(std::vector<std::string> frames);
	void addFrame(std::string frames);

};

#endif // !1
