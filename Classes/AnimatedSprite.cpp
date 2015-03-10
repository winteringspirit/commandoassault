#include "AnimatedSprite.h"

AnimatedSprite::AnimatedSprite()
{
}

AnimatedSprite::~AnimatedSprite()
{
}

AnimatedSprite* AnimatedSprite::create(std::string filepath)
{
	return create(filepath, 1, 1);
}

AnimatedSprite* AnimatedSprite::create(std::string filepath, int columns, int rows)
{
	AnimatedSprite* animatedsprite = new AnimatedSprite();
	animatedsprite->init(filepath, columns, rows);
	return animatedsprite;
}

AnimatedSprite* AnimatedSprite::createWithPhysicsBody(std::string filepath)
{
	AnimatedSprite* animatedsprite = AnimatedSprite::create(filepath, 1, 1);
	animatedsprite->initPhysicBody();
	return animatedsprite;
}
AnimatedSprite* AnimatedSprite::createWithPhysicsBody(std::string filepath, int columns, int rows)
{
	AnimatedSprite* animatedsprite = AnimatedSprite::create(filepath, columns, rows);
	animatedsprite->initPhysicBody();
	return animatedsprite;
}
bool AnimatedSprite::initWithTexture(Texture2D* texture)
{
	if (Sprite::initWithTexture(texture))
	{
	}
	return true;
}
bool AnimatedSprite::init()
{
	return Node::init();
}

bool AnimatedSprite::init(std::string filepath, int columns, int rows)
{
	Texture2D* tx = Director::getInstance()->getTextureCache()->getTextureForKey(filepath);
	if (tx == NULL)
	{
		tx = Director::getInstance()->getTextureCache()->addImage(filepath);
	}
	//create new animatedsprite

	//set rows and columns
	this->setRows(rows);
	this->setColumns(columns);

	//set width and height
	this->setWidth(tx->getContentSize().width / columns);
	this->setHeight(tx->getContentSize().height / rows);

	this->initWithSpriteFrame(SpriteFrame::createWithTexture(tx, Rect(0, 0, this->getWidth(), this->getHeight())));

	//add frame to vector sprite frame
	for (int i = 0; i < columns * rows; i++)
	{
		this->Frames.pushBack(SpriteFrame::createWithTexture(tx,
			Rect((i % columns) * this->getWidth(), (i / columns) *this->getHeight(), this->getWidth(), this->getHeight())));
	}
	//auto release if dont use this(no need to call release - it's auto)
	this->autorelease();
	return true; 
}

void AnimatedSprite::initSettingVectorFrames(std::vector<int> &frames, std::string attribute)
{
	frames.clear();
	std::string listframes = settings->valueForKey(attribute)->getCString();
	std::istringstream iss(listframes);
	while (iss)
	{
		std::string sub;
		iss >> sub;
		if (sub != "")
			frames.push_back(atoi(sub.c_str()));
	}
}

int AnimatedSprite::getSettingIntValue(std::string attribute)
{
	return settings->valueForKey(attribute)->intValue();
}

void AnimatedSprite::setLoop(unsigned int looptime)
{
	_loopTime = looptime;
}

void AnimatedSprite::animate(float animationdelay, std::vector<int> frames)
{
	animate(animationdelay, frames, -1);
}

void AnimatedSprite::animate(float animationdelay, std::vector<int> frames, int loop)
{
	//start animation for this sprite
	this->runAction(AnimatedSprite::createAnimate(animationdelay, frames, loop));
}

void AnimatedSprite::animateWithAutoRelease(float animationdelay, int loop)
{
	std::vector<int> frames;
	for (int i = 0; i < getRows() * getColumns(); i++)
		frames.push_back(i);

	this->runAction(CCSequence::create(AnimatedSprite::createAnimate(animationdelay, frames, loop)
		, CCCallFunc::create(this, callfunc_selector(AnimatedSprite::releaseThis)), NULL));
}

void AnimatedSprite::setFrame(int frame)
{
	this->setSpriteFrame(Frames.at(frame));
}

void AnimatedSprite::animateWithAutoRelease(float animationdelay, std::vector<int> frames, int loop)
{
	this->runAction(CCSequence::create(AnimatedSprite::createAnimate(animationdelay, frames, loop)
		, CCCallFunc::create(this, callfunc_selector(AnimatedSprite::releaseThis)), NULL));
}

Animate* AnimatedSprite::createAnimate(float animationdelay, std::vector<int> frames, int loop)
{
	//set animation delay
	_AnimationDelay = animationdelay;
	Vector<SpriteFrame*> _animateframes;

	//add frame to vector sprite frame
	for (int i = 0; i < frames.size(); i++)
	{
		_animateframes.pushBack(Frames.at(frames.at(i)));
	}
	//create animation with a vector sprite frames
	Animation* _animationW = Animation::createWithSpriteFrames(_animateframes, _AnimationDelay);
	//set loop time
	_animationW->setLoops(loop);
	//stop all action that this sprite is active
	this->stopAllActions();
	return Animate::create(_animationW);
}

void AnimatedSprite::initPhysicBody()
{
	auto physicsBody = PhysicsBody::createBox(Size(this->getContentSize().width, this->getContentSize().height), 
		PhysicsMaterial(0.0f, 0.0f, 0.0f));
	physicsBody->setDynamic(true);
	this->setPhysicsBody(physicsBody);
}

void AnimatedSprite::releaseThis()
{
	this->getParent()->removeChild(this, true);
}
