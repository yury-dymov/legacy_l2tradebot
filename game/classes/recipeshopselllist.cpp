#include "gamefunc.h"

void GameF::recipeShopSellList (const string & pck, int * objectId, int * mp, int * maxMp, int * adena, vector <RecipeShopItem> * items)
{
	*objectId = DataFunc::stringToInt (pck, 1);
	*mp = DataFunc::stringToInt (pck, 5);
	*maxMp = DataFunc::stringToInt (pck, 9);
	*adena = DataFunc::stringToInt (pck, 13);
	int count = DataFunc::stringToInt (pck, 17);
	for (int i = 0; i < count; ++i)
	{
		RecipeShopItem elem;
		elem.recipeId = DataFunc::stringToInt (pck, i * 12 + 21);
		elem.price = DataFunc::stringToInt (pck, i * 12 + 29);
		items->push_back (elem);
	}
}
