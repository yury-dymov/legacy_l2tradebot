#ifndef __BAG_H__
#define __BAG_H__

#include <QTableWidget>
#include <QHeaderView>
#include <QList>
#include <QString>
#include <QMenu>

#include <map>

#include "../data.h"
#include "../datafunc.h"
#include "../game_struct.h"
#include "../dialog/dialog.h"
#include "../game/packet/gamepacket.h"

using namespace std;

class BagWidget : public QTableWidget
{
	Q_OBJECT
	signals:
		void signalWrite (const string & pck);
		void signalUseItem (int, int);
	private:
		vector <InventoryItem> item_;
		void deleteRow_ (int);
		void addRow_ (const InventoryItem &);
	public:
		BagWidget ();
		~BagWidget ();
	private slots:
		void slotDoubleClicked (int, int);
		void setInventory (const vector <InventoryItem> &);
		void slotCellClicked (int, int);
		void slotCurrentCellChanged (int, int, int, int);
		void slotEnterWorld (bool);
};

#endif
