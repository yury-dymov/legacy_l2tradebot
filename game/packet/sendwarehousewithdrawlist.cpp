#include "gamepacket.h"

string GamePacket::sendWareHouseWithdrawList (const string & pck)
{
	string ret;
	ret += E_C_GAME_SEND_WAREHOUSE_WITHDRAW_LIST;
	ret += pck;
	return ret;
}
