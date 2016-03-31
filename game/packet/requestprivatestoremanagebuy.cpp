#include "gamepacket.h"

string GamePacket::requestPrivateStoreManageBuy ()
{
	string ret;
	ret += E_C_GAME_REQUEST_PRIVATE_STORE_MANAGE_BUY;
	return ret;
}
