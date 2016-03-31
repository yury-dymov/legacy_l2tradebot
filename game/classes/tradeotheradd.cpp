#include "gamefunc.h"

void GameF::tradeOtherAdd (const string & pck, vector <TradeItem> * items)
{
	int count = DataFunc::stringToInt (pck, 1, 2);
	for (int i = 0; i < count; ++i)
	{
		TradeItem elem;
		elem.itemType1 = DataFunc::stringToInt (pck, i * 28 + 3, 2);
		elem.objectId = DataFunc::stringToInt (pck, i * 28 + 5);
		elem.itemId = DataFunc::stringToInt (pck, i * 28 + 9);
		elem.count = DataFunc::stringToInt (pck, i * 28 + 13);
		elem.itemType2 = DataFunc::stringToInt (pck, i * 28 + 17, 2);
		elem.h1 = DataFunc::stringToInt (pck, i * 28 + 19, 2);
		elem.bodyPart = DataFunc::stringToInt (pck, i * 28 + 21);
		elem.enchantLevel = DataFunc::stringToInt (pck, i * 28 + 25, 2);
		elem.h2 = DataFunc::stringToInt (pck, i * 28 + 27, 2);
		elem.h3 = DataFunc::stringToInt (pck, i * 28 + 29, 2);
		items->push_back (elem);
	}
}
