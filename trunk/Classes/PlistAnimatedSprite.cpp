#include "PlistAnimatedSprite.h"

PlistAnimatedSprite::PlistAnimatedSprite()
{
}

PlistAnimatedSprite* PlistAnimatedSprite::create()
{
	PlistAnimatedSprite* _PlistAnimatedSprite = new PlistAnimatedSprite();
	_PlistAnimatedSprite->init();
	_PlistAnimatedSprite->autorelease();
	return _PlistAnimatedSprite;
}

PlistAnimatedSprite* PlistAnimatedSprite::createWithPhysics()
{
	PlistAnimatedSprite* _PlistAnimatedSprite = new PlistAnimatedSprite();
	_PlistAnimatedSprite->init();
	_PlistAnimatedSprite->initPhysicBody();
	_PlistAnimatedSprite->autorelease();
	return _PlistAnimatedSprite;
}

PlistAnimatedSprite* PlistAnimatedSprite::createWithPhysics(std::string frame)
{
	PlistAnimatedSprite* _PlistAnimatedSprite = new PlistAnimatedSprite();
	_PlistAnimatedSprite->initWithSpriteFrameName(frame);
	_PlistAnimatedSprite->autorelease();
	_PlistAnimatedSprite->initPhysicBody();
	return _PlistAnimatedSprite;
}

PlistAnimatedSprite* PlistAnimatedSprite::createWithPhysics(float animationdelay, std::string frames[])
{
	std::vector < std::string > temp;
	for (int i = 0; i < sizeof(frames); i++)
	{
		temp.push_back(frames[i]);
	}
	return createWithPhysics(animationdelay, temp);
}

PlistAnimatedSprite* PlistAnimatedSprite::create(std::string frame)
{
	PlistAnimatedSprite* _PlistAnimatedSprite = new PlistAnimatedSprite();
	_PlistAnimatedSprite->initWithSpriteFrameName(frame);
	_PlistAnimatedSprite->autorelease();
	return _PlistAnimatedSprite;
}

PlistAnimatedSprite* PlistAnimatedSprite::create(float animationdelay, std::string frames[])
{
	std::vector < std::string > temp;
	for (int i = 0; i < sizeof(frames); i++)
	{
		temp.push_back(frames[i]);
	}
	return create(animationdelay, temp);
}

PlistAnimatedSprite* PlistAnimatedSprite::create(float animationdelay, std::vector<std::string> frames)
{
	//create new animatedsprite
	PlistAnimatedSprite* _PlistAnimatedSprite = new PlistAnimatedSprite();
	_PlistAnimatedSprite->initAnimation(animationdelay, frames);
	return _PlistAnimatedSprite;
}

PlistAnimatedSprite* PlistAnimatedSprite::createWithPhysics(float animationdelay, std::vector<std::string> frames)
{
	//create new animatedsprite
	PlistAnimatedSprite* _PlistAnimatedSprite = new PlistAnimatedSprite();
	_PlistAnimatedSprite->initAnimation(animationdelay, frames);
	_PlistAnimatedSprite->initPhysicBody();
	return _PlistAnimatedSprite;
}

void PlistAnimatedSprite::initAnimation(float animationdelay, std::vector<std::string> frames)
{
	this->initWithSpriteFrameName(frames.at(0));
	this->Node::autorelease();

	if (frames.size() > 1)
	{
		//add frame to vector sprite frame
		this->addFrames(frames);

		//create animation with a vector sprite frames
		Animation* _animationW = Animation::createWithSpriteFrames(_AnimationFrames, animationdelay);
		//set loop time
		_animationW->setLoops(-1);
		//start animation for this sprite
		this->runAction(Animate::create(_animationW));
	}
}

void PlistAnimatedSprite::animate(float animationdelay, std::string frames[])
{
	std::vector<std::string> _Frames;
	//add frame to vector sprite frame
	for (int i = 0; i < sizeof(frames); i++)
	{
		_Frames.push_back(frames[i]);
	}
	this->animate(animationdelay, _Frames);
}

void PlistAnimatedSprite::animate(float animationdelay, std::vector<std::string> frames)
{
	this->animate( animationdelay,  frames, -1);
}

void PlistAnimatedSprite::animate(float animationdelay, std::vector<std::string> frames, int looptime)
{
	//stop all action that this sprite is active
	this->stopAllActions();
	if (frames.size() > 1)
	{
		Vector<SpriteFrame*> _animateframes;
		//add frame to vector sprite frame
		for (int i = 0; i < frames.size(); i++)
		{
			int position = _FrameNames[frames.at(i)] - 1;
			if (position != -1)
				_animateframes.pushBack(_AnimationFrames.at(position));
		}
		//create animation with a vector sprite frames
		Animation* _animationW = Animation::createWithSpriteFrames(_animateframes, animationdelay);
		//set loop time
		_animationW->setLoops(looptime);

		//start animation for this sprite
		this->runAction(Animate::create(_animationW));
	}
	else
	{
		int position = _FrameNames[frames.at(0)] - 1;
		this->setSpriteFrame(_AnimationFrames.at(position));
	}
}

void PlistAnimatedSprite::addFrames(std::vector<std::string> frames)
{
	for (int i = 0; i < frames.size(); i++)
	{
		_AnimationFrames.pushBack(SpriteFrameCache::sharedSpriteFrameCache()->getSpriteFrameByName(frames.at(i) ) );
		_FrameNames[frames.at(i)] = _AnimationFrames.size();
	}
}

void PlistAnimatedSprite::addFrame(std::string frames)
{
	_AnimationFrames.pushBack(SpriteFrameCache::sharedSpriteFrameCache()->getSpriteFrameByName(frames));
	_FrameNames[frames] = _AnimationFrames.size();
}