#include "recipeshopiteminfo.h"

RecipeShopItemInfo::RecipeShopItemInfo (int recipeId, int mp, int maxMp)
{
	bool available = true;
	table_ = new QTableWidget (0, 2);
	QList <QString> labels;
	labels.push_back ("Item");
	labels.push_back ("Amount");
	table_->setHorizontalHeaderLabels (QStringList (labels));
	table_->verticalHeader ()->hide ();
	table_->setColumnWidth (0, 230);
	table_->setColumnWidth (1, 100);
	Recipe_s rec = Data::recipe (recipeId);
	for (unsigned int i = 0; i < rec.items.size (); ++i)
	{
		table_->setRowCount (table_->rowCount () + 1);
		QTableWidgetItem * wiName = new QTableWidgetItem;
		wiName->setText (Data::itemName (rec.items[i].itemId).c_str ());
		wiName->setFlags (Qt::ItemIsSelectable | Qt::ItemIsEnabled);
		table_->setItem (table_->rowCount () - 1, 0, wiName);		
		QTableWidgetItem * wiCount = new QTableWidgetItem;
		int count = 0;
		for (unsigned int j = 0; j < Data::bag.size (); ++j)
		{
			if (Data::bag[j].itemId == rec.items[i].itemId)
			{
				count = Data::bag[j].count;
				break;
			}
		}
		if (count < rec.items[i].count)
		{
			available = false;
		}
		wiCount->setText (QString (DataFunc::number (count).c_str ()) + " / " + QString (DataFunc::number (rec.items[i].count).c_str ()));
		wiCount->setFlags (Qt::ItemIsSelectable | Qt::ItemIsEnabled);
		table_->setItem (table_->rowCount () - 1, 1, wiCount);		
	}
	recipeLabel_ = new QLabel (QString ("Recipe: ") + QString (Data::recipeName (recipeId).c_str ()));
	mpLabel_ = new QLabel (QString ("Creator MP: ") + QString (DataFunc::number (mp).c_str ()) + " / " + QString (DataFunc::number (maxMp).c_str ()));
	prevButton_ = new QPushButton ("Back");
	connect (prevButton_, SIGNAL (pressed ()), SLOT (slotPressed ()));
	craftButton_ = new QPushButton ("Craft");
	craftButton_->setEnabled (available);
	connect (craftButton_, SIGNAL (pressed ()), SLOT (slotPressed ()));
	cancelButton_ = new QPushButton ("Cancel");
	connect (cancelButton_, SIGNAL (pressed ()), SLOT (reject ()));
	buttonLayout_ = new QHBoxLayout;
	buttonLayout_->addWidget (prevButton_);
	buttonLayout_->addWidget (craftButton_);
	buttonLayout_->addWidget (cancelButton_);
	vla_ = new QVBoxLayout;
	vla_->addWidget (recipeLabel_);
	vla_->addWidget (mpLabel_);
	vla_->addWidget (table_);
	vla_->addLayout (buttonLayout_);
	this->setLayout (vla_);
	this->setWindowTitle ("Create Item");
	this->move (400, 300);
	this->setFixedSize (360, 300);
	this->show ();
}

RecipeShopItemInfo::~RecipeShopItemInfo ()
{
	for (int i = 0; i < table_->rowCount (); ++i)
	{
		for (int j = 0; j < table_->columnCount (); ++j)
		{
			delete table_->item (i, j);
		}
	}
	delete recipeLabel_;
	delete mpLabel_;
	delete table_;
	delete craftButton_;
	delete cancelButton_;
	delete prevButton_;
	delete buttonLayout_;
	delete vla_;
}

void RecipeShopItemInfo::slotPressed ()
{
	if (sender () == craftButton_)
	{
		selection_ = 0;
		accept ();
	}
	else if (sender () == prevButton_)
	{
		selection_ = 1;
		accept ();
	}
}

int RecipeShopItemInfo::selection () const
{
	return selection_;
}
