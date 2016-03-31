#include "gamepacket.h"

string GamePacket::setPrivateStoreListSell (const string & str)
{
	string ret;
	ret += E_C_GAME_SET_PRIVATE_STORE_LIST_SELL;
	ret += str;
	return ret;
}
