#include "gamepacket.h"

string GamePacket::requestRecipeShopMessageSet (const string & str)
{
	string ret;
	ret += E_C_GAME_REQUEST_RECIPE_SHOP_MESSAGE_SET;
	ret += str;
	return ret;
}
