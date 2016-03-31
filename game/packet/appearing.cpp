#include "gamepacket.h"

string GamePacket::appearing ()
{
	string ret;
	ret += E_C_GAME_APPEARING;
	return ret;
}
