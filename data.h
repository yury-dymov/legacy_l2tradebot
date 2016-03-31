#ifndef __DATA_H__
#define __DATA_H__

#define L2_HOST "rpg.f1recat.com"
#define L2_PORT 2106
#define BLOWFISH "6B60CB5B82CE90B1CC2B6C556C6C6C6C"
#define REVISION 746
#define MESSAGE_MAX_LENGTH 32

#include <string>
#include <map>
#include <vector>
#include "classes/map_item.h"
#include "dialog/sellbuywidget.h"

#include "catx/reader.h"
#include "catx/convert.h"
#include "catxpoint.h"

#include "debug.h"
#include "b32.h"
#include "game_struct.h"
#include "dat.h"

class Data : public Dat
{
	private:
		static SellWidget * sellWidget_;
		static BuyWidget * buyWidget_;
	public:
		static SellWidget * sellWidget ();
		static BuyWidget * buyWidget ();
		static void init ();
		static vector <InventoryItem> bag;
};

class L2Object
{
	private:
		int objectId_;
		CatXPoint pos_;
		CatXPoint next_;
		int speed_;
		int wSpeed_;
		bool isRun_;
		MapItem * mItem_;
		std::string name_;
	public:
		L2Object () : mItem_ (0) {;}
		int objectId () const {return objectId_;}
		CatXPoint pos () const {return pos_;}
		CatXPoint next () const {return next_;}
		int speed () const {return speed_;}
		int walkSpeed () const {return wSpeed_;}
		bool isRun () const {return isRun_;}
		MapItem * mapItem () {return mItem_;}
		void setObjectId (int id) {objectId_ = id;}
		void setPos (CatXPoint pos) {pos_ = pos;}
		void setNext (CatXPoint pos) {next_ = pos;}
		void setSpeed (int speed) {speed_ = speed;}
		void setWalkSpeed (int speed) {wSpeed_ = speed;}
		void setIsRun (bool val) {isRun_ = val;}
		void setMapItem (MapItem * item) {mItem_ = item;}
		void deleteMapItem () {delete mItem_;}
		std::string name () const {return name_;}
		void setName (const std::string & name) {name_ = name;}
};

class User : public L2Object
{
};

class Npc : public L2Object
{
	private:
		int npcId_;
		bool isAttackable_;
	public:
		int npcId () const {return npcId_;}
		bool isAttackable () const {return isAttackable_;}
		void setNpcId (const int npcId) {npcId_ = npcId;}
		void setAttackable (bool at) {isAttackable_ = at;}
};

class Char : public L2Object
{
	private:
		int shop_;
	public:
		void setShop (int shop) {shop_ = shop;}
		int shop () const {return shop_;}
		bool isTrading () const {if (shop_ == 1 || shop_ == 3 || shop_ == 8) return true; return false;}
};

#endif
