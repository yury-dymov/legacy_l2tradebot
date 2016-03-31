#include "gamepacket.h"

string GamePacket::netPing (const string & str)
{
	string ret;
	ret += E_C_GAME_NET_PING;
	ret += str;
	for (unsigned int i = 0; i < 8; ++i)
	{
		ret += static_cast <char> (0);
	}
	return ret;
}
