#include "gamefunc.h"

void GameF::inventoryUpdate (const string & pck, vector <InventoryItem> * items)
{
	int count = DataFunc::stringToInt (pck, 1, 2);
	for (int i = 0; i < count; ++i)
	{
		InventoryItem elem;
		elem.updateId = DataFunc::stringToInt (pck, i * 38 + 3, 2);
		elem.itemType1 = DataFunc::stringToInt (pck, i * 38 + 5, 2);
		elem.objectId = DataFunc::stringToInt (pck, i * 38 + 7);
		elem.itemId = DataFunc::stringToInt (pck, i * 38 + 11);
		elem.count = DataFunc::stringToInt (pck, i * 38 + 15);
		elem.itemType2 = DataFunc::stringToInt (pck, i * 38 + 19, 2);
		elem.custType1 = DataFunc::stringToInt (pck, i * 38 + 21, 2);
		elem.isEquipped = DataFunc::stringToInt (pck, i * 38 + 23, 2);
		elem.bodyPart = DataFunc::stringToInt (pck, i * 38 + 25);
		elem.enchantLevel = DataFunc::stringToInt (pck, i * 38 + 29, 2);
		elem.custType2 = DataFunc::stringToInt (pck, i * 38 + 31, 2);
		elem.augId = DataFunc::stringToInt (pck, i * 38 + 33);
		elem.shadowTime = DataFunc::stringToInt (pck, i * 38 + 37);
		items->push_back (elem);
	}
}
