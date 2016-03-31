#include "gamefunc.h"

void GameF::itemListPacket (const string & pck, int * window, vector <InventoryItem> * items)
{
	*window  = DataFunc::stringToInt (pck, 1, 2);
	int count = DataFunc::stringToInt (pck, 3, 2);
	for (int i = 0; i < count; ++i)
	{
		InventoryItem elem;
		elem.updateId = E_INVENTORY_NONE;
		elem.itemType1 = DataFunc::stringToInt (pck, i * 36 + 5, 2);
		elem.objectId = DataFunc::stringToInt (pck, i * 36 + 7);
		elem.itemId = DataFunc::stringToInt (pck, i * 36 + 11);
		elem.count = DataFunc::stringToInt (pck, i * 36 + 15);
		elem.itemType2 = DataFunc::stringToInt (pck, i * 36 + 19, 2);
		elem.custType1 = DataFunc::stringToInt (pck, i * 36 + 21, 2);
		elem.isEquipped = DataFunc::stringToInt (pck, i * 36 + 23, 2);
		elem.bodyPart = DataFunc::stringToInt (pck, i * 36 + 25);
		elem.enchantLevel = DataFunc::stringToInt (pck, i * 36 + 29, 2);
		elem.custType2 = DataFunc::stringToInt (pck, i * 36 + 31, 2);
		elem.augId = DataFunc::stringToInt (pck, i * 36 + 33);
		elem.shadowTime = DataFunc::stringToInt (pck, i * 36 + 37);
		items->push_back (elem);
	}
}
