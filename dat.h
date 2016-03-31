#ifndef __DAT_H__
#define __DAT_H__

#include <string>
#include <map>
#include <vector>

#include "game_struct.h"
#include "datafunc.h"
#include "catx/reader.h"
#include "catx/convert.h"

using namespace std;
using namespace CatX;

class Dat
{
	private:
		static std::map <int, std::string> sysstring_;
		static std::map <int, std::string> className_;
		static std::map <int, std::string> serverName_;
		static std::map <int, Item_> items_;
		static std::map <int, std::string> npcName_;
		static std::map <int, Recipe_s> recipe_;
		static std::map <int, std::string> systemMessage_;
		static std::vector <std::string> read2_ (const std::string &);
		static void initItems_ ();
		static void initNpc_ ();
		static void initRecipe_ ();
		static void initSystemMessage_ ();
		static void initServerName_ ();
		static void initClassName_ ();
		static void initSysstring_ ();
	public:
		static std::string sysstring (const int);
		static std::string className (const int);
		static std::string serverName (const int);
		static std::string itemName (const int);
		static std::string itemDesc (const int);
		static std::string itemIcon (const int);
		static bool itemCrystallizable (const int);
		static std::string npcName (const int);
		static std::string recipeName (const int);
		static void init ();
		static std::string buildSystemMessage (int id, const vector <SystemItem> &);
		static Recipe_s recipe (const int id);
};

#endif
