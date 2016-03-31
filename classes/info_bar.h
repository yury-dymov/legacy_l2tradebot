#ifndef __INFO_BAR__
#define __INFO_BAR__

#include <QWidget>
#include <QTreeWidget>
#include <QMouseEvent>
#include <QHeaderView>

#include <map>
#include <vector>
#include <string>

#include "map_item.h"

using namespace std;

class InfoBar : public QTreeWidget
{
	Q_OBJECT
	private:
		struct Object_s
		{
			QTreeWidgetItem * item;
			int stereotype;
		};
		map <int, vector <Object_s> > data_;
//		map <int, QTreeWidgetItem*> data_;
//		map <int, int> stereotype_;
		map <QTreeWidgetItem*, int> objectId_;
	protected:
		//void mousePressEvent (QMouseEvent *);
		//void mouseDoubleClickEvent (QMouseEvent *);
	public:
		InfoBar ();
		~InfoBar ();
		void deleteItem (const int objectId, const int stereotype);
	signals:
		void signalInfoBarSelected (const int, const int);
	private slots:
		void slotAddItem (const int, const int, const string &);
		void slotDeleteItem (const int, const int);
		void slotItemActivated (QTreeWidgetItem * item, int column);
		void slotCurrentItemChanged (QTreeWidgetItem *, QTreeWidgetItem *);
		void slotEnterWorld (bool);
};

#endif
