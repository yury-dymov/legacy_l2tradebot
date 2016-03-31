#include "gamepacket.h"

string GamePacket::requestItemList ()
{
	string ret;
	ret += E_C_GAME_REQUEST_ITEM_LIST;
	return ret;
}
