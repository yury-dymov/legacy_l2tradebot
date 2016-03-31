#include "loginpacket.h"

string LoginPacket::checksum_ (const string & raw)
{
	b32 chksum;
	chksum.word = 0;
	unsigned char * a = new unsigned char [raw.length ()];
	for (unsigned int i = 0; i < raw.length (); ++i)
	{
		a[i] = raw[i];
	}
	for (unsigned int i = 0; i < raw.length (); i += 4 )
	{
		chksum.word ^= *((unsigned long *)&a[i]);
	}
	delete [] a;
	string ret;
	for (int i = 0; i < 4; ++i)
	{
		ret += chksum.byte [i];
	}
	return ret;
}

string LoginPacket::key1;


