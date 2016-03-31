#include "gamepacket.h"

string GamePacket::sendPrivateStoreBuyList (int storePlayerId, const string & str)
{
	string ret;
	ret += E_C_GAME_SEND_PRIVATE_STORE_BUY_LIST;
	ret += DataFunc::intToString (storePlayerId);
	ret += str;
	return ret;
}
