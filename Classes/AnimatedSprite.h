#ifndef __ANIMATED_SPRITE_H__
#define __ANIMATED_SPRITE_H__

#include "cocos2d.h"
#include "Globals.h"

USING_NS_CC;

class AnimatedSprite :public Sprite
{
private:
	void releaseThis();
public:
	//Contructor & Destructor
	AnimatedSprite();
	~AnimatedSprite();
	
	//Init sprite with Texture
	bool initWithTexture(Texture2D* texture);

	Vector<SpriteFrame*> Frames;
	CCDictionary* settings;


	void setAnimationDelay(float animationdelay){ _AnimationDelay = animationdelay; };
	float getAnimationDelay(){ return _AnimationDelay; };

	void initPhysicBody();
	void setDynamicBody();
	void setSensorBody();
	void setGroup(int group); 
	void setFrame(int frame);
	//Initialize
	static AnimatedSprite* create(std::string filepath);
	static AnimatedSprite* create(std::string filepath, int columns, int rows);
	static AnimatedSprite* createWithPhysicsBody(std::string filepath);
	static AnimatedSprite* createWithPhysicsBody(std::string filepath, int columns, int rows);
	
	bool init();
	bool init(std::string filepath, int columns, int rows);
	void initSettingVectorFrames(std::vector<int> &frames, std::string attribute);
	int getSettingIntValue(std::string attribute);

	//animate this sprite with a specific list frames
	void animate(float animationdelay, std::vector<int>frames);
	void animate(float animationdelay, std::vector<int> frames, int loop);
	void animateWithAutoRelease(float animationdelay, std::vector<int> frames, int loop);
	void animateWithAutoRelease(float animationdelay, int loop);

	Animate* createAnimate(float animationdelay, std::vector<int> frames, int loop);
	//Set and get properties
	void setLoop(unsigned int looptime);

	//Sprite properties
	CC_SYNTHESIZE(int, _rows, Rows);
	CC_SYNTHESIZE(int, _rolumns, Columns);
	CC_SYNTHESIZE(int, _width, Width);
	CC_SYNTHESIZE(int, _height, Height);

	//Times loop
	CC_SYNTHESIZE(int, _loopTime, LoopTime);
	//animation delay
	float _AnimationDelay;

};

#endif
