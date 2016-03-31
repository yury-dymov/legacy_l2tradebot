#ifndef __SERVER_LIST_H__
#define __SERVER_LIST_H__

#include <string>
#include <vector>

#include "../../catx/convert.h"
#include "../../data.h"

using namespace std;
using namespace CatX;

class ServerList
{
	private:
		static string ip_ (const string &);
	public:
	        static vector <Server_s> data;
		static void init (const string & pck);
};

#endif
