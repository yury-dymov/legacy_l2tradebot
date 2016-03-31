#include "gamepacket.h"

string GamePacket::requestRecipeShopPrev (int objectId)
{
	string ret;
	ret += E_C_GAME_REQUEST_RECIPE_SHOP_PREV;
	ret += DataFunc::intToString (objectId);
	return ret;
}
