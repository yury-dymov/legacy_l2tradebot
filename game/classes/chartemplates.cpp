#include "gamefunc.h"

void GameF::charTemplates (const string & pck, vector <CharTemplate> * chars)
{
	int count = DataFunc::stringToInt (pck, 1);
	for (int i = 0; i < count; ++i)
	{
		CharTemplate elem;
		elem.race = DataFunc::stringToInt (pck, 80 * i + 5);
		elem.classId = DataFunc::stringToInt (pck, 80 * i + 9);	
		elem.str = DataFunc::stringToInt (pck, 80 * i + 17);
		elem.dex = DataFunc::stringToInt (pck, 80 * i + 29);
		elem.con = DataFunc::stringToInt (pck, 80 * i + 41);
		elem.intt = DataFunc::stringToInt (pck, 80 * i + 53);
		elem.wit = DataFunc::stringToInt (pck, 80 * i + 65);	
		elem.men = DataFunc::stringToInt (pck, 80 * i + 77);
		chars->push_back (elem);
	}
}
