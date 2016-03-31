#include "gamefunc.h"

void GameF::charCreateOk (const string & pck, int * ok)
{
	*ok = DataFunc::stringToInt (pck, 1);
}
