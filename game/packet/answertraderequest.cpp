#include "gamepacket.h"

string GamePacket::answerTradeRequest (int answer)
{
	string ret;
	ret += E_C_GAME_ANSWER_TRADE_REQUEST;
	ret += DataFunc::intToString (answer);
	return ret;
}
