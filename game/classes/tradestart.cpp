#include "gamefunc.h"

void GameF::tradeStart (const string & pck, int * objectId, vector <TradeItem> * items)
{
	*objectId = DataFunc::stringToInt (pck, 1);
	int count = DataFunc::stringToInt (pck, 5, 2);
	for (int i = 0; i < count; ++i)
	{
		TradeItem elem;
		elem.itemType1 = DataFunc::stringToInt (pck, i * 28 + 7, 2);
		elem.objectId = DataFunc::stringToInt (pck, i * 28 + 9);
		elem.itemId = DataFunc::stringToInt (pck, i * 28 + 13);
		elem.count = DataFunc::stringToInt (pck, i * 28 + 17);
		elem.itemType2 = DataFunc::stringToInt (pck, i * 28 + 21, 2);
		elem.h1 = DataFunc::stringToInt (pck, i * 28 + 23, 2);
		elem.bodyPart = DataFunc::stringToInt (pck, i * 28 + 25);
		elem.enchantLevel = DataFunc::stringToInt (pck, i * 28 + 29, 2);
		elem.h2 = DataFunc::stringToInt (pck, i * 28 + 31, 2);
		elem.h3 = DataFunc::stringToInt (pck, i * 28 + 33, 2);
		items->push_back (elem);
	}
}
