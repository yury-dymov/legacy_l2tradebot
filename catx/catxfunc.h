#ifndef __CATX_FUNC_H__
#define __CATX_FUNC_H__

#include <string>

namespace CatX
{

	#define ANSI 0
	#define UTF 1

	class Func
	{
		public:
			static bool mycmp (const std::string &str, const std::string &, const unsigned int segm);
			static bool mycmp_to_lower (const std::string &str, const std::string &, const unsigned int segm);
			static unsigned int skipComment (const std::string & str, const unsigned int i);			
			static void cx_write (FILE *f, const char * str, const unsigned int length, int encode);
			static void cx_write (FILE *f, const std::string & str, int encode);
			static std::string trim (const std::string &);
			static std::string deleteComment (const std::string & str);
	};
}

#endif
