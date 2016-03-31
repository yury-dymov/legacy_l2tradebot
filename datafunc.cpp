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
			case 'À':
				ret += 0x10;
				ret += 0x04;
				break;
			case 'Á':
				ret += 0x11;
				ret += 0x04;
				break;
			case 'Â':
				ret += 0x12;
				ret += 0x04;
				break;
			case 'Ã':
				ret += 0x13;
				ret += 0x04;
				break;
			case 'Ä':
				ret += 0x14;
				ret += 0x04;
				break;
			case 'Å':
				ret += 0x15;
				ret += 0x04;
				break;
			case '¨':
				ret += 0x01;
				ret += 0x04;
				break;
			case 'Æ':
				ret += 0x16;
				ret += 0x04;
				break;
			case 'Ç':
				ret += 0x17;
				ret += 0x04;
				break;
			case 'È':
				ret += 0x18;
				ret += 0x04;
				break;
			case 'É':
				ret += 0x19;
				ret += 0x04;
				break;
			case 'Ê':
				ret += 0x1a;
				ret += 0x04;
				break;
			case 'Ë':
				ret += 0x1b;
				ret += 0x04;
				break;
			case 'Ì':
				ret += 0x1c;
				ret += 0x04;
				break;
			case 'Í':
				ret += 0x1d;
				ret += 0x04;
				break;
			case 'Î':
				ret += 0x1e;
				ret += 0x04;
				break;
			case 'Ï':
				ret += 0x1f;
				ret += 0x04;
				break;
			case 'Ğ':
				ret += 0x20;
				ret += 0x04;
				break;
			case 'Ñ':
				ret += 0x21;
				ret += 0x04;
				break;
			case 'Ò':
				ret += 0x22;
				ret += 0x04;
				break;
			case 'Ó':
				ret += 0x23;
				ret += 0x04;
				break;
			case 'Ô':
				ret += 0x24;
				ret += 0x04;
				break;
			case 'Õ':
				ret += 0x25;
				ret += 0x04;
				break;
			case 'Ö':
				ret += 0x26;
				ret += 0x04;
				break;
			case '×':
				ret += 0x27;
				ret += 0x04;
				break;
			case 'Ø':
				ret += 0x28;
				ret += 0x04;
				break;
			case 'Ù':
				ret += 0x29;
				ret += 0x04;
				break;
			case 'Ú':
				ret += 0x2a;
				ret += 0x04;
				break;
			case 'Û':
				ret += 0x2b;
				ret += 0x04;
				break;
			case 'Ü':
				ret += 0x2c;
				ret += 0x04;
				break;
			case 'İ':
				ret += 0x2d;
				ret += 0x04;
				break;
			case 'Ş':
				ret += 0x2e;
				ret += 0x04;
				break;
			case 'ß':
				ret += 0x2f;
				ret += 0x04;
				break;
			case 'à':
				ret += 0x30;
				ret += 0x04;
				break;
			case 'á':
				ret += 0x31;
				ret += 0x04;
				break;
			case 'â':
				ret += 0x32;
				ret += 0x04;
				break;
			case 'ã':
				ret += 0x33;
				ret += 0x04;
				break;
			case 'ä':
				ret += 0x34;
				ret += 0x04;
				break;
			case 'å':
				ret += 0x35;
				ret += 0x04;
				break;
			case '¸':
				ret += 0x51;
				ret += 0x04;
				break;
			case 'æ':
				ret += 0x36;
				ret += 0x04;
				break;
			case 'ç':
				ret += 0x37;
				ret += 0x04;
				break;
			case 'è':
				ret += 0x38;
				ret += 0x04;
				break;
			case 'é':
				ret += 0x39;
				ret += 0x04;
				break;
			case 'ê':
				ret += 0x3a;
				ret += 0x04;
				break;
			case 'ë':
				ret += 0x3b;
				ret += 0x04;
				break;
			case 'ì':
				ret += 0x3c;
				ret += 0x04;
				break;
			case 'í':
				ret += 0x3d;
				ret += 0x04;
				break;
			case 'î':
				ret += 0x3e;
				ret += 0x04;
				break;
			case 'ï':
				ret += 0x3f;
				ret += 0x04;
				break;
			case 'ğ':
				ret += 0x40;
				ret += 0x04;
				break;
			case 'ñ':
				ret += 0x41;
				ret += 0x04;
				break;
			case 'ò':
				ret += 0x42;
				ret += 0x04;
				break;
			case 'ó':
				ret += 0x43;
				ret += 0x04;
				break;
			case 'ô':
				ret += 0x44;
				ret += 0x04;
				break;
			case 'õ':
				ret += 0x45;
				ret += 0x04;
				break;
			case 'ö':
				ret += 0x46;
				ret += 0x04;
				break;
			case '÷':
				ret += 0x47;
				ret += 0x04;
				break;
			case 'ø':
				ret += 0x48;
				ret += 0x04;
				break;
			case 'ù':
				ret += 0x49;
				ret += 0x04;
				break;
			case 'ú':
				ret += 0x4a;
				ret += 0x04;
				break;
			case 'û':
				ret += 0x4b;
				ret += 0x04;
				break;
			case 'ü':
				ret += 0x4c;
				ret += 0x04;
				break;
			case 'ı':
				ret += 0x4d;
				ret += 0x04;
				break;
			case 'ş':
				ret += 0x4e;
				ret += 0x04;
				break;
			case 'ÿ':
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
					ret += 'À';
					break;
				case 0x11:
					ret += 'Á';
					break;
				case 0x12:
					ret += 'Â';
					break;
				case 0x13:
					ret += 'Ã';
					break;
				case 0x14:
					ret += 'Ä';
					break;
				case 0x15:
					ret += 'Å';
					break;
				case 0x01:
					ret += '¨';
					break;
				case 0x16:
					ret += 'Æ';
					break;
				case 0x17:
					ret += 'Ç';
					break;
				case 0x18:
					ret += 'È';
					break;
				case 0x19:
					ret += 'É';
					break;
				case 0x1a:
					ret += 'Ê';
					break;
				case 0x1b:
					ret += 'Ë';
					break;
				case 0x1c:
					ret += 'Ì';
					break;
				case 0x1d:
					ret += 'Í';
					break;
				case 0x1e:
					ret += 'Î';
					break;
				case 0x1f:
					ret += 'Ï';
					break;
				case 0x20:
					ret += 'Ğ';
					break;
				case 0x21:
					ret += 'Ñ';
					break;
				case 0x22:
					ret += 'Ò';
					break;
				case 0x23:
					ret += 'Ó';
					break;
				case 0x24:
					ret += 'Ô';
					break;
				case 0x25:
					ret += 'Õ';
					break;
				case 0x26:
					ret += 'Ö';
					break;
				case 0x27:
					ret += '×';
					break;
				case 0x28:
					ret += 'Ø';
					break;
				case 0x29:
					ret += 'Ù';
					break;
				case 0x2a:
					ret += 'Ú';
					break;
				case 0x2b:
					ret += 'Û';
					break;
				case 0x2c:
					ret += 'Ü';
					break;				
				case 0x2d:
					ret += 'İ';
					break;				
				case 0x2e:
					ret += 'Ş';
					break;				
				case 0x2f:
					ret += 'ß';
					break;				
				case 0x30:
					ret += 'à';
					break;
				case 0x31:
					ret += 'á';
					break;
				case 0x32:
					ret += 'â';
					break;
				case 0x33:
					ret += 'ã';
					break;
				case 0x34:
					ret += 'ä';
					break;
				case 0x35:
					ret += 'å';
					break;
				case 0x36:
					ret += 'æ';
					break;
				case 0x37:
					ret += 'ç';
					break;
				case 0x38:
					ret += 'è';
					break;
				case 0x39:
					ret += 'é';
					break;
				case 0x3a:
					ret += 'ê';
					break;
				case 0x3b:
					ret += 'ë';
					break;
				case 0x3c:
					ret += 'ì';
					break;
				case 0x3d:
					ret += 'í';
					break;
				case 0x3e:
					ret += 'î';
					break;
				case 0x3f:
					ret += 'ï';
					break;
				case 0x40:
					ret += 'ğ';
					break;
				case 0x41:
					ret += 'ñ';
					break;
				case 0x42:
					ret += 'ò';
					break;
				case 0x43:
					ret += 'ó';
					break;
				case 0x44:
					ret += 'ô';
					break;
				case 0x45:
					ret += 'õ';
					break;
				case 0x46:
					ret += 'ö';
					break;
				case 0x47:
					ret += '÷';
					break;
				case 0x48:
					ret += 'ø';
					break;
				case 0x49:
					ret += 'ù';
					break;
				case 0x4a:
					ret += 'ú';
					break;
				case 0x4b:
					ret += 'û';
					break;
				case 0x4c:
					ret += 'ü';
					break;
				case 0x4d:
					ret += 'ı';
					break;
				case 0x4e:
					ret += 'ş';
					break;
				case 0x4f:
					ret += 'ÿ';
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
