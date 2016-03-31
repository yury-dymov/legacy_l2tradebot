#ifndef __SELL_BUY__
#define __SELL_BUY__

#include "../dat.h"
#include "tablewidget.h"
#include "countdialog.h"

using namespace std;

class SellWidget : public TableWidget
{
	private:
		map <int, int> objectId_;
		bool checked_;
		void deleteItem_ (int);
		vector <int> rowData_ (int, int, int);
		void dialog_ (int row);
	public:
		SellWidget (int x = 0, int y = 3, int adena = -1);
		void addItem (const QString &, const vector <int> &);
		string packet ();
		void setPackage (bool val);
		bool package () const;
};

class BuyWidget : public TableWidget
{
	private:
		map <int, int> h1_;
		map <int, int> h2_;
		map <int, int> type2_;
		map <int, int> itemId_;
		vector <int> rowData_ (int, int, int);
		void deleteItem_ (int);
		void dialog_ (int);
		bool isStackable_ (int);
	public:
		BuyWidget (int x = 0, int y = 3, int adena = -1);
		string packet ();
		void addItem (const QString &, const vector <int> &);
};


#endif
