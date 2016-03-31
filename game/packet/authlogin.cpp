#include "gamepacket.h"

string GamePacket::authRequest (const string & acc, const string & sessionKey)
{
	string ret;
	ret += E_C_GAME_AUTH_REQUEST;
	ret += DataFunc::encodeTo (acc);
	for (int i = 0; i < 2; ++i)
	{
		ret += sessionKey.substr (4, 4);
		ret += sessionKey.substr (0, 4);
	}
	ret += 0x01;
	for (int i = 0; i < 3; ++i)
	{
		ret += static_cast <char> (0);
	}
	return ret;
}

