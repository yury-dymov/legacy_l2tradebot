#include "dat.h"

std::map <int, Item_> Dat::items_;
std::map <int, std::string> Dat::npcName_;
std::map <int, Recipe_s> Dat::recipe_;
std::map <int, std::string> Dat::systemMessage_;
std::map <int, std::string> Dat::serverName_;
std::map <int, std::string> Dat::className_;
std::map <int, std::string> Dat::sysstring_;

std::vector <std::string> Dat::read2_ (const std::string & str)
{
	std::vector <std::string> ret;
	std::string a;
	for (unsigned int i = 0; i < str.length (); ++i)
	{
		if (str[i] == '\t')
		{
			ret.push_back (a);
			a.clear ();
		}
		else if (str[i] == '\n')
		{
			break;
		}
		else
		{
			a += str[i];
		}
	}
	ret.push_back (a);
	while (ret.size () < 4)
	{
		ret.push_back ("");
	}
	return ret;
}

std::string Dat::npcName (const int id)
{
	return npcName_ [id - 1000000];
}

void Dat::initItems_ ()
{
	std::string grade [] = {"No Grade", "D", "C", "B", "A", "S"};
	std::string type [] = {"0", "Sword", "Blunt", "Dagger", "Spear", "Fist", "Bow", "Etc", "8"};
	std::string str;
	std::map <int, Item_> ret;
	CatX::Reader3 * myR = new CatX::Reader3 ("data/itemname.txt");
	myR->init ();
	myR->readNext ();
	while ((str = myR->readNext ()).length ())
	{
		std::vector <std::string> data = read2_ (str);
		int id = CatX::Convert (data[0]).toInt ();
		ret[id].id = id;
		ret[id].name = data [1] + " " + data [2];
		string pr;
		for (unsigned int i = 0; i < data[3].length (); ++i)
		{
			if (data[3].substr (i, 2) == "\\n")
			{
				pr += '\n';
				++i;
			}
			else
			{
				pr +=  data[3][i];
			}
		}
		ret[id].desc = pr;
	}
	items_ = ret;
	delete myR;
	CatX::Reader3 * myR4 = new CatX::Reader3 ("data/armorgrp.txt");
	myR4->init ();
	myR4->readNext ();
	while ((str = myR4->readNext ()).length ())
	{
		std::vector <std::string> data = read2_ (str);
		std::string desc;
		desc += "Grade: ";
		desc += grade [Convert (data [327]).toInt ()];
		desc += "\nP.def: ";
		desc += Convert (data[329]).toString ();
		desc += "\nM.def: ";
		desc += Convert (data[330]).toString ();
		desc += "\nWeight: ";
		desc += Convert (data[19]).toString ();
		desc += "\n";
		items_ [Convert (data[1]).toInt ()].desc = desc + items_ [Convert (data[1]).toInt ()].desc;
		items_ [Convert (data[1]).toInt ()].isCrystallizable = static_cast <bool> (Convert (data[21]).toInt ());
	}
	delete myR4;
	CatX::Reader3 * myR5 = new CatX::Reader3 ("data/weapongrp.txt");
	myR5->init ();
	myR5->readNext ();
	while ((str = myR5->readNext ()).length ())
	{
		std::vector <std::string> data = read2_ (str);
		std::string desc;
		desc += "Grade: ";
		desc += grade [Convert (data [44]).toInt ()];
		if (Convert (data[43]).toInt () < 9)
		{
			desc += "\nType: ";
			desc += type [Convert (data[43]).toInt ()];
		}
		desc += "\nP.attack: ";
		desc += Convert (data[41]).toString ();
		desc += "\nM.attack: ";
		desc += Convert (data[42]).toString ();
		desc += "\nSoulshot: ";
		desc += Convert (data[52]).toString ();
		desc += "\nSpiritshot: ";
		desc += Convert (data[53]).toString ();
		desc += "\nWeight: ";
		desc += Convert (data[19]).toString ();
		desc += "\n";
		items_ [Convert (data[1]).toInt ()].desc = desc + items_ [Convert (data[1]).toInt ()].desc;
		items_ [Convert (data[1]).toInt ()].isCrystallizable = static_cast <bool> (Convert (data[21]).toInt ());
	}
	delete myR5;
	CatX::Reader3 myR6 ("data/etcitem.txt");
	myR6.init ();
	myR6.readNext ();
	while ((str = myR6.readNext ()).length ())
	{
		std::vector <std::string> data = read2_ (str);
		std::string desc;
		desc += "Weight: ";
		desc += Convert (data[19]).toString ();
		desc += "\n";
		items_ [Convert (data[1]).toInt ()].desc = desc + items_ [Convert (data[1]).toInt ()].desc;
		items_ [Convert (data[1]).toInt ()].isCrystallizable = static_cast <bool> (Convert (data[21]).toInt ());
	}
}


std::string Dat::itemName (const int id)
{
	return items_ [id].name;
}

std::string Dat::itemDesc (const int id)
{
	return items_ [id].desc;
}

std::string Dat::itemIcon (const int id)
{
	return items_ [id].icon;
}

std::string Dat::recipeName (const int id)
{
	return Dat::itemName (recipe_ [id].recipeId);
}

Recipe_s Dat::recipe (const int id)
{
	return recipe_ [id];
}

void Dat::init ()
{
	initItems_ ();
	initNpc_ ();
	initRecipe_ ();
	initSystemMessage_ ();
	initServerName_ ();
	initClassName_ ();
	initSysstring_ ();
}

void Dat::initNpc_ ()
{
	std::map <int, Item_> ret;
	CatX::Reader3 myR ("data/npcname.txt");
	myR.init ();
	std::string str;
	while ((str = myR.readNext ()).length ())
	{
		std::vector <std::string> data = read2_ (str);
		int id = CatX::Convert (data[0]).toInt ();
		npcName_ [id] = data [1];
	}
}

void Dat::initRecipe_ ()
{
	CatX::Reader3 myR ("data/recipe.txt");
	myR.init ();
	myR.readNext ();
	std::string str;
	while ((str = myR.readNext ()).length ())
	{
		std::vector <std::string> data = read2_ (str);
		Recipe_s elem;
		elem.id = CatX::Convert (data[1]).toInt ();
		elem.recipeId = CatX::Convert (data[2]).toInt ();
		elem.level = CatX::Convert (data[3]).toInt ();
		elem.itemId = CatX::Convert (data[4]).toInt ();
		elem.count = CatX::Convert (data[5]).toInt ();
		elem.mpCost = CatX::Convert (data[6]).toInt ();
		elem.successRate = CatX::Convert (data[7]).toInt ();
		int count = CatX::Convert (data[8]).toInt ();
		for (int i = 0; i < count; ++i)
		{
			RecipeItem ritem;
			ritem.itemId = CatX::Convert (data [9 + 2 * i]).toInt ();
			ritem.count = CatX::Convert (data [10 + 2 * i]).toInt ();
			elem.items.push_back (ritem);
		}
		recipe_ [elem.id] = elem;
	}
}

void Dat::initSystemMessage_ ()
{
	CatX::Reader3 myR ("data/systemmsg.txt");
	myR.init ();
	myR.readNext ();
	std::string str;
	while ((str = myR.readNext ()).length ())
	{
		vector <string> data = read2_ (str);
		systemMessage_ [CatX::Convert (data[0]).toInt ()] = data [2];
	}
}

std::string Dat::buildSystemMessage (int id, const vector <SystemItem> & items)
{
	std::string ret;
	std::string msg = systemMessage_ [id];
	for (unsigned int i = 0; i < msg.length (); ++i)
	{
		if (msg[i] == '$')
		{
			std::string num;
			i += 1;
			while (isdigit (msg[++i]))
			{
				num += msg[i];
			}
			--i;
			unsigned int id = static_cast <unsigned int> (CatX::Convert (num).toInt ());
			if (id > items.size ())
			{
				id = items.size ();
			}
			switch (items[id - 1].type)
			{
				case E_SYSTEM_AMOUNT:
					ret+= CatX::Convert (DataFunc::stringToInt (items[id - 1].data, 0)).toString ();
					break;
				case E_SYSTEM_ITEM_TYPE:
					ret += itemName (DataFunc::stringToInt (items[id - 1].data, 0));
					break;
				case E_SYSTEM_STRING:
					ret += DataFunc::encodeFrom (items[id - 1].data);
					break;
				default:
					printf ("Unknown system type %d\n", items[id - 1].type);
					break;
			}
		}
		else
		{
			ret += msg[i];
		}
	}
	return ret;
}

std::string Dat::serverName (const int id)
{
	return serverName_ [id];
}

void Dat::initServerName_ ()
{
	CatX::Reader3 myR ("data/servername.txt");
	myR.init ();
	std::string str;
	while ((str = myR.readNext ()).length ())
	{
		std::vector <std::string> data = read2_ (str);
		int id = CatX::Convert (data[0]).toInt ();
		serverName_ [id] = data [2];
	}
}

void Dat::initClassName_ ()
{
	CatX::Reader3 myR ("data/class.txt");
	myR.init ();
	std::string str;
	while ((str = myR.readNext ()).length ())
	{
		std::vector <std::string> data = read2_ (str);
		int id = CatX::Convert (data[0]).toInt ();
		className_ [id] = data [1];
	}
}

std::string Dat::className (int id)
{
	return className_ [id];
}

void Dat::initSysstring_ ()
{
	CatX::Reader3 myR ("data/sysstring.txt");
	myR.init ();
	std::string str;
	while ((str = myR.readNext ()).length ())
	{
		std::vector <std::string> data = read2_ (str);
		int id = CatX::Convert (data[0]).toInt ();
		sysstring_ [id] = data [1];
	}
}

std::string Dat::sysstring (const int id)
{
	return sysstring_ [id];
}

bool Dat::itemCrystallizable (const int id)
{
	return items_[id].isCrystallizable;
}
