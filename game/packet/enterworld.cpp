#include "gamepacket.h"

string GamePacket::enterWorld ()
{
	string ret;
	ret += E_C_GAME_ENTER_WORLD;
	return ret;
}
