#include "gamefunc.h"

void GameF::sellList (const string & pck, int * adena, int * saleId, vector <NpcBuyItem> * items)
{
	*adena = DataFunc::stringToInt (pck, 1);
	*saleId = DataFunc::stringToInt (pck, 5);
	int count = DataFunc::stringToInt (pck, 9, 2);
	for (int i = 0; i < count; ++i)
	{
		NpcBuyItem elem;
		elem.itemType1 = DataFunc::stringToInt (pck, i * 32 + 11, 2);
		elem.objectId = DataFunc::stringToInt (pck, i * 32 + 13);
		elem.itemId = DataFunc::stringToInt (pck, i * 32 + 17);
		elem.count = DataFunc::stringToInt (pck, i * 32 + 21);
		elem.itemType2 = DataFunc::stringToInt (pck, i * 32 + 25, 2);
		elem.h1 = DataFunc::stringToInt (pck, i * 32 + 27, 2);
		elem.itemBodyPart = DataFunc::stringToInt (pck, i * 32 + 29);
		elem.enchantLevel = DataFunc::stringToInt (pck, i * 32 + 33, 2);
		elem.h2 = DataFunc::stringToInt (pck, i * 32 + 35, 2);
		elem.h3 = DataFunc::stringToInt (pck, i * 32 + 37, 2);
		elem.refPrice = DataFunc::stringToInt (pck, i * 32 + 39);
		items->push_back (elem);
	}
}
