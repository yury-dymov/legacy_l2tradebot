#include "gamepacket.h"

string GamePacket::requestManorList ()
{
	string ret;
	ret += E_C_GAME_REQUEST_MANOR_LIST1;
	ret += E_C_GAME_REQUEST_MANOR_LIST2;
	return ret;
}
