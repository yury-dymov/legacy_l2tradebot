#include "gamepacket.h"

string GamePacket::sendWareHouseDepositList (const string & pck)
{
	string ret;
	ret += E_C_GAME_SEND_WAREHOUSE_DEPOSIT_LIST;
	ret += pck;
	return ret;
}
