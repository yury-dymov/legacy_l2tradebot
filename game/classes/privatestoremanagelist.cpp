#include "gamefunc.h"

void GameF::privateStoreManageList (const string & pck, int * playerObjId, int * packSell, int * adena, vector <SellItem> * items)
{
	*playerObjId = DataFunc::stringToInt (pck, 1);
	*packSell = DataFunc::stringToInt (pck, 5);
	*adena = DataFunc::stringToInt (pck, 9);
	int count = DataFunc::stringToInt (pck, 13);
	for (int i = 0; i < count; ++i)
	{
		SellItem elem;
		elem.type2 = DataFunc::stringToInt (pck, 17 + i * 30);
		elem.objectId = DataFunc::stringToInt (pck, 21 + i * 30);
		elem.itemId = DataFunc::stringToInt (pck, 25 + i * 30);
		elem.count = DataFunc::stringToInt (pck, 29 + i * 30);
		elem.h1 = DataFunc::stringToInt (pck, 33 + i * 30, 2);
		elem.enchant = DataFunc::stringToInt (pck, 35 + i * 30, 2);
		elem.h2 = DataFunc::stringToInt (pck, 37 + i * 30, 2);
		elem.bodyPart = DataFunc::stringToInt (pck, 39 + i * 30);
		elem.price = DataFunc::stringToInt (pck, 43 + i * 30);
		items->push_back (elem);
	}
}
