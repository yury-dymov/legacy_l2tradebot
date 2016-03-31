#include "gamefunc.h"

int GameF::deleteObject (const string & pck)
{
	return DataFunc::stringToInt (pck, 1);
}
