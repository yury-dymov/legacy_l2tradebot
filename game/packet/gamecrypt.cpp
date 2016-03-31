#include "gamepacket.h"

void GameCrypt::init (const string & key)
{
	string newKey;
	for (int i = 0; i < 8; ++i)
	{
		newKey += key [i];
	}
	newKey += 0xc8;
	newKey += 0x27;
	newKey += 0x93;
	newKey += 0x01;
	newKey += 0xa1;
	newKey += 0x6c;
	newKey += 0x31;
	newKey += 0x97;
	key1_ = newKey;
	key2_ = newKey;
}


string GameCrypt::encrypt (const std::string & pck)
{
	string str = pck;
	str[0]^= key1_[0];
	for (unsigned int i = 1; i < str.length (); ++i)
	{
		str[i] ^= key1_[i & 0x0f] ^ str[i - 1];
	}
	b32 a;
	for (unsigned int i = 0; i < 4; ++i)
	{
		a.byte[i] = key1_[i + 8];
	}
	a.word += str.length ();
	for (int i = 0; i < 4; ++i)
	{
		key1_[i + 8] = a.byte[i];
	}
	return str;
}

string GameCrypt::decrypt (const string & str)
{
	string pck = str;
	unsigned char j = 0;
	for (unsigned int i = 0; i < pck.length (); ++i)
	{
		unsigned char tmp = pck[i];
		pck[i] = tmp ^ (unsigned char)(key2_[i & 0x0f]) ^ j;
		j = tmp;
	}
	b32 old;
	for (int i = 0; i < 4; ++i)
	{
		old.byte[i] = key2_[i + 8];
	}
	old.word += str.length ();
	for (int i = 0; i < 4; ++i)
	{
		key2_[i + 8] = old.byte[i];
	}
	return pck;
}

string GameCrypt::key1_;
string GameCrypt::key2_;


