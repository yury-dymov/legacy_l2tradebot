#include "gamefunc.h"

void GameF::stopMove (const string & pck, int * objectId, CatXPoint * pos)
{
	*objectId = DataFunc::stringToInt (pck, 1);
	pos->setX (DataFunc::stringToInt (pck, 5));
	pos->setY (DataFunc::stringToInt (pck, 9));
	pos->setZ (DataFunc::stringToInt (pck, 13));
}
