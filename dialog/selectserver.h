#ifndef __SELECT_SERVER__
#define __SELECT_SERVER__

#include <QDialog>
#include <QTableWidget>
#include <QHeaderView>
#include <QList>
#include <QString>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include "../game_struct.h"
#include "../data.h"

#include "../catx/convert.h"

using namespace std;
using namespace CatX;

class SelectServerDialog : public QDialog
{
	Q_OBJECT
	private:
		QHBoxLayout * buttonLayout_;
		QVBoxLayout * mainLayout_;
		QTableWidget * serverList_;
		QPushButton * okButton_;
		QPushButton * cancelButton_;
		int selected_;
		void addRow_ (int id, const string & name, bool online);
	public:
		int serverId () const;
		SelectServerDialog (const vector <Server_s> &);
		~SelectServerDialog ();
	private slots:
		void slotCellClicked (int, int);
		void slotCellDoubleClicked (int, int);
		void slotCurrentCellChanged (int, int, int, int);
};

#endif
