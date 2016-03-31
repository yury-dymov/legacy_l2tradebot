#ifndef __DATA_FUNC__
#define __DATA_FUNC__

#include <string>
#include "catx/convert.h"
#include "b32.h"

using namespace CatX;

class DataFunc
{
	public:
		static std::string intToString (const int num, int count = 4);
		static int stringToInt (const std::string & str, int segm, int count = 4);
		static std::string number (const int);
		static int toNumber (const std::string &);
		static std::string encodeTo (const std::string &);
		static std::string encodeFrom (const std::string &);
};

#endif
