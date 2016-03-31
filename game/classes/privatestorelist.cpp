#include "gamefunc.h"

void GameF::privateStoreList (const string & pck, int * objectId, int * packSale, int * adena, vector <PlayerSellItem> * items)
{
	*objectId = DataFunc::stringToInt (pck, 1);
	*packSale = DataFunc::stringToInt (pck, 5);
	*adena = DataFunc::stringToInt (pck, 9);
	int count = DataFunc::stringToInt (pck, 13);
	for (int i = 0; i < count; ++i)
	{
		PlayerSellItem elem;
		elem.type2 = DataFunc::stringToInt (pck, i * 34 + 17);
		elem.objectId = DataFunc::stringToInt (pck, i * 34 + 21);
		elem.itemId = DataFunc::stringToInt (pck, i * 34 + 25);
		elem.count = DataFunc::stringToInt (pck, i * 34 + 29);
		elem.h1 = DataFunc::stringToInt (pck, i * 34 + 33, 2);
		elem.enchant = DataFunc::stringToInt (pck, i * 34 + 35, 2);
		elem.h2 = DataFunc::stringToInt (pck, i * 34 + 37, 2);
		elem.bodyPart = DataFunc::stringToInt (pck, i * 34 + 39);
		elem.price = DataFunc::stringToInt (pck, i * 34 + 43);
		elem.storePrice = DataFunc::stringToInt (pck, i * 34 + 47);
		items->push_back (elem);
	}
}
