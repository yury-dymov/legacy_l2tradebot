#include "gamefunc.h"

void GameF::privateStoreMsg (const string & pck, int * objectId, string * msg)
{
	*objectId = DataFunc::stringToInt (pck, 1);
	*msg = DataFunc::encodeFrom (pck.substr (5, pck.length ()));
}

