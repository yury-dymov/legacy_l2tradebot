#include "gamefunc.h"

void GameF::restartResponse (const string & pck, int * ok, string * msg)
{
	*ok = DataFunc::stringToInt (pck, 1);
	*msg = pck.substr (5, pck.length ());
}
