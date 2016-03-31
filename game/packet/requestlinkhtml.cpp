#include "gamepacket.h"

string GamePacket::requestLinkHtml (const string & str)
{
	string ret;
	ret += E_C_GAME_REQUEST_LINK_HTML;
	ret += str;
	return ret;
}
