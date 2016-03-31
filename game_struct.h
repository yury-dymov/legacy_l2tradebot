#ifndef __GAME_STRUCT__
#define __GAME_STRUCT__

#include <vector>

enum
{
	E_LS_S_INIT = 0x00,
	E_LS_S_LOGIN_OK = 0x03,
	E_LS_S_RECIEVED_SERVER_LIST = 0x04,
	E_LS_S_PLAY_FAIL = 0x06,
	E_LS_S_PLAY_OK = 0x07
};

enum
{
	E_INVENTORY_NONE = 0x00,
	E_INVENTORY_ADD = 0x01,
	E_INVENTORY_MOD = 0x02,
	E_INVENTORY_REMOVE = 0x03
};

enum
{
	E_LD_LOGIN = 0x00,
	E_LD_SELECT_SERVER = 0x01,
	E_LD_OK = 0x02,
	E_LD_FAIL = 0x03
};

enum
{
	E_LD_LOGIN_PASS = 0x00,
	E_LD_SERVER = 0x01,
};

enum
{
	E_INFO_NPC = 0,
	E_INFO_PLAYER = 1,
	E_INFO_SELL = 2,
	E_INFO_BUY = 3,
	E_INFO_CRAFT = 4
};

enum
{
	SAY_ALL = 0,
	SAY_SHOUT = 1,
	SAY_PM = 2,
	SAY_PARTY = 3,
	SAY_CLAN = 4,
	SAY_TRADE = 8,
	SAY_ALLY = 9,
	SAY_ANNOUNCE = 10,
	SAY_HERO = 17
};

enum
{
	E_MAIN_MAP = 0,
	E_MAIN_CHAT = 1,
};

enum
{
	E_SYSTEM_STRING = 0x00,
	E_SYSTEM_ITEM_TYPE =0x03,
	E_SYSTEM_AMOUNT = 0x01,
};


struct TradeItem
{
	int itemType1;
	int objectId;
	int itemId;
	int count;
	int itemType2;
	int h1;
	int bodyPart;
	int enchantLevel;
	int h2;
	int h3;
};

struct PlayerBuyItem
{
	int objectId;
	int itemId;
	int enchant;
	int playerCount;
	int refPrice;
	int h1;
	int bodyPart;
	int type2;
	int buyersPrice;
	int count;
};

struct PlayerSellItem
{
	int type2;
	int objectId;
	int itemId;
	int count;
	int h1;
	int enchant;
	int h2;
	int bodyPart;
	int price;
	int storePrice;
};

struct SellItem
{
	int type2;
	int objectId;
	int itemId;
	int count;
	int h1;
	int enchant;
	int h2;
	int bodyPart;
	int price;
};

struct BuyItem
{
	int itemId;
	int h1;
	int count;
	int price;
	int h2;
	int bodyPart;
	int type2;
};

struct Item_
{
	int id;
	bool isCrystallizable;
	std::string name;
	std::string desc;
	std::string icon;	
	bool operator < (Item_ obj) {return obj.id < id;}
};

struct RecipeItem
{
	int itemId;
	int count;
};

struct Recipe_s
{
	std::vector <RecipeItem> items;
	int recipeId;
	int id;
	int level;
	int count;
	int itemId;
	int mpCost;
	int successRate;
};

struct Server_s
{
	int id;
	int port;
	std::string ip;
	bool online;
};

struct NpcSellItem
{
	int itemType1;
	int objectId;
	int itemId;
	int maxcnt;
	int itemType2;
	int h1;
	int itemBodyPart;
	int enchantLevel;
	int h2;
	int h3;
	int priceToSell;
};

struct NpcBuyItem
{
	int itemType1;
	int objectId;
	int itemId;
	int count;
	int itemType2;
	int h1;
	int itemBodyPart;
	int enchantLevel;
	int h2;
	int h3;
	int refPrice;
};

struct WarehouseItem
{
	int itemType1;
	int objectId;
	int itemId;
	int count;
	int itemType2;
	int h1;
	int bodyPart;
	int enchantLevel;
	int h2;
	int h3;
	int objectId2;
	int d1;
	int d2;
};

struct DwarfenManufactureItem
{
	int recipeId;
	int recipeNum;
	int d;
	int price;
};

struct SystemItem
{
	int type;
	std::string data;
};

struct InventoryItem
{
	int updateId;
	int itemType1;
	int objectId;
	int itemId;
	int itemType2;
	int custType1;
	int isEquipped;
	int bodyPart;
	int enchantLevel;
	int custType2;
	int augId;
	int shadowTime;
	int count;
};

struct CharSelectItem
{
	std::string name;
	int cls;
};

struct CharTemplate
{
	int race;
	int classId;
	int intt;
	int str;
	int con;
	int dex;
	int men;
	int wit;
};

struct RecipeShopItem
{
	int recipeId;
	int price;
};

#endif
