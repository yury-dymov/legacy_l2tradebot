#ifndef __LOGIN_PACKET__
#define __LOGIN_PACKET__

#include <string>
#include "../../data.h"

using namespace std;

class LoginPacket
{
	private:
		enum
		{
			E_LS_REQUEST_AUTH_LOGIN = 0,
			E_LS_REQUEST_SERVER_LOGIN = 2,
			E_LS_REQUEST_SERVER_LIST = 5
		};	
		static string checksum_ (const string & raw);
	public:
		static string requestAuthLogin (const string &, const string &);
		static string requestServerLogin (const string & sKey1, const int id);
		static string requestServerList (const string & sKey1);
		static string key1;
};


#endif
