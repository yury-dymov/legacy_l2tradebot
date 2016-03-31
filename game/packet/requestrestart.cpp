#include "gamepacket.h"

string GamePacket::requestRestart ()
{
	string ret;
	ret += E_C_GAME_REQUEST_RESTART;
	return ret;
}
