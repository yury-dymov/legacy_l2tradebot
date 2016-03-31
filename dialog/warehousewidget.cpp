#include "warehouse.h"

WarehouseDepositWidget::WarehouseDepositWidget (int x, int y) : TableWidget (x, y)
{
}

string WarehouseDepositWidget::packet ()
{
	string ret;
	int count = this->rowCount ();
	ret += DataFunc::intToString (count);
	for (int i = 0; i < count; ++i)
	{
		ret += DataFunc::intToString (this->objectId2_ [i]);
		ret += DataFunc::intToString (this->amount_ (i));
	}
	return ret;
}

int WarehouseDepositWidget::total_ () const
{
	return this->rowCount () * 30;
}

void WarehouseDepositWidget::deleteItem_ (int row)
{
	for (int i = row + 1; i < this->rowCount (); ++i)
	{
		for (int j = 0; j < this->columnCount (); ++j)
		{
			this->item (i - 1, j)->setText (this->item (i, j)->text ());
		}
		this->itemId_ [i - 1] = this->itemId_ [i];
		this->itemType1_ [i - 1] = this->itemType1_ [i];
		this->itemType2_ [i - 1] = this->itemType2_ [i];
		this->objectId_ [i - 1] = this->objectId_ [i];
		this->objectId2_ [i - 1] = this->objectId2_ [i];
		this->enchantLevel_ [i - 1] = this->enchantLevel_ [i];
	}
	for (int j = 0; j < this->columnCount (); ++j)
	{
		delete this->item (this->rowCount () - 1, j);
	}
	this->setRowCount (this->rowCount () - 1);
}

vector <int> WarehouseDepositWidget::rowData_ (int row, int count, int)
{
	vector <int> ret;
	ret.push_back (itemType1_[row]);
	ret.push_back (itemId_[row]);
	ret.push_back (itemType2_[row]);
	ret.push_back (count);
	ret.push_back (objectId_ [row]);
	ret.push_back (objectId2_ [row]);
	ret.push_back (enchantLevel_ [row]);
	return ret;
}

bool WarehouseDepositWidget::isStackable_ (int type) const
{
	if (type == 5 || type == 4)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void WarehouseDepositWidget::addItem (const QString & name, const vector <int> & data)
{
	// data[0] - itemType1, data[1] - itemId, data[2] - itemType2, data[3] - count, data[4] - objectId, data[5] - objectId2, data[6] - enchantLevel
	if (isStackable_ (data[2]))
	{
		for (int i = 0; i < this->rowCount (); ++i)
		{
			if (objectId_ [i] == data[4])
			{
				this->setAmount_ (i, this->amount_ (i) + data[3]);
				return;
			}
		}
	}
	this->itemId_ [this->rowCount ()] = data[1];
	this->itemType1_ [this->rowCount ()] = data[0];
	this->itemType2_ [this->rowCount ()] = data[2];
	this->objectId_ [this->rowCount ()] = data[4];
	this->objectId2_ [this->rowCount ()] = data[5];
	this->enchantLevel_ [this->rowCount ()] = data[6];
	this->setRowCount (this->rowCount () + 1);
	QTableWidgetItem * wiName = new QTableWidgetItem;
	wiName->setFlags (Qt::ItemIsSelectable | Qt::ItemIsEnabled);
	wiName->setText (name);
	this->setItem (this->rowCount () - 1, 0, wiName);
	QTableWidgetItem * wiCount = new QTableWidgetItem;
	wiCount->setFlags (Qt::ItemIsSelectable | Qt::ItemIsEnabled);
	wiCount->setText (DataFunc::number (data[3]).c_str ());
	this->setItem (this->rowCount () - 1, 1, wiCount);		
	emit changeTotal (total_ ());
}

void WarehouseDepositWidget::dialog_ (int row)
{
	if (amount_ (row) == 1)
	{
		emit signalAddItem (name_ (row), rowData_ (row, amount_ (row), 0));
		deleteItem_ (row);
	}
	else
	{
		CountDialog * di = new CountDialog ("How many <b>" + this->name_ (row) + "</b> would you like to move?", this->amount_ (row));
		if (di->exec () == QDialog::Accepted)
		{
			if (di->result () == this->amount_ (row))
			{
				emit signalAddItem (name_ (row), rowData_ (row, amount_ (row), 0));
				deleteItem_ (row);
			}
			else
			{
				emit signalAddItem (name_ (row), rowData_ (row, di->result (), 0));
				this->setAmount_ (row, amount_ (row) - di->result ());
			}
		}
		else
		{
			delete di;
			return;
		}
		delete di;
	}
	emit changeTotal (total_ ());
}

