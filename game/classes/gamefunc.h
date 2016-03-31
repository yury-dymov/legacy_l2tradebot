#ifndef __GAME_FUNC__
#define __GAME_FUNC__

#include "../../data.h"
#include <string>

using namespace std;

class GameF
{   
	public:
		static Char charInfo (const string &);
		static int deleteObject (const string &);
		static Npc npcInfo (const string &);
		static User userInfo (const string & pck);
		static void moveToLocation (const string & pck, int * objectId, CatXPoint * from, CatXPoint * tp);
		static void moveToPawn (const string &, int *, int *, CatXPoint *, int *);
		static string npcHtmlMessage (const string &);
		static void stopMove (const string &, int *, CatXPoint *);
		static void privateStoreManageList (const string & pck, int * playerObjId, int * packSell, int * adena, vector <SellItem> * items);
		static void privateStoreBuyManageList (const string & pck, int * playerObjId, int * adena, vector <BuyItem> * items);
		static void privateStoreList (const string & pck, int * objectId, int * packSale, int * adena, vector <PlayerSellItem> * items);
		static void privateBuyListBuy (const string & pck, int * objectId, int * adena, vector <PlayerBuyItem> * items);
		static void tradeRequest (const string & pck, int * senderId);
		static void tradeStart (const string & pck, int * objectId, vector <TradeItem> * items);
		static void tradeOwnAdd (const string & pck, vector <TradeItem> *);
		static void tradeOtherAdd (const string & pck, vector <TradeItem> *);
		static void tradeDone (const string & pck, int * ret);
		static void buyList (const string & pck, int * adena, int * tradeId, vector <NpcSellItem> *);
		static void sellList (const string & pck, int * adena, int * tradeId, vector <NpcBuyItem> *);
		static void wareHouseDepositList (const string & pck, int * whtype, int * adena, vector <WarehouseItem> *);
		static void privateStoreMsg (const string & pck, int * objectId, string * msg);
		static void changeWaitType (const string & pck, int * objectId, int * waitType, CatXPoint * pos);
		static void recipeShopManageList (const string & pck, int * objectId, int * adena, int * isDwarven, vector <DwarfenManufactureItem> *, vector <DwarfenManufactureItem> *);
		static void say2 (const string & pck, int * objectId, int * type, string * charName, string * msg);
		static void systemMessage (const string & pck, int * msgId, vector <SystemItem> * items);
		static void gmHide (const string & pck, int * id);
		static void itemListPacket (const string & pck, int * window, vector <InventoryItem> * items);
		static void inventoryUpdate (const string & pck, vector <InventoryItem> * items);
		static void teleportToLocation (const string & pck, int * objectId, CatXPoint * pos);
		static void charSelect (const string & pck, vector <CharSelectItem> *);
		static void restartResponse (const string & pck, int * ok, string * msg);
		static void charTemplates (const string & pck, vector <CharTemplate> * chars);
		static void charCreateFail (const string & pck, int *);
		static void charCreateOk (const string & pck, int *);
		static void recipeShopSellList (const string & pck, int *, int *, int *, int *, vector <RecipeShopItem> *);
		static void recipeShopItemInfo (const string & pck, int *, int *, int *, int *);
};
#endif

