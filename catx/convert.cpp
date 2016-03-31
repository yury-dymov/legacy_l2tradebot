#include "convert.h"

/*
	Часть библиотеки CatX. Увы, автор не стал документировать
	её.
*/


namespace CatX
{
	Convert::Convert (std::string value)
	{
		value_ = value;
	}
	
	Convert::Convert (double val)
	{
		char a[200];
		sprintf (a, "%g", val);
		value_ += a;
	}

	Convert::Convert (int num)
	{
		value_ = "";
		if (num == 0)
		{
			value_ = "0";
		}
		else
		{
			char a[200];
			sprintf (a, "%d", num);
			value_ += a;
		}
	}
	
	int Convert::toInt ()
	{
		int ret;
		sscanf (value_.c_str (), "%d", &ret);
		return ret;
	}

	std::string Convert::toString ()
	{
		return value_;
	}

	double Convert::toDouble ()
	{
		return 0;
	}
}
