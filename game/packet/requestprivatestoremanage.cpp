#include "gamepacket.h"

string GamePacket::requestPrivateStoreManage ()
{
	string ret;
	ret += E_C_GAME_REQUEST_PRIVATE_STORE_MANAGE;
	return ret;
}
