#include "recipeshopselllist.h"

RecipeShopSellList::RecipeShopSellList (int mp, int maxMp, int adena, const vector <RecipeShopItem> & recipes)
{
	adenaLabel_ = new QLabel (QString ("Adena: ") + DataFunc::number (adena).c_str ());
	mpLabel_ = new QLabel (QString ("Creators Mp: ") + QString (DataFunc::number (mp).c_str ()) + " / " + QString (DataFunc::number (maxMp).c_str ()));
	table_ = new QTableWidget (0, 2);
	connect (table_, SIGNAL (cellClicked (int, int)), SLOT (slotCellClicked (int, int)));
	connect (table_, SIGNAL (cellDoubleClicked (int, int)), SLOT (slotCellDoubleClicked (int, int)));
	connect (table_, SIGNAL (currentCellChanged (int, int, int, int)), SLOT (slotCurrentCellChanged (int, int, int, int)));
	for (unsigned int i = 0; i < recipes.size (); ++i)
	{
		table_->setRowCount (table_->rowCount () + 1);
		QTableWidgetItem * wiName = new QTableWidgetItem;
		wiName->setText (Data::recipeName (recipes[i].recipeId).c_str ());
		wiName->setFlags (Qt::ItemIsSelectable | Qt::ItemIsEnabled);
		table_->setItem (table_->rowCount () - 1, 0, wiName);		
		QTableWidgetItem * wiPrice = new QTableWidgetItem;
		wiPrice->setText (DataFunc::number (recipes[i].price).c_str ());
		wiPrice->setFlags (Qt::ItemIsSelectable | Qt::ItemIsEnabled);
		table_->setItem (table_->rowCount () - 1, 1, wiPrice);
	}
	QList <QString> labels;
	labels.push_back ("Recipe");
	labels.push_back ("Price");
	table_->setHorizontalHeaderLabels (QStringList (labels));
	table_->verticalHeader ()->hide ();
	table_->setColumnWidth (0, 230);
	table_->setColumnWidth (1, 90);
	cancelButton_ = new QPushButton ("Cancel");
	connect (cancelButton_, SIGNAL (pressed ()), SLOT (reject ()));
	vla_ = new QVBoxLayout;
	vla_->addWidget (table_);
	vla_->addWidget (mpLabel_);
	vla_->addWidget (adenaLabel_);
	vla_->addWidget (cancelButton_);
	this->setWindowTitle ("Dwarven Manufacture");
	this->move (400, 250);
	this->setFixedSize (350, 250);
	this->setLayout (vla_);
	this->show ();
}

RecipeShopSellList::~RecipeShopSellList ()
{
	for (int i = 0; i < table_->rowCount (); ++i)
	{
		for (int j = 0; j < table_->columnCount (); ++j)
		{
			delete table_->item (i, j);
		}
	}
	delete table_;
	delete mpLabel_;
	delete adenaLabel_;
	delete cancelButton_;
	delete vla_;
}

void RecipeShopSellList::slotCellClicked (int row, int)
{
	for (int i = 0; i < table_->columnCount (); ++i)
	{
		table_->item (row, i)->setSelected (true);
	}
}

void RecipeShopSellList::slotCellDoubleClicked (int row, int)
{
	rowId_ = row;
	accept ();
}

void RecipeShopSellList::slotCurrentCellChanged (int row, int, int, int)
{
	if (row >= 0)
	{
		for (int i = 0; i < table_->columnCount (); ++i)
		{
			table_->item (row, i)->setSelected (true);
		}	
	}
}

int RecipeShopSellList::rowId () const
{
	return rowId_;
}
