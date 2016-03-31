#include "gamepacket.h"

string GamePacket::requestSellItem (int saleId, const string & str)
{
	string ret;
	ret += E_C_GAME_REQUEST_SELL_ITEM;
	ret += DataFunc::intToString (saleId);
	ret += str;
	return ret;
}
