#include "gamepacket.h"

string GamePacket::requestCrystallizeItem (int objectId, int count)
{
	string ret;
	ret += E_C_GAME_REQUEST_CRYSTALLIZE_ITEM;
	ret += DataFunc::intToString (objectId);
	ret += DataFunc::intToString (count);
	return ret;
}
