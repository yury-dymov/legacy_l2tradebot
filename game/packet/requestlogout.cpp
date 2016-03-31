#include "gamepacket.h"

string GamePacket::requestLogout ()
{
	string ret;
	ret += E_C_GAME_REQUEST_LOGOUT;
	return ret;
}
