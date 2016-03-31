#include "gamepacket.h"

string GamePacket::validatePosition (const CatXPoint & pnt, const int heading, const int idata)
{
	string ret;
	ret += E_C_GAME_VALIDATE_POSITION;
	ret += DataFunc::intToString (static_cast <int> (pnt.x ()));
	ret += DataFunc::intToString (static_cast <int> (pnt.y ()));
	ret += DataFunc::intToString (static_cast <int> (pnt.z ()));
	ret += DataFunc::intToString (heading);
	ret += DataFunc::intToString (idata);
	return ret;
}

