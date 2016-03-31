#include "gamepacket.h"

string GamePacket::sendBypassBuildCmd (const string & msg)
{
	string ret;
	ret += E_C_GAME_SEND_BYPASS_BUILD_CMD;
	ret += msg;
	return ret;
}
