#include "gamepacket.h"

string GamePacket::action (const int objectId, const int x, const int y, const int z)
{
	string pck;
	pck += E_C_GAME_ACTION;
	pck += DataFunc::intToString (objectId);
	pck += DataFunc::intToString (x);
	pck += DataFunc::intToString (y);
	pck += DataFunc::intToString (z);
	pck += static_cast <char> (0);
	return pck;
}
