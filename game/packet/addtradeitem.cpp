#include "gamepacket.h"

string GamePacket::addTradeItem (int tradeId, int objectId, int count)
{
	string ret;
	ret += E_C_GAME_ADD_TRADE_ITEM;
	ret += DataFunc::intToString (tradeId);
	ret += DataFunc::intToString (objectId);
	ret += DataFunc::intToString (count);
	return ret;
}
