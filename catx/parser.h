#ifndef _CATX__PARSER_
#define _CATX__PARSER_

#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <stdlib.h>

#include "convert.h"
#include "catxfunc.h"

namespace CatX
{
	class Parser
	{
		private:
			std::map <std::string, std::string> data_;	
		public:
			Parser () {;}
			Parser (const char * filename);
			std::string getString (const std::string &);
			int getInt (const std::string &);
			double getDouble (const std::string &);
			std::vector <std::string> getVector (const std::string &, const char razdelitel);
	};
}

#endif
