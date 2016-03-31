#include "datafunc.h"

std::string DataFunc::intToString (const int num, int count)
{
	b32 data;
	data.word = num;
	std::string ret;
	for (int i = 0; i < count; ++i)
	{
		ret += data.byte[i];
	}
	return ret;
}

int DataFunc::stringToInt (const std::string & str, int segm, int count)
{
	b32 data;
	data.word = 0;
	for (int i = 0; i < count; ++i)
	{
		data.byte[i] = str[static_cast <unsigned int> (i + segm)];
	}
	return data.word;
}

std::string DataFunc::number (const int num)
{
	std::string str = CatX::Convert (num).toString ();
	std::string ret;
	for (unsigned int i = 0; i < str.length (); ++i)
	{
		if (i && (str.length () - i) % 3 == 0)
		{
			ret += ',';
		}
		ret += str[i];
	}	
	return ret;
}

int DataFunc::toNumber (const std::string & str)
{
	std::string ret;
	for (unsigned int i = 0; i < str.length (); ++i)
	{
		if (str[i] != ',')
		{
			ret += str[i];
		}
	}
	return CatX::Convert (ret).toInt ();
}

std::string DataFunc::encodeTo (const std::string & str)
{
	std::string ret;
	for (unsigned int i = 0; i < str.length (); ++i)
	{
		switch (str[i])
		{
			case '�':
				ret += 0x10;
				ret += 0x04;
				break;
			case '�':
				ret += 0x11;
				ret += 0x04;
				break;
			case '�':
				ret += 0x12;
				ret += 0x04;
				break;
			case '�':
				ret += 0x13;
				ret += 0x04;
				break;
			case '�':
				ret += 0x14;
				ret += 0x04;
				break;
			case '�':
				ret += 0x15;
				ret += 0x04;
				break;
			case '�':
				ret += 0x01;
				ret += 0x04;
				break;
			case '�':
				ret += 0x16;
				ret += 0x04;
				break;
			case '�':
				ret += 0x17;
				ret += 0x04;
				break;
			case '�':
				ret += 0x18;
				ret += 0x04;
				break;
			case '�':
				ret += 0x19;
				ret += 0x04;
				break;
			case '�':
				ret += 0x1a;
				ret += 0x04;
				break;
			case '�':
				ret += 0x1b;
				ret += 0x04;
				break;
			case '�':
				ret += 0x1c;
				ret += 0x04;
				break;
			case '�':
				ret += 0x1d;
				ret += 0x04;
				break;
			case '�':
				ret += 0x1e;
				ret += 0x04;
				break;
			case '�':
				ret += 0x1f;
				ret += 0x04;
				break;
			case '�':
				ret += 0x20;
				ret += 0x04;
				break;
			case '�':
				ret += 0x21;
				ret += 0x04;
				break;
			case '�':
				ret += 0x22;
				ret += 0x04;
				break;
			case '�':
				ret += 0x23;
				ret += 0x04;
				break;
			case '�':
				ret += 0x24;
				ret += 0x04;
				break;
			case '�':
				ret += 0x25;
				ret += 0x04;
				break;
			case '�':
				ret += 0x26;
				ret += 0x04;
				break;
			case '�':
				ret += 0x27;
				ret += 0x04;
				break;
			case '�':
				ret += 0x28;
				ret += 0x04;
				break;
			case '�':
				ret += 0x29;
				ret += 0x04;
				break;
			case '�':
				ret += 0x2a;
				ret += 0x04;
				break;
			case '�':
				ret += 0x2b;
				ret += 0x04;
				break;
			case '�':
				ret += 0x2c;
				ret += 0x04;
				break;
			case '�':
				ret += 0x2d;
				ret += 0x04;
				break;
			case '�':
				ret += 0x2e;
				ret += 0x04;
				break;
			case '�':
				ret += 0x2f;
				ret += 0x04;
				break;
			case '�':
				ret += 0x30;
				ret += 0x04;
				break;
			case '�':
				ret += 0x31;
				ret += 0x04;
				break;
			case '�':
				ret += 0x32;
				ret += 0x04;
				break;
			case '�':
				ret += 0x33;
				ret += 0x04;
				break;
			case '�':
				ret += 0x34;
				ret += 0x04;
				break;
			case '�':
				ret += 0x35;
				ret += 0x04;
				break;
			case '�':
				ret += 0x51;
				ret += 0x04;
				break;
			case '�':
				ret += 0x36;
				ret += 0x04;
				break;
			case '�':
				ret += 0x37;
				ret += 0x04;
				break;
			case '�':
				ret += 0x38;
				ret += 0x04;
				break;
			case '�':
				ret += 0x39;
				ret += 0x04;
				break;
			case '�':
				ret += 0x3a;
				ret += 0x04;
				break;
			case '�':
				ret += 0x3b;
				ret += 0x04;
				break;
			case '�':
				ret += 0x3c;
				ret += 0x04;
				break;
			case '�':
				ret += 0x3d;
				ret += 0x04;
				break;
			case '�':
				ret += 0x3e;
				ret += 0x04;
				break;
			case '�':
				ret += 0x3f;
				ret += 0x04;
				break;
			case '�':
				ret += 0x40;
				ret += 0x04;
				break;
			case '�':
				ret += 0x41;
				ret += 0x04;
				break;
			case '�':
				ret += 0x42;
				ret += 0x04;
				break;
			case '�':
				ret += 0x43;
				ret += 0x04;
				break;
			case '�':
				ret += 0x44;
				ret += 0x04;
				break;
			case '�':
				ret += 0x45;
				ret += 0x04;
				break;
			case '�':
				ret += 0x46;
				ret += 0x04;
				break;
			case '�':
				ret += 0x47;
				ret += 0x04;
				break;
			case '�':
				ret += 0x48;
				ret += 0x04;
				break;
			case '�':
				ret += 0x49;
				ret += 0x04;
				break;
			case '�':
				ret += 0x4a;
				ret += 0x04;
				break;
			case '�':
				ret += 0x4b;
				ret += 0x04;
				break;
			case '�':
				ret += 0x4c;
				ret += 0x04;
				break;
			case '�':
				ret += 0x4d;
				ret += 0x04;
				break;
			case '�':
				ret += 0x4e;
				ret += 0x04;
				break;
			case '�':
				ret += 0x4f;
				ret += 0x04;
				break;
			default:
				ret += str[i];
				ret += static_cast <char> (0);
				break;
		}
	}
	ret += static_cast <char> (0);
	ret += static_cast <char> (0);
	return ret;
}

std::string DataFunc::encodeFrom (const std::string & str)
{
	std::string ret;
	for (unsigned int i = 0; i < str.length () - 2; i += 2)
	{
		if (str[i + 1] == static_cast <char> (0))
		{
			ret += str[i];
		}
		else
		{
			switch (str[i])
			{
				case 0x00:
				case 0x04:
					break;
				case 0x10:
					ret += '�';
					break;
				case 0x11:
					ret += '�';
					break;
				case 0x12:
					ret += '�';
					break;
				case 0x13:
					ret += '�';
					break;
				case 0x14:
					ret += '�';
					break;
				case 0x15:
					ret += '�';
					break;
				case 0x01:
					ret += '�';
					break;
				case 0x16:
					ret += '�';
					break;
				case 0x17:
					ret += '�';
					break;
				case 0x18:
					ret += '�';
					break;
				case 0x19:
					ret += '�';
					break;
				case 0x1a:
					ret += '�';
					break;
				case 0x1b:
					ret += '�';
					break;
				case 0x1c:
					ret += '�';
					break;
				case 0x1d:
					ret += '�';
					break;
				case 0x1e:
					ret += '�';
					break;
				case 0x1f:
					ret += '�';
					break;
				case 0x20:
					ret += '�';
					break;
				case 0x21:
					ret += '�';
					break;
				case 0x22:
					ret += '�';
					break;
				case 0x23:
					ret += '�';
					break;
				case 0x24:
					ret += '�';
					break;
				case 0x25:
					ret += '�';
					break;
				case 0x26:
					ret += '�';
					break;
				case 0x27:
					ret += '�';
					break;
				case 0x28:
					ret += '�';
					break;
				case 0x29:
					ret += '�';
					break;
				case 0x2a:
					ret += '�';
					break;
				case 0x2b:
					ret += '�';
					break;
				case 0x2c:
					ret += '�';
					break;				
				case 0x2d:
					ret += '�';
					break;				
				case 0x2e:
					ret += '�';
					break;				
				case 0x2f:
					ret += '�';
					break;				
				case 0x30:
					ret += '�';
					break;
				case 0x31:
					ret += '�';
					break;
				case 0x32:
					ret += '�';
					break;
				case 0x33:
					ret += '�';
					break;
				case 0x34:
					ret += '�';
					break;
				case 0x35:
					ret += '�';
					break;
				case 0x36:
					ret += '�';
					break;
				case 0x37:
					ret += '�';
					break;
				case 0x38:
					ret += '�';
					break;
				case 0x39:
					ret += '�';
					break;
				case 0x3a:
					ret += '�';
					break;
				case 0x3b:
					ret += '�';
					break;
				case 0x3c:
					ret += '�';
					break;
				case 0x3d:
					ret += '�';
					break;
				case 0x3e:
					ret += '�';
					break;
				case 0x3f:
					ret += '�';
					break;
				case 0x40:
					ret += '�';
					break;
				case 0x41:
					ret += '�';
					break;
				case 0x42:
					ret += '�';
					break;
				case 0x43:
					ret += '�';
					break;
				case 0x44:
					ret += '�';
					break;
				case 0x45:
					ret += '�';
					break;
				case 0x46:
					ret += '�';
					break;
				case 0x47:
					ret += '�';
					break;
				case 0x48:
					ret += '�';
					break;
				case 0x49:
					ret += '�';
					break;
				case 0x4a:
					ret += '�';
					break;
				case 0x4b:
					ret += '�';
					break;
				case 0x4c:
					ret += '�';
					break;
				case 0x4d:
					ret += '�';
					break;
				case 0x4e:
					ret += '�';
					break;
				case 0x4f:
					ret += '�';
					break;

			}	
		}
	}
	return ret;
}


/*
std::string DataFunc::encodeTo (const std::string & str)
{
	std::string ret;
	for (unsigned int i = 0; i < str.length (); ++i)
	{
		ret += str[i];
		ret += static_cast <char> (0);
	}
	ret += static_cast <char> (0);
	ret += static_cast <char> (0);
	return ret;
}

std::string DataFunc::encodeFrom (const std::string & str)
{
	std::string ret;
	for (unsigned int i = 0; i < str.length (); i += 2)
	{
		if (str[i] == static_cast <char> (0))
		{
			break;
		}
		else
		{
			ret += str[i];
		}
	}
	return ret;
}*/
