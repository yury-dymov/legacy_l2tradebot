#include "catxfunc.h"

namespace CatX
{
	bool Func::mycmp (const std::string & str1, const std::string & str2, const unsigned int segm)
	{
		if (str2.length () <= str1.length () - segm)
		{
			for (unsigned int i = 0; i < str2.length (); ++i)
			{
				if (str1[segm + i] != str2[i])
				{
					return true;
				}
			}
			return false;
		}
		else
		{
			return true;
		}
	}

	bool Func::mycmp_to_lower (const std::string & str1, const std::string & str2, const unsigned int segm)
	{
		if (str2.length () <= str1.length () - segm)
		{
			for (unsigned int i = 0; i < str2.length (); ++i)
			{
				if (std::tolower (str1[segm + i]) != std::tolower (str2[i]))
				{
					return true;
				}
			}
			return false;
		}
		else
		{
			return true;
		}
	}


	unsigned int Func::skipComment (const std::string & str, const unsigned int i)
	{
		unsigned int j = i;
		for (; j < str.length (); ++j)
		{
			if (!mycmp (str, "*/", j))
			{
				j += 2;
				break;
			}
		}
		return j;
	}

	void Func::cx_write (FILE *f, const std::string & str, int encode)
	{
		if (encode == ANSI)
		{
			fprintf (f,"%s\r\n", str.c_str ());
		}
		else if (encode == UTF)
		{
			if (ftell (f) == 0)
			{
				fprintf (f, "%c%c", -1, -2);
			}
			std::string out;
			for (unsigned int i = 0; i < str.length (); ++i)
			{
				out += str[i];
				out += (char)0;
			}
			out += '\r';
			out += (char)0;
			out += '\n';
			out += (char)0;
			fwrite (out.c_str (), sizeof (char), out.length (), f);
		}
	}

	std::string Func::trim (const std::string & str)
	{
		unsigned int first = 0;
		unsigned int last = str.length ();
		if (last)
		{
			for (unsigned int i = 0; i < str.length (); ++i)
			{
				if (!isspace (str[i]))
				{
					first = i;
					break;
				}
			}
			for (unsigned int i = last - 1; i > 0; --i)
			{
				if (!isspace (str[i]))
				{
					last = i;
					break;
				}
			}
			if (last != str.length ())
			{
				std::string ret = str;
				if (isspace (ret[ret.length () - 1]))
				{
					return ret;
				}
				else
				{
					return ret;
				}
			}
			else
			{
				return str;
			}
			
		}
		else
		{
			return "";
		}
	}
}
