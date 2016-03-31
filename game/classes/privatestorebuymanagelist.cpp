#include "gamefunc.h"

void GameF::privateStoreBuyManageList (const string & pck, int * playerObjId, int * adena, vector <BuyItem> * items)
{
	*playerObjId = DataFunc::stringToInt (pck, 1);
	*adena = DataFunc::stringToInt (pck, 5);
	int count = DataFunc::stringToInt (pck, 9);
	for (int i = 0; i < count; ++i)
	{
		BuyItem elem;
		elem.itemId = DataFunc::stringToInt (pck, 13 + i * 22);
		elem.h1 = DataFunc::stringToInt (pck, 17 + i * 22, 2);
		elem.count = DataFunc::stringToInt (pck, 19 + i * 22);
		elem.price = DataFunc::stringToInt (pck, 23 + i * 22);
		elem.h2 = DataFunc::stringToInt (pck, 27 + i * 22, 2);
		elem.bodyPart = DataFunc::stringToInt (pck, 29 + i * 22);
		elem.type2 = DataFunc::stringToInt (pck, 33 + i * 22, 2);
		items->push_back (elem);
	}
}


