#include "gamepacket.h"

string GamePacket::charSelected (const int id)
{
	string ret;
	ret += E_C_GAME_CHAR_SELECTED;
	ret += static_cast <char> (id);
	for (int i = 0; i < 17; ++i)
	{
		ret += static_cast <char> (0);
	}
	return ret;
}
