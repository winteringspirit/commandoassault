#include "RexxBody.h"
#include "Links.h"

bool RexxBody::init()
{
	AnimatedSprite::init(LINK_REXX_BODY, 16, 1);
	this->setPosition(0, 8);
	return true;
}

void RexxBody::setAim(Vec2 aim)
{
	float tempx = aim.x - this->getParent()->getPosition().x;
	float tempy = aim.y - this->getParent()->getPosition().y;
	float angle = std::asin(std::abs(tempx) / std::sqrt(pow(tempx, 2) + pow(tempy, 2))) * 180 / 3.1415;

	if (tempx >= 0 && tempy < 0)
		angle = angle;
	if (tempx >= 0 && tempy >= 0)
		angle = 180 - angle;
	if (tempx < 0 && tempy >= 0)
		angle = 180 + angle;
	if (tempx < 0 && tempy < 0)
		angle = 360 - angle;

	int frame = angle / 22.5;
	if (frame < 8)
	{
		this->setFlipX(true);
		this->setFrame(frame);
	}
	else
	{
		this->setFlipX(false);
		this->setFrame( 7 - frame % 8);
	}
}