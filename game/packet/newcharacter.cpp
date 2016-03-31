#include "gamepacket.h"

string GamePacket::newCharacter ()
{
	string ret;
	ret += E_C_GAME_NEW_CHARACTER;
	return ret;
}
