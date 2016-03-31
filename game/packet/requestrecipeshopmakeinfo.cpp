#include "gamepacket.h"

string GamePacket::requestRecipeShopMakeInfo (int objectId, int recipeId)
{
	string ret;
	ret += E_C_GAME_REQUEST_RECIPE_SHOP_MAKE_INFO;
	ret += DataFunc::intToString (objectId);
	ret += DataFunc::intToString (recipeId);
	return ret;
}
