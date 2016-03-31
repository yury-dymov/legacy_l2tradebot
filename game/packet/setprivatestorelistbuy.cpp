#include "gamepacket.h"

string GamePacket::setPrivateStoreListBuy (const string & pck)
{
	string ret;
	ret += E_C_GAME_SET_PRIVATE_STORE_LIST_BUY;
	ret += pck;
	return ret;
}
