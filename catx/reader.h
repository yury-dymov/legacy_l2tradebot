#ifndef _CATX_READER_H__
#define _CATX_READER_H__

#include <vector>
#include <string> 
#include <iostream>
#include <stdlib.h>

namespace CatX
{
	class Reader3
	{
		private:
			std::string data_;		
			std::string fileName_;
			std::vector <unsigned int> next_;
			unsigned int currentPos_;
			unsigned int fileSize_;
			unsigned int getFileSize_ () const;
			FILE * fopen_ () const;
		public:
			Reader3 (const char * filename);
			void init ();
			std::string readNext ();
			double done () const;
	};
}

#endif
