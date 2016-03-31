#include "loginpacket.h"

string LoginPacket::requestServerList (const string & sKey1)
{
	string ret;
	ret += E_LS_REQUEST_SERVER_LIST;
	ret += sKey1;
	ret += (char)4;
	for (int i = 0; i < 6; ++i)
	{
		ret += (char)0;
	}
	ret += checksum_ (ret);
	return ret;
}
