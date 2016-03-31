#include "gamefunc.h"

void GameF::moveToLocation (const string & pck, int * objectId, CatXPoint * from, CatXPoint * to)
{
	// 0 - packet Id
	// 1 - object id
	// 5 - dest x
	// 9 - dest y
	// 13 - dest z
	// 17 - cur x
	// 21 - cur y
	// 25 - cur z
	*objectId = DataFunc::stringToInt (pck, 1);
	from->setX (DataFunc::stringToInt (pck, 5));
	from->setY (DataFunc::stringToInt (pck, 9));
	from->setZ (DataFunc::stringToInt (pck, 13));
	to->setX (DataFunc::stringToInt (pck, 17));
	to->setY (DataFunc::stringToInt (pck, 21));
	to->setZ (DataFunc::stringToInt (pck, 25));
}
