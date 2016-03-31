#include "gamefunc.h"

void GameF::charCreateFail (const string & pck, int * reason)
{
	*reason = DataFunc::stringToInt (pck, 1);
}
