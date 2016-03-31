#include "gamepacket.h"

string GamePacket::tradeRequest (int objectId)
{
	string ret;
	ret += E_C_GAME_TRADE_REQUEST;
	ret += DataFunc::intToString (objectId);
	return ret;
}
