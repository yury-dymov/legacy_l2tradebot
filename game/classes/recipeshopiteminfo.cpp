#include "gamefunc.h"

void GameF::recipeShopItemInfo (const string & pck, int * shopId, int * recipeId, int * mp, int * maxMp)
{
	*shopId = DataFunc::stringToInt (pck, 1);
	*recipeId = DataFunc::stringToInt (pck, 5);
	*mp = DataFunc::stringToInt (pck, 9);
	*maxMp = DataFunc::stringToInt (pck, 13);
}
