#ifndef __GAME_PACKET__
#define __GAME_PACKET__

#include "../../debug.h"
#include "../../datafunc.h"
#include "../../b32.h"
#include "../../catxpoint.h"
#include "../../game_struct.h"
#include <string>

enum
{
	E_C_GAME_PROTOCOL_VERSION = 0x00,
	E_C_GAME_MOVE_BACKWARD_TO_LOCATION = 0x01,
	E_C_GAME_ENTER_WORLD = 0x03,
	E_C_GAME_ACTION = 0x04,
	E_C_GAME_AUTH_REQUEST = 0x08,
	E_C_GAME_REQUEST_LOGOUT = 0x09,
	E_C_GAME_CHAR_CREATE = 0x0b,
	E_C_GAME_CHAR_SELECTED = 0x0d,
	E_C_GAME_NEW_CHARACTER = 0x0e,
	E_C_GAME_REQUEST_ITEM_LIST = 0x0f,
	E_C_GAME_USE_ITEM = 0x14,
	E_C_GAME_TRADE_REQUEST = 0x15,
	E_C_GAME_ADD_TRADE_ITEM = 0x16, 
	E_C_GAME_TRADE_DONE = 0x17,
	E_C_GAME_REQUEST_SELL_ITEM = 0x1e,
	E_C_GAME_REQUEST_BUY_ITEM = 0x1f,
	E_C_GAME_REQUEST_LINK_HTML = 0x20,
	E_C_GAME_REQUEST_BYPASS_TO_SERVER = 0x21,
	E_C_GAME_APPEARING = 0x30,
	E_C_GAME_SEND_WAREHOUSE_DEPOSIT_LIST = 0x31,
	E_C_GAME_SEND_WAREHOUSE_WITHDRAW_LIST = 0x32,
	E_C_GAME_SAY2 = 0x38,
	E_C_GAME_ANSWER_TRADE_REQUEST = 0x44,
	E_C_GAME_REQUEST_ACTION_USE = 0x45,
	E_C_GAME_REQUEST_RESTART = 0x46,
	E_C_GAME_VALIDATE_POSITION = 0x48,
	E_C_GAME_REQUEST_DESTROY_ITEM = 0x59,
	E_C_GAME_SEND_BYPASS_BUILD_CMD = 0x5b,
	E_C_GAME_REQUEST_QUEST_LIST = 0x63,
	E_C_GAME_REQUEST_CRYSTALLIZE_ITEM = 0x72,
	E_C_GAME_REQUEST_PRIVATE_STORE_MANAGE = 0x73,
	E_C_GAME_SET_PRIVATE_STORE_LIST_SELL = 0x74,
	E_C_GAME_REQUEST_PRIVATE_STORE_QUIT = 0x76,
	E_C_GAME_SET_PRIVATE_STORE_MSG = 0x77,
	E_C_GAME_SEND_PRIVATE_STORE_BUY_LIST = 0x79,
	E_C_GAME_REQUEST_PRIVATE_STORE_MANAGE_BUY = 0x90,
	E_C_GAME_SET_PRIVATE_STORE_LIST_BUY = 0x91,
	E_C_GAME_REQUEST_PRIVATE_STORE_QUIT_BUY = 0x93,
	E_C_GAME_SET_PRIVATE_STORE_MSG_BUY = 0x94,
	E_C_GAME_SEND_PRIVATE_STORE_BUY_LIST_BUY = 0x96,
	E_C_GAME_REQUEST_ANSWER_FRIEND_INVITE = 0x5f,
	E_C_GAME_REQUEST_FRIEND_LIST = 0x60,
	E_C_GAME_NET_PING = 0xa8,
	E_C_GAME_REQUEST_RECIPE_SHOP_MESSAGE_SET = 0xb1,
	E_C_GAME_REQUEST_RECIPE_SHOP_LIST_SET = 0xb2,
	E_C_GAME_REQUEST_RECIPE_SHOP_MAKE_INFO = 0xb5,
	E_C_GAME_REQUEST_RECIPE_SHOP_MAKE_ITEM = 0xb6,
	E_C_GAME_REQUEST_RECIPE_SHOP_PREV = 0xb7,
	E_C_GAME_REQUEST_SEND_FRIEND_MSG = 0xCC,
	E_C_GAME_REQUEST_MANOR_LIST1 = 0xD0,
	E_C_GAME_REQUEST_MANOR_LIST2 = 0x08
};

enum
{
	E_ACTION_SIT_STAND = 0x00,
	E_ACTION_DWARFEN_MANUFACTURE = 0x25
};

using namespace std;

class GamePacket
{
	public:
		static string protocolVersion (const int protocol);
		static string moveBackwardToLocation (const CatXPoint & next, const CatXPoint & first);
		static string authRequest (const string & account, const string & sessionKey);
		static string charSelected (const int id);
		static string requestQuestList ();
		static string requestManorList ();
		static string enterWorld ();
		static string netPing (const string &);
		static string action (const int, const int, const int, const int);
		static string requestBypassToServer (const string &);
		static string requestLinkHtml (const string &);
		static string validatePosition (const CatXPoint & pos, const int heading, const int data = 0);
		static string requestPrivateStoreManage ();
		static string requestPrivateStoreQuit ();
		static string setPrivateStoreListSell (const string &);
		static string setPrivateStoreMsg (const string &);
		static string requestPrivateStoreManageBuy ();
		static string requestPrivateStoreQuitBuy ();
		static string setPrivateStoreListBuy (const string &);
		static string setPrivateStoreMsgBuy (const string &);
		static string sendPrivateStoreBuyList (int, const string &);
		static string sendPrivateStoreBuyListBuy (int, const string &);
		static string tradeRequest (int);
		static string answerTradeRequest (int answer);
		static string addTradeItem (int tradeId, int objectId, int count);
		static string tradeDone (int response);
		static string requestBuyItem (int saleId, const string & str);
		static string requestSellItem (int saleId, const string & str);
		static string sendWareHouseDepositList (const string & str);
		static string sendWareHouseWithdrawList (const string & str);
		static string requestActionUse (const int action, const int ctrl = 0, const int shift = 0);
		static string requestRecipeShopListSet (const string &);
		static string requestRecipeShopMessageSet (const string &);
		static string say2 (const string &, const int, const string & pm = "");
		static string sendBypassBuildCmd (const string & msg);
		static string appearing ();
		static string requestItemList ();
		static string useItem (int objectId, int d);
		static string requestRestart ();
		static string requestLogout ();
		static string requestDestroyItem (int, int);
		static string requestCrystallizeItem (int, int);
		static string newCharacter ();
		static string charCreate (const string & name, int sex, const CharTemplate & ch, int style, int color, int face);
		static string requestRecipeShopMakeInfo (int objectId, int recipeId);
		static string requestRecipeShopPrev (int objectId);
		static string requestRecipeShopMakeItem (int objectId, int recipeId, int un = 300);
};

class GameCrypt
{
	private:
		static string key1_;
		static string key2_;
	public:
		static void init (const string & key);
		static string encrypt (const string & packet);
		static string decrypt (const string & packet);
};


#endif
