#include "gamefunc.h"

void GameF::wareHouseDepositList (const string & pck, int * whtype, int * adena, vector <WarehouseItem> * items)
{
	*whtype = DataFunc::stringToInt (pck, 1, 2);
	*adena = DataFunc::stringToInt (pck, 3);
	int count = DataFunc::stringToInt (pck, 7, 2);
	for (int i = 0; i < count; ++i)
	{
		WarehouseItem elem;
		elem.itemType1 = DataFunc::stringToInt (pck, i * 40 + 9, 2);
		elem.objectId = DataFunc::stringToInt (pck, i * 40 + 11);
		elem.itemId = DataFunc::stringToInt (pck, i * 40 + 15);
		elem.count = DataFunc::stringToInt (pck, i * 40 + 19);
		elem.itemType2 = DataFunc::stringToInt (pck, i * 40 + 23, 2);
		elem.h1 = DataFunc::stringToInt (pck, i * 40 + 25, 2);
		elem.bodyPart = DataFunc::stringToInt (pck, i * 40 + 27);
		elem.enchantLevel = DataFunc::stringToInt (pck, i * 40 + 31, 2);
		elem.h2 = DataFunc::stringToInt (pck, i * 40 + 33, 2);
		elem.h3 = DataFunc::stringToInt (pck, i * 40 + 35, 2);
		elem.objectId2 = DataFunc::stringToInt (pck, i * 40 + 37);
		elem.d1 = DataFunc::stringToInt (pck, i * 40 + 41);
		elem.d2 = DataFunc::stringToInt (pck, i * 40 + 45);
		items->push_back (elem);
	}
}
