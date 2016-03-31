#include "loginpacket.h"

string LoginPacket::requestServerLogin (const string & sKey1, const int id)
{
	string ret;
	ret += E_LS_REQUEST_SERVER_LOGIN;
	ret += sKey1;
	ret += (char)id;
	for (int i = 0; i < 6; ++i)
	{
		ret += (char)0;
	}
	ret += checksum_ (ret);
	return ret;
}

