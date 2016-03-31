#include "gamefunc.h"

void GameF::systemMessage (const string & pck, int * msgId, vector <SystemItem> * items)
{
	*msgId = DataFunc::stringToInt (pck, 1);
	int count = DataFunc::stringToInt (pck, 5);
	int segm = 9;
	for (int i = 0; i < count; ++i)
	{
		SystemItem elem;
		elem.type = DataFunc::stringToInt (pck, segm);
		segm += 4;
		if (elem.type == E_SYSTEM_STRING)
		{
			unsigned int j = segm;
			for (; pck[j] != static_cast <char> (0); j += 2)
			{
				elem.data += pck[j];
				elem.data += pck[j + 1];
			}
			segm = j + 2;
		}
		else
		{
			elem.data = pck.substr (segm, 4);
			segm += 4;
		}
		items->push_back (elem);
	}
}

