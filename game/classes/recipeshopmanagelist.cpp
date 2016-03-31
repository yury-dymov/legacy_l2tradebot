#include "gamefunc.h"

void GameF::recipeShopManageList (const string & pck, int * objectId, int * adena, int * isDwarven, vector <DwarfenManufactureItem> * recipe, vector <DwarfenManufactureItem> * trade)
{
	*objectId = DataFunc::stringToInt (pck, 1);
	*adena = DataFunc::stringToInt (pck, 5);
	*isDwarven = DataFunc::stringToInt (pck, 9);
	int count = DataFunc::stringToInt (pck, 13);
	for (int i = 0; i < count; ++i)
	{
		DwarfenManufactureItem elem;
		elem.recipeId = DataFunc::stringToInt (pck, 8 * i + 17);
		elem.recipeNum = DataFunc::stringToInt (pck, 8 * i + 21);
		recipe->push_back (elem);
	}
	int count2 = DataFunc::stringToInt (pck, 8 * count + 17);
	for (int i = 0; i < count2; ++i)
	{
		DwarfenManufactureItem elem;
		elem.recipeId = DataFunc::stringToInt (pck, 8 * count + 21 + i * 12);
		elem.d = DataFunc::stringToInt (pck, 8 * count + 25 + i * 12);
		elem.price = DataFunc::stringToInt (pck, 8 * count + 29 + i * 12);
		trade->push_back (elem);
	}
}
