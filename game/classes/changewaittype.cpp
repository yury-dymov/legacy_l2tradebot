#include "gamefunc.h"

void GameF::changeWaitType (const string & pck, int * objectId, int * waitType, CatXPoint * pos)
{
	*objectId = DataFunc::stringToInt (pck, 1);
	*waitType = DataFunc::stringToInt (pck, 5);
	pos->setX (DataFunc::stringToInt (pck, 9));
	pos->setY (DataFunc::stringToInt (pck, 13));
	pos->setZ (DataFunc::stringToInt (pck, 17));
}
