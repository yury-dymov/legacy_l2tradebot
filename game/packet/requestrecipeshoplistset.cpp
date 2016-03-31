#include "gamepacket.h"

string GamePacket::requestRecipeShopListSet (const string & pck)
{
	string ret;
	ret += E_C_GAME_REQUEST_RECIPE_SHOP_LIST_SET;
	ret += pck;
	return ret;
}

