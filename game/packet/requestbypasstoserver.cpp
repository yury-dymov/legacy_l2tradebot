#include "gamepacket.h"

string GamePacket::requestBypassToServer (const string & pck)
{
	string ret;
	ret += E_C_GAME_REQUEST_BYPASS_TO_SERVER;
	ret += pck;
	return ret;
}
