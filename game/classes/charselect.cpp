#include "gamefunc.h"

void GameF::charSelect (const string & pck, vector <CharSelectItem> * chars)
{
	int count = DataFunc::stringToInt (pck, 1);
	int segm = 5;
	for (int i = 0; i < count; ++i)
	{
		CharSelectItem elem;
		int length1 = 2;
		int length2 = 2;
		for (int j = segm; pck[j] != static_cast <char> (0); j += 2)
		{
			elem.name += pck[j];
			length1 += 2;
		}
		for (int j = segm + length1 + 4; pck[j] != static_cast <char> (0); j += 2)
		{
			length2 += 2;
		}
		elem.cls = DataFunc::stringToInt (pck, segm + length1 + length2 + 24);
		segm += length1;
		segm += length2;
		segm += 297;
		chars->push_back (elem);
	}
}
