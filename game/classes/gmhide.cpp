#include "gamefunc.h"

void GameF::gmHide (const string & pck, int * val)
{
	*val = DataFunc::stringToInt (pck, 1);
}
