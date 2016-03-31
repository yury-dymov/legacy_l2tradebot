#include "gamepacket.h"

string GamePacket::setPrivateStoreMsgBuy (const string & msg)
{
	string ret;
	ret += E_C_GAME_SET_PRIVATE_STORE_MSG_BUY;
	ret += msg;
	return ret;
}
