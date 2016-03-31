#ifndef __TABLE_WIDGET__
#define __TABLE_WIDGET__

#include <QTableWidget>
#include <QString>
#include <string>
#include <map>
#include <vector>

#include "../datafunc.h"

using namespace std;

// adena == -1 then sellWidget, else ownWidget. Dirty, I know (
class TableWidget : public QTableWidget
{
	Q_OBJECT
	protected:
		int amount_ (int) const;
		int price_ (int) const;
		QString name_ (int) const;
		void setAmount_ (int, int);
		void setPrice_ (int, int);
		int adena_;
	private:
		virtual void deleteItem_ (int) = 0;
		virtual vector <int> rowData_ (int, int, int) = 0;
		virtual void dialog_ (int) = 0;
		string motd_;
		int income_;
	public:
		TableWidget (int x = 0, int y = 3, int adena = -1);
		~TableWidget ();
		virtual void addItem (const QString &, const vector <int> &) = 0;
		virtual string packet () = 0;
		int income () const;
		void setIncome (int);
		void setMotd (const string &);
		string motd () const;
	signals:
		void signalDeselect ();
		void signalAddItem (const QString &, const vector <int> &);
		void signalChangeIncome ();
	private slots:
		void slotCellClicked (int, int);
		void slotCellDoubleClicked (int, int);
		void slotCurrentCellChanged (int, int, int, int);
		void slotDeselect ();
		void slotAddRow (const QString &, const vector <int> &);
};

#endif
