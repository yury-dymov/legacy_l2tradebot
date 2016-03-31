#ifndef __GAME_THREAD_H__
#define __GAME_THREAD_H__

#include <QThread>
#include <QTimer>
#include <QTcpSocket>
#include <QErrorMessage>

#include "../data.h"

#include "../debug.h"

#include "../catx/convert.h"

#include "packet/gamepacket.h"

#include "../login/classes/logindata.h"
#include "../classes/map_scene.h"

#include "classes/gamefunc.h"
#include "../dialog/dialog.h"

using namespace std;
using namespace CatX;

enum
{
	E_S_GAME_KEY = 0x00,
	E_S_GAME_MOVE_TO_LOCATION = 0x01,
	E_S_GAME_CHARINFO = 0x03,
	E_S_GAME_USERINFO = 0x04,
	E_S_GAME_NPC_HTML_MESSAGE = 0x0f,
	E_S_GAME_SELL_LIST = 0x10, 
	E_S_GAME_BUY_LIST = 0x11,
	E_S_GAME_DELETE_OBJECT = 0x12,
	E_S_GAME_CHAR_SELECT = 0x13,
	E_S_GAME_CHAR_SELECTED = 0x15,
	E_S_GAME_NPCINFO = 0x16,
	E_S_GAME_CHAR_TEMPLATES = 0x17,
	E_S_GAME_CHAR_CREATE_FAIL = 0x1a,
	E_S_GAME_ITEM_LIST_PACKET = 0x1b,
	E_S_GAME_TRADE_START = 0x1e,
	E_S_GAME_TRADE_OWN_ADD = 0x20,
	E_S_GAME_TRADE_OTHER_ADD = 0x21,
	E_S_GAME_TRADE_DONE = 0x22,
	E_S_GAME_ACTION_FAIL = 0x25,
	E_S_GAME_INVENTORY_UPDATE = 0x27,
	E_S_GAME_TELEPORT_TO_LOCATION = 0x28,
	E_S_GAME_SOCIAL_ACTION = 0x2d,
	E_S_GAME_CHANGE_WAIT_TYPE = 0x2f,
	E_S_GAME_WAREHOUSE_DEPOSIT_LIST = 0x41,
	E_S_GAME_WAREHOUSE_WITHDRAW_LIST = 0x42,
	E_S_GAME_STOP_MOVE = 0x47,
	E_S_GAME_SAY2 = 0x4A,
	E_S_GAME_TRADE_REQUEST = 0x5e,
	E_S_GAME_RESTART_RESPONSE = 0x5f,
	E_S_GAME_MOVE_TO_PAWN = 0x60,
	E_S_GAME_FINISH_ROTATING = 0x63,
	E_S_GAME_SYSTEM_MESSAGE = 0x64,
	E_S_GAME_TRADE_PRESS_OWN_OK = 0x75,
	E_S_GAME_TRADE_PRESS_OTHER_OK = 0x7c,
	E_S_GAME_LOGOUT_OK = 0x7e,
	E_S_GAME_QUEST_LIST = 0x80,
	E_S_GAME_GM_HIDE = 0x8d,
	E_S_GAME_PRIVATE_STORE_MANAGE_LIST = 0x9a,
	E_S_GAME_PRIVATE_STORE_LIST = 0x9b,
	E_S_GAME_PRIVATE_STORE_MSG = 0x9c,
	E_S_GAME_PRIVATE_STORE_BUY_MANAGE_LIST = 0xb7,
	E_S_GAME_PRIVATE_BUY_LIST_BUY = 0xb8,
	E_S_GAME_PRIVATE_STORE_MSG_BUY = 0xb9,
	E_S_GAME_NET_PING = 0xd3,
	E_S_GAME_RECIPE_SHOP_MANAGE_LIST = 0xd8,
	E_S_GAME_RECIPE_SHOP_SELL_LIST = 0xd9,
	E_S_GAME_RECIPE_SHOP_ITEM_INFO = 0xda,
	E_S_GAME_RECIPE_SHOP_MSG = 0xdb,
	E_S_GAME_SSQ_INFO = 0xf8,
	E_S_GAME_RCVD_MANOR_LIST = 0xfe
};

class GameThread : public QThread
{
	Q_OBJECT
	private:
		QTimer * teleportTimer_;
		QTcpSocket * pSocket_;
		unsigned int bSize_;
		void write_ (const string & str) const;
		bool init_;
		string saveGameCharSelect_;
	private:
		static bool enterWorld_;
		Trade * tradeUi_;
	public:
		static bool enterWorld ();
		GameThread ();
		~GameThread ();
		void run ();
	signals:
		void signalAddItem (const int, const int, const string &);
		void signalGameSendData (const int, const string &);
		void signalCreateNpc (const Npc &);
		void signalCreateUser (const User &);
		void signalCreateChar (const Char &);
		void signalDeleteObject (const int);
		void signalDeleteItem (const int, const int);
		void signalSystemMessage (const string & str);
		void signalSay2 (const string &);
		void signalItemList (const vector <InventoryItem> &);
		void enterWorld (bool);
	private slots:
		void slotReadyRead_ ();
		void slotDisconnected_ ();
		void slotConnected_ ();
		void slotEnterWorld_ ();
		void slotMap (const string &);
		void slotSell_ (bool);
		void slotBuy_ (bool);
		void slotDwarfenManufacture_ (bool);
		void slotSay2 (const string &, const int, const string &);
		void slotTeleportTimer ();
		void slotRestart (bool);
		void slotLogout (bool);
};

#endif
