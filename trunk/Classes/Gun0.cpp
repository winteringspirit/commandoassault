#include "Gun0.h"
#include "Links.h"

bool Gun0::init()
{
	Weapon::init(LINK_GUN_0, 1, 1);
	return true;
}

void Gun0::setAim(Vec2 aim)
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

	if (angle > 180)
	{
		this->setPosition(2, 0);
		this->setAnchorPoint(Vec2(0.9, 0.6));
		this->setFlipX(false);
		this->setRotation(-angle - 90);
	}
	else
	{
		this->setPosition(-2, 0);
		this->setAnchorPoint(Vec2(0.1, 0.6));
		this->setFlipX(true);
		this->setRotation(-angle + 90);
	}

}