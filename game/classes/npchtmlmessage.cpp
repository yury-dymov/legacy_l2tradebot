#include "gamefunc.h"

string GameF::npcHtmlMessage (const string & pck)
{
	return DataFunc::encodeFrom (pck.substr (5, pck.length ()));
}
