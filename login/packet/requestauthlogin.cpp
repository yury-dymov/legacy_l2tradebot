#include "loginpacket.h"

string LoginPacket::requestAuthLogin (const string & glogin, const string & gpass)
{
	string ret;
	string login = glogin;
	string pass = gpass;
	ret += E_LS_REQUEST_AUTH_LOGIN;
	if (login.length () > 14)
	{
		login = login.substr (0, 14);
	}
	while (login.length () != 14)
	{
		login += (char) 0;
	}
	if (pass.length () > 16)
	{
		pass = pass.substr (0, 16);
	}
	while (pass.length () != 16)
	{
		pass += (char) 0;
	}
	ret += login;
	ret += pass;
	ret += (char)8;
	for (int i = 0; i < 8; ++i)
	{
		ret += (char)0;
	}
	ret += checksum_ (ret);
	return ret;
}
