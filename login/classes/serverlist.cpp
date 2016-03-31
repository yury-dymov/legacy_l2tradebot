#include "serverlist.h"

vector <Server_s> ServerList::data;

void ServerList::init (const string & pck)
{
	data.clear ();
	// 0 - packet_id
	// 1 - server num
	// 2 - not used

	// i + 3 - server id
	// i + 4 - server ip
	// i + 8 - server port
	// i + 12 - age limit
	// i + 13 - pvp server
	// i + 14 - online
	// i + 16 - max online
	// i + 18 - is active
	union b32
	{
		unsigned long word;
		unsigned char byte[4];
	};
	for (unsigned int i = 0; i < static_cast <unsigned char> (pck[1]); ++i)
	{
		Server_s serv;
		serv.id = pck [i + 3];
		serv.ip = ip_ (pck.substr (i + 4, 4));		
		b32 port;
		for (unsigned int j = 0; j < 4; ++j)
		{
			port.byte[j] = pck[i + 8 + j];
		}
		serv.port = port.word;
		serv.online = pck[i + 18];
		data.push_back (serv);
	}
}

string ServerList::ip_ (const string & pck)
{
	string ret;
	for (unsigned int i = 0; i < 4; ++i)
	{
		ret += Convert (static_cast <int> (static_cast <unsigned char> (pck[i]))).toString ();
		if (i != 3)
		{
			ret += '.';
		}
	}
	return ret;
}


