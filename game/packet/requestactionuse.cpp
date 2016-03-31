#include "gamepacket.h"

string GamePacket::requestActionUse (const int action, const int ctrl, const int shift)
{
	string ret;
	ret += E_C_GAME_REQUEST_ACTION_USE;
	ret += DataFunc::intToString (action);
	ret += DataFunc::intToString (ctrl);
	ret += static_cast <char> (shift);
	return ret;
}

