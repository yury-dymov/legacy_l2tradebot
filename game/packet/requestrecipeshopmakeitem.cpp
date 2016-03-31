#include "gamepacket.h"

string GamePacket::requestRecipeShopMakeItem (int objectId, int recipeId, int un)
{
	string ret;
	ret += E_C_GAME_REQUEST_RECIPE_SHOP_MAKE_ITEM;
	ret += DataFunc::intToString (objectId);
	ret += DataFunc::intToString (recipeId);
	ret += DataFunc::intToString (un);
	return ret;
}
