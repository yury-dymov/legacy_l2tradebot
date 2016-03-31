#ifndef __PLAYER_SELL_BUY__
#define __PLAYER_SELL_BUY__

#include "tablewidget.h"
#include "countdialog.h"
#include "../datafunc.h"
#include "../dat.h"
#include <map>
#include <string>
#include <vector>

using namespace std;

class PlayerSellWidget : public TableWidget
{
	private:
		map <int, int> h1_;
		map <int, int> h2_;
		map <int, int> type2_;
		map <int, int> itemId_;
		map <int, int> objectId_;
		map <int, int> enchant_;
		map <int, int> bodyPart_;
		map <int, int> storePrice_;
		vector <int> rowData_ (int, int, int);
		void deleteItem_ (int);
		void dialog_ (int);
		int package_;
	public:
		PlayerSellWidget (int x = 0, int y = 3, int adena = -1, int package = 0);
		string packet ();
		void addItem (const QString &, const vector <int> &);
};

class PlayerBuyWidget : public TableWidget
{
	private:
		map <int, int> objectId_;
		map <int, int> itemId_;
		map <int, int> type2_;
		map <int, int> playerCount_;
		map <int, int> h1_;
		map <int, int> enchant_;
		map <int, int> refPrice_;
		map <int, int> bodyPart_;
		vector <int> rowData_ (int, int, int);
		void deleteItem_ (int);
		void dialog_ (int);
	public:
		PlayerBuyWidget (int x = 0, int y = 3, int adena = -1);
		string packet ();
		void addItem (const QString &, const vector <int> &);
};

#endif
