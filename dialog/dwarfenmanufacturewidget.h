#ifndef __DWARFEN_MANUFACTURE_WIDGET__
#define __DWARFEN_MANUFACTURE_WIDGET__

#include "tradewidget.h"
#include <map>
#include <QString>
#include <string>

using namespace std;

class DwarfenManufactureWidgetUp : public TradeWidget
{
	Q_OBJECT
	private:
		void dialog_ (int row);
		map <int, int> recipeId_;
	public:
		DwarfenManufactureWidgetUp (int x = 0, int y = 1);
		void addItem (const QString & name, int recipeId);
	signals:
		void signalAddItem (const QString & name, int recipeId, int price);
};

// amount_ == price
class DwarfenManufactureWidgetDown : public TradeWidget
{
	Q_OBJECT
	private:
		void dialog_ (int row);
		void deleteItem_ (int row);
		map <int, int> recipeId_;
	public:
		DwarfenManufactureWidgetDown (int x = 0, int y = 2);
		string packet ();
	public slots:
		void addItem (const QString & name, int recipeId, int price);
};

#endif
