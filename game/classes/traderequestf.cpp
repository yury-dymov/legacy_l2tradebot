#include "gamefunc.h"

void GameF::tradeRequest (const string & pck, int * senderId)
{
	*senderId = DataFunc::stringToInt (pck, 1);
}
