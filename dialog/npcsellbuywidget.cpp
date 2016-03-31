#include "npcsellbuywidget.h"

NpcSellWidgetUp::NpcSellWidgetUp (int adena, int x, int y) : TradeWidget (x, y), adena_ (adena)
{
}

int NpcSellWidgetUp::adena () const
{
	return adena_;
}

void NpcSellWidgetUp::setAdena (int adena)
{
	adena_ = adena;
}

void NpcSellWidgetUp::addItem (const QString & name, const vector <int> & data)
{
	// data[0] - itemType1, data[1] - itemId, data[2] - itemType2, data[3] - price
	this->itemType1_ [this->rowCount ()] = data[0];
	this->itemId_ [this->rowCount ()] = data[1];
	this->itemType2_ [this->rowCount ()] = data[0];
	this->setRowCount (this->rowCount () + 1);
	QTableWidgetItem * wiName = new QTableWidgetItem;
	wiName->setFlags (Qt::ItemIsSelectable | Qt::ItemIsEnabled);
	wiName->setText (name);
	wiName->setToolTip (Dat::itemDesc (data[1]).c_str ());
	this->setItem (this->rowCount () - 1, 0, wiName);		
	QTableWidgetItem * wiPrice = new QTableWidgetItem;
	wiPrice->setFlags (Qt::ItemIsSelectable | Qt::ItemIsEnabled);
	wiPrice->setText (DataFunc::number (data[3]).c_str ());
	this->setItem (this->rowCount () - 1, 1, wiPrice);
}

void NpcSellWidgetUp::dialog_ (int row)
{
	CountDialog * di = new CountDialog ("How many <b>" + this->name_ (row) + "</b> would you like to buy?", 0);
	if (di->exec () == QDialog::Accepted)
	{
		vector <int> data;
		data.push_back (itemType1_ [row]);
		data.push_back (itemId_ [row]);
		data.push_back (itemType2_ [row]);
		data.push_back (amount_ (row));
		data.push_back (di->result ());
		emit signalAddItem (this->name_ (row), data);
	}
	delete di;
}

NpcSellWidgetDown::NpcSellWidgetDown (int x, int y) : TableWidget (x, y)
{
}

string NpcSellWidgetDown::packet ()
{
	string ret;
	int count = this->rowCount ();
	ret += DataFunc::intToString (count);
	for (int i = 0; i < count; ++i)
	{
		ret += DataFunc::intToString (this->itemId_ [i]);
		ret += DataFunc::intToString (this->amount_ (i));
	}
	return ret;
}

int NpcSellWidgetDown::total_ () const
{
	int ret = 0;
	for (int i = 0; i < this->rowCount (); ++i)
	{
		ret += this->amount_ (i) * this->price_ (i);
	}
	return ret;
}

void NpcSellWidgetDown::deleteItem_ (int row)
{
	for (int i = row + 1; i < this->rowCount (); ++i)
	{
		for (int j = 0; j < this->columnCount (); ++j)
		{
			this->item (i - 1, j)->setText (this->item (i, j)->text ());
		}
		this->itemId_ [i - 1] = this->itemId_ [i];
	}
	for (int j = 0; j < this->columnCount (); ++j)
	{
		delete this->item (this->rowCount () - 1, j);
	}
	this->setRowCount (this->rowCount () - 1);
}

vector <int> NpcSellWidgetDown::rowData_ (int, int, int)
{
	return vector <int> ();
	// we don't need this;
}

bool NpcSellWidgetDown::isStackable_ (int type) const
{
	if (type == 5)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void NpcSellWidgetDown::addItem (const QString & name, const vector <int> & data)
{
	// data[0] - itemType1, data[1] - itemId, data[2] - itemType2, data[3] - price, data[4] - count
	int count = 1;
	if (isStackable_ (data[2]))
	{
		for (int i = 0; i < this->rowCount (); ++i)
		{
			if (itemId_ [i] == data[1])
			{
				this->setAmount_ (i, this->amount_ (i) + data[4]);
				return;
			}
		}
	}
	else
	{
		count = data[4];
	}
	for (int i = 0; i < count; ++i)
	{
		this->itemId_ [this->rowCount ()] = data[1];
		this->setRowCount (this->rowCount () + 1);
		QTableWidgetItem * wiName = new QTableWidgetItem;
		wiName->setFlags (Qt::ItemIsSelectable | Qt::ItemIsEnabled);
		wiName->setText (name);
		wiName->setToolTip (Dat::itemDesc (data[1]).c_str ());
		this->setItem (this->rowCount () - 1, 0, wiName);
		QTableWidgetItem * wiCount = new QTableWidgetItem;
		wiCount->setFlags (Qt::ItemIsSelectable | Qt::ItemIsEnabled);
		if (count == 1)
		{
			wiCount->setText (DataFunc::number (data[4]).c_str ());
		}
		else
		{
			wiCount->setText (DataFunc::number (1).c_str ());
		}
		this->setItem (this->rowCount () - 1, 1, wiCount);		
		QTableWidgetItem * wiPrice = new QTableWidgetItem;
		wiPrice->setFlags (Qt::ItemIsSelectable | Qt::ItemIsEnabled);
		wiPrice->setText (DataFunc::number (data[3]).c_str ());
		this->setItem (this->rowCount () - 1, 2, wiPrice);
	}
	emit changeTotal (total_ ());
}

void NpcSellWidgetDown::dialog_ (int row)
{
	if (amount_ (row) == 1)
	{
		deleteItem_ (row);
	}
	else
	{
		CountDialog * di = new CountDialog ("How many <b>" + this->name_ (row) + "</b> would you like to return?", this->amount_ (row));
		if (di->exec () == QDialog::Accepted)
		{
			if (di->result () == this->amount_ (row))
			{
				deleteItem_ (row);
			}
			else
			{
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

NpcBuyWidget::NpcBuyWidget (int x, int y) : TableWidget (x, y)
{
}

string NpcBuyWidget::packet ()
{
	string ret;
	int count = this->rowCount ();
	ret += DataFunc::intToString (count);
	for (int i = 0; i < count; ++i)
	{
		ret += DataFunc::intToString (this->objectId_ [i]);
		ret += DataFunc::intToString (this->itemId_ [i]);
		ret += DataFunc::intToString (this->amount_ (i));
	}
	return ret;
}

int NpcBuyWidget::total_ () const
{
	int ret = 0;
	for (int i = 0; i < this->rowCount (); ++i)
	{
		ret += this->amount_ (i) * this->price_ (i);
	}
	return ret;
}

void NpcBuyWidget::deleteItem_ (int row)
{
	for (int i = row + 1; i < this->rowCount (); ++i)
	{
		for (int j = 0; j < this->columnCount (); ++j)
		{
			this->item (i - 1, j)->setText (this->item (i, j)->text ());
		}
		this->itemId_ [i - 1] = this->itemId_ [i];
		this->objectId_ [i - 1] = this->objectId_ [i];
	}
	for (int j = 0; j < this->columnCount (); ++j)
	{
		delete this->item (this->rowCount () - 1, j);
	}
	this->setRowCount (this->rowCount () - 1);
}

vector <int> NpcBuyWidget::rowData_ (int row, int count, int price)
{
	vector <int> ret;
	ret.push_back (itemType1_ [row]);
	ret.push_back (itemId_ [row]);
	ret.push_back (itemType2_ [row]);
	ret.push_back (price);
	ret.push_back (count);
	ret.push_back (objectId_ [row]);
	ret.push_back (enchantLevel_ [row]);
	return ret;
}

void NpcBuyWidget::addItem (const QString & name, const vector <int> & data)
{
	// data[0] - itemType1, data[1] - itemId, data[2] - itemType2, data[3] - price, data[4] - count, data[5] - objectId, data[6] - enchantLevel
	for (int i = 0; i < this->rowCount (); ++i)
	{
		if (objectId_ [i] == data[5])
		{
			this->setAmount_ (i, this->amount_ (i) + data[4]);
			return;
		}
	}
	this->itemType1_ [this->rowCount ()] = data[0];
	this->itemType2_ [this->rowCount ()] = data[2];
	this->itemId_ [this->rowCount ()] = data[1];
	this->enchantLevel_ [this->rowCount ()] = data[6];
	this->objectId_ [this->rowCount ()] = data [5];
	this->setRowCount (this->rowCount () + 1);
	QTableWidgetItem * wiName = new QTableWidgetItem;
	wiName->setFlags (Qt::ItemIsSelectable | Qt::ItemIsEnabled);
	wiName->setText (name);
	wiName->setToolTip (Dat::itemDesc (data[1]).c_str ());
	this->setItem (this->rowCount () - 1, 0, wiName);
	QTableWidgetItem * wiCount = new QTableWidgetItem;
	wiCount->setFlags (Qt::ItemIsSelectable | Qt::ItemIsEnabled);
	wiCount->setText (DataFunc::number (data[4]).c_str ());
	this->setItem (this->rowCount () - 1, 1, wiCount);		
	QTableWidgetItem * wiPrice = new QTableWidgetItem;
	wiPrice->setFlags (Qt::ItemIsSelectable | Qt::ItemIsEnabled);
	wiPrice->setText (DataFunc::number (data[3]).c_str ());
	this->setItem (this->rowCount () - 1, 2, wiPrice);
	emit changeTotal (total_ ());
}

void NpcBuyWidget::dialog_ (int row)
{
	if (amount_ (row) == 1)
	{
 		emit signalAddItem (name_ (row), rowData_ (row, 1, price_ (row)));
		deleteItem_ (row);
	}
	else
	{
		CountDialog * di = new CountDialog ("How many <b>" + this->name_ (row) + "</b> would you like to sell?", this->amount_ (row));
		if (di->exec () == QDialog::Accepted)
		{
			if (di->result () == this->amount_ (row))
			{
				emit signalAddItem (name_ (row), rowData_ (row, di->result (), price_ (row)));
				deleteItem_ (row);
			}
			else
			{
				emit signalAddItem (name_ (row), rowData_ (row, di->result (), price_ (row)));
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


