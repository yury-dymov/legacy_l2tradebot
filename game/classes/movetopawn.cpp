#include "gamefunc.h"

void GameF::moveToPawn (const string & pck, int * objectId, int * target, CatXPoint * point, int * dist)
{
	*objectId = DataFunc::stringToInt (pck, 1);
	*target = DataFunc::stringToInt (pck, 5);
	*dist = DataFunc::stringToInt (pck, 9);
	point->setX (DataFunc::stringToInt (pck, 13));
	point->setY (DataFunc::stringToInt (pck, 17));
	point->setZ (DataFunc::stringToInt (pck, 21));
}
