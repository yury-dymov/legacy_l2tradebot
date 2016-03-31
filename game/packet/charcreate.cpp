#include "gamepacket.h"

string GamePacket::charCreate (const string & name, int sex, const CharTemplate & ch, int style, int color, int face)
{
	string ret;
	ret += E_C_GAME_CHAR_CREATE;
	ret += name;
	ret += DataFunc::intToString (ch.race);
	ret += DataFunc::intToString (sex);
	ret += DataFunc::intToString (ch.classId);
	ret += DataFunc::intToString (ch.intt);
	ret += DataFunc::intToString (ch.str);
	ret += DataFunc::intToString (ch.con);
	ret += DataFunc::intToString (ch.men);
	ret += DataFunc::intToString (ch.dex);
	ret += DataFunc::intToString (ch.wit);
	ret += DataFunc::intToString (style);
	ret += DataFunc::intToString (color);
	ret += DataFunc::intToString (face);
	return ret;
}

