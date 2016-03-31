#include "gamefunc.h"

void GameF::teleportToLocation (const string & pck, int * targetId, CatXPoint * pos)
{
	*targetId = DataFunc::stringToInt (pck, 1);
	pos->setX (DataFunc::stringToInt (pck, 5));
	pos->setY (DataFunc::stringToInt (pck, 9));
	pos->setZ (DataFunc::stringToInt (pck, 13));
}
