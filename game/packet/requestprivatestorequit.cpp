#include "gamepacket.h"

string GamePacket::requestPrivateStoreQuit ()
{
	string ret;
	ret += E_C_GAME_REQUEST_PRIVATE_STORE_QUIT;
	return ret;
}
