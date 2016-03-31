#include "gamepacket.h"

string GamePacket::useItem (int objectId, int d)
{
	string ret;
	ret += E_C_GAME_USE_ITEM;
	ret += DataFunc::intToString (objectId);
	ret += DataFunc::intToString (d);
	return ret;
}
