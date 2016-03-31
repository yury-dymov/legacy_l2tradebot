/*
	Часть библиотеки CatX. Увы, автор не стал документировать
	её.
*/

#ifndef __convert__
#define __convert__

#include <string>
#include <iostream>

namespace CatX
{
	class Convert 
	{
		private:
			std::string value_;
		public:
			Convert (std::string value);
			Convert (int);
			Convert (double);
			int toInt ();
			std::string toString ();
			double toDouble ();
	};
}
#endif
