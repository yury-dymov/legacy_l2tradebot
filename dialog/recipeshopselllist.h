#ifndef __RECIPE_SHOP_SELL_LIST__
#define __RECIPE_SHOP_SELL_LIST__

#include <QDialog>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QString>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QHeaderView>
#include <QList>

#include <vector>

#include "../catx/convert.h"

#include "../data.h"

using namespace std;
using namespace CatX;

class RecipeShopSellList : public QDialog
{
	Q_OBJECT
	private:
		QVBoxLayout * vla_;
		QPushButton * cancelButton_;
		QLabel * adenaLabel_;
		QTableWidget * table_;
		QLabel * mpLabel_;
		int rowId_;
	public:
		int rowId () const;
		RecipeShopSellList (int, int, int, const vector <RecipeShopItem> &);
		~RecipeShopSellList ();
	private slots:
		void slotCellClicked (int, int);
		void slotCellDoubleClicked (int, int);
		void slotCurrentCellChanged (int, int, int, int);
};

#endif
