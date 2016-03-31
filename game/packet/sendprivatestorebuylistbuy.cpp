#include "gamepacket.h"

string GamePacket::sendPrivateStoreBuyListBuy (int storePlayerId, const string & str)
{
	string ret;
	ret += E_C_GAME_SEND_PRIVATE_STORE_BUY_LIST_BUY;
	ret += DataFunc::intToString (storePlayerId);
	ret += str;
	return ret;
}
