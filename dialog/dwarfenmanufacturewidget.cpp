#include "dwarfenmanufacturewidget.h"

DwarfenManufactureWidgetUp::DwarfenManufactureWidgetUp (int x, int y) : TradeWidget (x, y)
{
}

void DwarfenManufactureWidgetUp::addItem (const QString & name, int recipeId)
{
	QTableWidgetItem * wiName = new QTableWidgetItem;
	wiName->setFlags (Qt::ItemIsSelectable | Qt::ItemIsEnabled);
	wiName->setText (name);
	this->setRowCount (rowCount () + 1);
	this->setItem (this->rowCount () - 1, 0, wiName);		
	this->recipeId_ [this->rowCount () - 1] = recipeId;	
}

void DwarfenManufactureWidgetUp::dialog_ (int row)
{
	CountDialog * di = new CountDialog ("What price do you want to set?", 0);
	if (di->exec () == QDialog::Accepted)
	{
		emit signalAddItem (name_ (row), recipeId_ [row], di->result ());
	}
	delete di;
}

DwarfenManufactureWidgetDown::DwarfenManufactureWidgetDown (int x, int y) : TradeWidget (x, y)
{
}

void DwarfenManufactureWidgetDown::dialog_ (int row)
{
	deleteItem_ (row);
}

void DwarfenManufactureWidgetDown::deleteItem_ (int row)
{
	for (int i = row + 1; i < this->rowCount (); ++i)
	{
		for (int j = 0; j < this->columnCount (); ++j)
		{
			this->item (i - 1, j)->setText (this->item (i, j)->text ());
		}
		this->recipeId_[i - 1] = this->recipeId_ [i];
	}
	for (int j = 0; j < this->columnCount (); ++j)
	{
		delete this->item (this->rowCount () - 1, j);
	}
	this->setRowCount (this->rowCount () - 1);
}

void DwarfenManufactureWidgetDown::addItem (const QString & name, int recipeId, int price)
{
	for (int i = 0; i < this->rowCount (); ++i)
	{
		if (this->recipeId_ [i] == recipeId)
		{
			this->setAmount_ (i, price);
			return;
		}
	}
	QTableWidgetItem * wiName = new QTableWidgetItem;
	wiName->setFlags (Qt::ItemIsSelectable | Qt::ItemIsEnabled);
	wiName->setText (name);
	this->setRowCount (rowCount () + 1);
	this->setItem (this->rowCount () - 1, 0, wiName);		
	this->recipeId_ [this->rowCount () - 1] = recipeId;
	QTableWidgetItem * wiCount = new QTableWidgetItem;
	wiCount->setFlags (Qt::ItemIsSelectable | Qt::ItemIsEnabled);
	wiCount->setText (DataFunc::number (price).c_str ());
	this->setItem (this->rowCount () - 1, 1, wiCount);		
}

string DwarfenManufactureWidgetDown::packet ()
{
	string ret;
	ret += DataFunc::intToString (this->rowCount ());
	for (int i = 0; i < this->rowCount (); ++i)
	{
		ret += DataFunc::intToString (this->recipeId_ [i]);
		ret += DataFunc::intToString (this->amount_ (i));
	}
	return ret;
}
