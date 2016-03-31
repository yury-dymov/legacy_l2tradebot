#ifndef __NPC_SELL_BUY_WIDGET__
#define __NPC_SELL_BUY_WIDGET__

#include "tablewidget.h"
#include "tradewidget.h"
#include "../dat.h"

#include <QString>
#include <map>
#include <vector>

using namespace std;

class NpcSellWidgetUp : public TradeWidget		// TradeWidget: amount_ === price in this case
{
	Q_OBJECT
	private:
		void dialog_ (int row);
		map <int, int> itemId_;
		map <int, int> itemType1_;
		map <int, int> itemType2_;
		int adena_;
	signals:
		void signalAddItem (const QString &, const vector <int> &);
	public:
		int adena () const;
		void setAdena (int);
		NpcSellWidgetUp (int adena, int x = 0, int y = 2);
		void addItem (const QString &, const vector <int> &);
};

class NpcSellWidgetDown : public TableWidget
{
	Q_OBJECT
	private:
		void deleteItem_ (int row);
		vector <int> rowData_ (int, int, int);
		void dialog_ (int);
		map <int, int> itemId_;
		bool isStackable_ (int itemType) const;
		int total_ () const;
	public:
		NpcSellWidgetDown (int x = 0, int y = 3);
		string packet ();
	signals:
		void changeTotal (int);
	private slots:
		void addItem (const QString &, const vector <int> &);
};

class NpcBuyWidget : public TableWidget
{
	Q_OBJECT
	private:
		void deleteItem_ (int row);
		vector <int> rowData_ (int, int, int);
		void dialog_ (int);
		map <int, int> itemId_;
		map <int, int> objectId_;
		map <int, int> itemType1_;
		map <int, int> itemType2_;
		map <int, int> enchantLevel_;
		int total_ () const;
	public:
		NpcBuyWidget (int x = 0, int y = 3);
		string packet ();
	signals:
		void changeTotal (int);
		void signalAddItem (const QString &, const vector <int> &);
	public slots:
		void addItem (const QString &, const vector <int> &);
};

#endif
