#include "gamepacket.h"

string GamePacket::requestPrivateStoreQuitBuy ()
{
	string ret;
	ret += E_C_GAME_REQUEST_PRIVATE_STORE_QUIT_BUY;
	return ret;
}
