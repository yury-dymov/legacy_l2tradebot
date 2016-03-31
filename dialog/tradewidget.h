#ifndef __TRADE_WIDGET__
#define __TRADE_WIDGET__

#include <QTableWidget>
#include <QString>
#include <string>
#include <map>
#include <vector>

#include "countdialog.h"
#include "../catxpoint.h"
#include "../game/packet/gamepacket.h"
#include "../dat.h"

using namespace std;

class TradeWidget : public QTableWidget
{
	Q_OBJECT
	protected:
		int amount_ (int) const;
		QString name_ (int) const;
		void setAmount_ (int, int);
		virtual void dialog_ (int row) = 0;
	public:
		TradeWidget (int x, int y);
		~TradeWidget ();
		void froze ();
	private slots:
		void slotCellClicked (int, int);
		void slotCellDoubleClicked (int, int);
		void slotCurrentCellChanged (int, int, int, int);
};

class TradeUpperWidget: public TradeWidget
{
	Q_OBJECT
	signals:
		void sendPacket (const string &);
	private:
		void dialog_ (int row);
		map <int, int> objectId_;
		map <int, int> itemId_;
		bool froze_;
	public:
		void froze ();
		TradeUpperWidget (int x = 0, int y = 2);
		void addItem (const QString &, const vector <int> &);
		void deleteItem (int objectId, int itemId, int count);
};

class TradeCharWidget : public TradeWidget
{
	Q_OBJECT
	private:
		void dialog_ (int row);
	public:
		TradeCharWidget (int x = 0, int y = 2);
		void addItem (const QString & name, int count);
};

class TradeUserWidget : public TradeWidget
{
	Q_OBJECT
	private:
		void dialog_ (int row);
	public:
		TradeUserWidget (int x = 0, int y = 2);
		void addItem (const QString & name, int count);
};

#endif
