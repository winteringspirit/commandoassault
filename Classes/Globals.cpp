#include "Globals.h"

bool Globals::instanceFlag = false;
Globals* Globals::_Globals = NULL;

Globals* Globals::getInstance()
{
	if (!instanceFlag)
	{
		instanceFlag = true;
		_Globals = new Globals();
		return _Globals;
	}
	else
	{
		return _Globals;
	}
}

Globals::Globals()
{
	_pause = false;
	_mapWidth = 1;
	_mapHeight = 1;
}