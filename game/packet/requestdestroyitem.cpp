#include "gamepacket.h"

string GamePacket::requestDestroyItem (int objectId, int count)
{
	string ret;
	ret += E_C_GAME_REQUEST_DESTROY_ITEM;
	ret += DataFunc::intToString (objectId);
	ret += DataFunc::intToString (count);
	return ret;
}
