#include "gamepacket.h"

string GamePacket::requestQuestList ()
{
	string ret;
	ret += E_C_GAME_REQUEST_QUEST_LIST;
	return ret;
}
