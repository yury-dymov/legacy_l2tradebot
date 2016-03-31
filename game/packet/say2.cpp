#include "gamepacket.h"

string GamePacket::say2 (const string & msg, const int type, const string & pm)
{
	string ret;
	ret += E_C_GAME_SAY2;
	ret += msg;
	ret += DataFunc::intToString (type);
	if (pm.length ())
	{
		ret += pm;
	}
	return ret;
}
