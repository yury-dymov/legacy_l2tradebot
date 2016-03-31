#include "gamepacket.h"

string GamePacket::tradeDone (int response)
{
	string ret;
	ret += E_C_GAME_TRADE_DONE;
	ret += DataFunc::intToString (response);
	return ret;
}
