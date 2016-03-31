#include "gamepacket.h"

string GamePacket::requestBuyItem (int tradeId, const string & str)
{
	string ret;
	ret += E_C_GAME_REQUEST_BUY_ITEM;
	ret += DataFunc::intToString (tradeId);
	ret += str;
	return ret;
}
