#ifndef __WAREHOUSE_WIDGET__
#define __WATEHOUSE_WIDGET__

#include "tablewidget.h"
#include <vector>
#include <map>
#include <string>
#include <QString>

using namespace std;

class WarehouseDepositWidget : public TableWidget
{
	Q_OBJECT
	private:
		void deleteItem_ (int row);
		vector <int> rowData_ (int, int, int);
		void dialog_ (int);
		map <int, int> objectId2_;
		map <int, int> objectId_;
		map <int, int> enchantLevel_;
		map <int, int> itemId_;
		map <int, int> itemType1_;
		map <int, int> itemType2_;
		bool isStackable_ (int itemType) const;
		int total_ () const;
	public:
		WarehouseDepositWidget (int x = 0, int y = 2);
		string packet ();
	signals:
		void changeTotal (int);
		void signalAddItem (const QString &, const vector <int> &);
	public slots:
		void addItem (const QString &, const vector <int> &);
};

#endif
