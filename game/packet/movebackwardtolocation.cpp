#include "gamepacket.h"

string GamePacket::moveBackwardToLocation (const CatXPoint & next, const CatXPoint & cur)
{
	string ret;
	ret += E_C_GAME_MOVE_BACKWARD_TO_LOCATION;
	ret += DataFunc::intToString (static_cast <int> (next.x ()));
	ret += DataFunc::intToString (static_cast <int> (next.y ()));
	ret += DataFunc::intToString (static_cast <int> (next.x ()));
	ret += DataFunc::intToString (static_cast <int> (cur.x ()));
	ret += DataFunc::intToString (static_cast <int> (cur.y ()));
	ret += DataFunc::intToString (static_cast <int> (cur.z ()));
	ret += DataFunc::intToString (1);
	return ret;
}
