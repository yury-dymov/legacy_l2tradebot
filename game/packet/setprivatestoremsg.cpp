#include "gamepacket.h"

string GamePacket::setPrivateStoreMsg (const string & str)
{
	string ret;
	ret += E_C_GAME_SET_PRIVATE_STORE_MSG;
	ret += str;
	return ret;
}
