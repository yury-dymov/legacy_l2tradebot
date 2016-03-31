#include "gamefunc.h"

void GameF::privateBuyListBuy (const string & pck, int * objectId, int * adena, vector <PlayerBuyItem> * items)
{
	*objectId =  DataFunc::stringToInt (pck, 1);
	*adena =  DataFunc::stringToInt (pck, 5);
	int count =  DataFunc::stringToInt (pck, 9);
	for (int i = 0; i < count; ++i)
	{
		PlayerBuyItem elem;
		elem.objectId = DataFunc::stringToInt (pck, i * 34 + 13);
		elem.itemId =  DataFunc::stringToInt (pck, i * 34 + 17);
		elem.enchant =  DataFunc::stringToInt (pck, i * 34 + 21, 2);
		elem.playerCount =  DataFunc::stringToInt (pck, i * 34 + 23);
		elem.refPrice =  DataFunc::stringToInt (pck, i * 34 + 27);
		elem.h1 =  DataFunc::stringToInt (pck, i * 34 + 31, 2);
		elem.bodyPart =  DataFunc::stringToInt (pck, i * 34 + 33);
		elem.type2 =  DataFunc::stringToInt (pck, i * 34 + 37);
		elem.buyersPrice =  DataFunc::stringToInt (pck, i * 34 + 39);
		elem.count =  DataFunc::stringToInt (pck, i * 34 + 43);
		items->push_back (elem);
	}
}
