#include "gamefunc.h"

void GameF::say2 (const string & pck, int * objectId, int * type, string * charName, string * message)
{
	*objectId = DataFunc::stringToInt (pck, 1);
	*type = DataFunc::stringToInt (pck, 5);
	unsigned int i = 9;
	for (; i < pck.length (); i += 2)
	{
		*charName += pck [i];
		*charName += pck [i + 1];
		if (pck[i] == static_cast <char> (0))
		{
			break;
		}
	}
	for (i += 2; i < pck.length (); i += 2)
	{
		*message += pck [i];
		*message += pck [i + 1];
		if (pck[i] == static_cast <char> (0))
		{
			break;
		}
	}
}
