#include "ButtonMap.h"
#include "Button.h"


std::map<std::string, Button*>& ButtonMap::GetMap()
{
	static std::map<std::string, Button*> map;
	return map;
}


