#ifndef __RECIPE_SHOP_ITEM_INFO__
#define __RECIPE_SHOP_ITEM_INFO__

#include <QDialog>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QLabel>

#include "../data.h"
#include "../datafunc.h"

class RecipeShopItemInfo : public QDialog
{	
	Q_OBJECT
	private:
		QPushButton * prevButton_;
		QPushButton * craftButton_;
		QPushButton * cancelButton_;
		QHBoxLayout * buttonLayout_;
		QVBoxLayout * vla_;
		QTableWidget * table_;
		int selection_;
		QLabel * mpLabel_;
		QLabel * recipeLabel_;
	public:
		int selection () const;
		RecipeShopItemInfo (int recipeId, int mp, int maxMp);
		~RecipeShopItemInfo ();
	private slots:
		void slotPressed ();
};

#endif
