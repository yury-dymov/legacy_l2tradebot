#include "sellbuywidget.h"

SellWidget::SellWidget (int p1, int p2, int adena) : TableWidget (p1, p2, adena), checked_ (false)
{
}

string SellWidget::packet ()
{
	string ret;
	if (this->rowCount ())
	{
		ret += DataFunc::intToString (this->rowCount ());
		for (int i = 0; i < this->rowCount (); ++i)
		{
			ret += DataFunc::intToString (this->objectId_ [i]);
			ret += DataFunc::intToString (this->amount_ (i));
			ret += DataFunc::intToString (this->price_ (i));
		}
	}
	return ret;
}

void SellWidget::setPackage (bool val)
{
	checked_ = val;
}

bool SellWidget::package () const
{
	return checked_;
}

void SellWidget::deleteItem_ (int row)
{
	for (int i = row + 1; i < this->rowCount (); ++i)
	{
		for (int j = 0; j < this->columnCount (); ++j)
		{
			this->item (i - 1, j)->setText (this->item (i, j)->text ());
		}
		this->objectId_[i - 1] = this->objectId_ [i];
	}
	for (int j = 0; j < this->columnCount (); ++j)
	{
		delete this->item (this->rowCount () - 1, j);
	}
	this->setRowCount (this->rowCount () - 1);
}

void SellWidget::addItem (const QString & name, const vector <int> & data)
{
	// data[0] - count, data[1] - price, data[2] - objectId. data[3] - itemId
	int size = this->rowCount ();
	for (int i = 0; i < size; ++i)
	{
		if (name_ (i) == name)
		{
			this->setAmount_ (i, this->amount_ (i) + data[0]);
			if (adena_ == -1)
			{
				this->setPrice_ (i, data[1]);
				emit signalChangeIncome ();
			}
			return;
		}
	}
	this->objectId_ [this->rowCount ()] = data[2];
	this->setRowCount (this->rowCount () + 1);
	QTableWidgetItem * wiName = new QTableWidgetItem;
	wiName->setFlags (Qt::ItemIsSelectable | Qt::ItemIsEnabled);
	wiName->setText (name);
	wiName->setToolTip (Dat::itemDesc (data[3]).c_str ());
	this->setItem (this->rowCount () - 1, 0, wiName);		
	QTableWidgetItem * wiCount = new QTableWidgetItem;
	wiCount->setFlags (Qt::ItemIsSelectable | Qt::ItemIsEnabled);
	wiCount->setText (DataFunc::number (data[0]).c_str ());
	this->setItem (this->rowCount () - 1, 1, wiCount);		
	QTableWidgetItem * wiPrice = new QTableWidgetItem;
	wiPrice->setFlags (Qt::ItemIsSelectable | Qt::ItemIsEnabled);
	wiPrice->setText (DataFunc::number (data[1]).c_str ());
	this->setItem (this->rowCount () - 1, 2, wiPrice);
	if (adena_ == -1)
	{
		emit signalChangeIncome ();
	}
}

vector <int> SellWidget::rowData_ (int row, int amount, int price)
{
	vector <int> ret;
	ret.push_back (amount);
	ret.push_back (price);
	ret.push_back (objectId_ [row]);
	return ret;
}

void SellWidget::dialog_ (int row)
{
	int res = 0;
	if (this->amount_ (row) > 1)
	{
		CountDialog * di = new CountDialog ("How many <b>" + this->name_ (row) + "</b> would you like to sell? (max: " + QString (DataFunc::number ( this->amount_ (row)).c_str ()) + ")", this->amount_ (row));
		if (di->exec () == QDialog::Accepted)
		{
			res = di->result ();
		}
		delete di;			
	}
	else
	{
		res = 1;
	}
	if (res)
	{
		int priced = -1;
		if (adena_ != -1)
		{
			CountDialog * di = new CountDialog ("What price do you want to set?", 0);
			if (di->exec () == QDialog::Accepted)
			{
				if (di->result ())
				{
					priced = di->result ();
				}
			}
			else
			{
				delete di;
				return;
			}
			delete di;
			if (priced == -1)
			{
				return;
			}
		}
		QString name = this->name_ (row);
		int amount = this->amount_ (row);
		vector <int> save = rowData_ (row, res, priced);
		if (res == this->item (row, 1)->text ().toInt ())
		{
			deleteItem_ (row);
		}
		else
		{
			this->setAmount_ (row, amount - res);
		}
		if (adena_ == -1)
		{
			emit signalAddItem (name, save);
			emit signalChangeIncome ();
		}
		else
		{
			emit signalAddItem (name, save);
		}
	}
}

BuyWidget::BuyWidget (int p1, int p2, int adena) : TableWidget (p1, p2, adena)
{
}


string BuyWidget::packet ()
{
	string ret;
	if (this->rowCount ())
	{
		ret += DataFunc::intToString (this->rowCount ());
		for (int i = 0; i < this->rowCount (); ++i)
		{
			ret += DataFunc::intToString (this->itemId_ [i]);
			ret += DataFunc::intToString (this->h1_ [i], 2);
			ret += DataFunc::intToString (this->h2_ [i], 2);
			ret += DataFunc::intToString (this->amount_ (i));
			ret += DataFunc::intToString (this->price_ (i));
		}
	}
	return ret;
}

vector <int> BuyWidget::rowData_ (int row, int amount, int price)
{
	vector <int> ret;
	ret.push_back (itemId_ [row]);
	ret.push_back (h1_[row]);
	ret.push_back (h2_[row]);
	ret.push_back (amount);
	ret.push_back (price);
	ret.push_back (type2_[row]);
	return ret;
}

void BuyWidget::deleteItem_ (int row)
{
	for (int i = row + 1; i < this->rowCount (); ++i)
	{
		for (int j = 0; j < this->columnCount (); ++j)
		{
			this->item (i - 1, j)->setText (this->item (i, j)->text ());
		}
		this->itemId_[i - 1] = this->itemId_ [i];
		this->h1_[i - 1] = this->h1_ [i];
		this->h2_[i - 1] = this->h2_ [i];
		this->type2_[i - 1] = this->type2_[i];
	}
	for (int j = 0; j < this->columnCount (); ++j)
	{
		delete this->item (this->rowCount () - 1, j);
	}
	this->setRowCount (this->rowCount () - 1);
}

void BuyWidget::addItem (const QString & name, const vector <int> & data)
{
	// data[0] - itemId, data[1] - h1, data[2] - h2, data[3] - count, data[4] - price
	int size = this->rowCount ();
	if (isStackable_ (data[5]))
	{
		for (int i = 0; i < size; ++i)
		{
			if (name_ (i) == name)
			{
				this->setAmount_ (i, this->amount_ (i) + data[3]);
				if (adena_ == -1)
				{
					this->setPrice_ (i, data[4]);
					emit signalChangeIncome ();
				}
				return;
			}
		}
	}
	int count = 1;
	if (!isStackable_ (data[5]))
	{
		count = data[3];
	}
	for (int i = 0; i < count; ++i)
	{
		this->itemId_ [this->rowCount ()] = data[0];
		this->h1_ [this->rowCount ()] = data[1];
		this->h2_ [this->rowCount ()] = data[2];
		this->type2_ [this->rowCount ()] = data[5];
		this->setRowCount (this->rowCount () + 1);
		QTableWidgetItem * wiName = new QTableWidgetItem;
		wiName->setFlags (Qt::ItemIsSelectable | Qt::ItemIsEnabled);
		wiName->setText (name);
		wiName->setToolTip (Dat::itemDesc (data[0]).c_str ());
		this->setItem (this->rowCount () - 1, 0, wiName);		
		QTableWidgetItem * wiCount = new QTableWidgetItem;
		wiCount->setFlags (Qt::ItemIsSelectable | Qt::ItemIsEnabled);
		if (count == 1)
		{
			wiCount->setText (DataFunc::number (data[3]).c_str ());
		}
		else
		{
			wiCount->setText (DataFunc::number (1).c_str ());
		}
		this->setItem (this->rowCount () - 1, 1, wiCount);		
		QTableWidgetItem * wiPrice = new QTableWidgetItem;
		wiPrice->setFlags (Qt::ItemIsSelectable | Qt::ItemIsEnabled);
		wiPrice->setText (DataFunc::number (data[4]).c_str ());
		this->setItem (this->rowCount () - 1, 2, wiPrice);
		if (adena_ == -1)
		{
			emit signalChangeIncome ();
		}
	}
}


void BuyWidget::dialog_ (int row)
{
	int res = 0;
	CountDialog * di;
	if (adena_ == -1)
	{
		if (this->amount_ (row) == 1)
		{
			res = 1;
		}
		else
		{
			di = new CountDialog ("How many <b>" + this->name_ (row) + "</b> would you like to buy? (max: " + QString (DataFunc::number (this->amount_ (row)).c_str ()) + ")", this->amount_ (row));
		}
	}
	else
	{
		di = new CountDialog ("How many <b>" + this->name_ (row) + "</b> would you like to buy?", 0);
	}	
	if (!res)
	{
		if (di->exec () == QDialog::Accepted)
		{
			res = di->result ();
		}
		delete di;
	}
	else
	{
		res = 1;
	}
	if (res)
	{
		int priced = -1;
		if (adena_ != -1)
		{
			CountDialog * di = new CountDialog ("What price do you want to set?", 0);
			if (di->exec () == QDialog::Accepted)
			{
				if (di->result ())
				{
					priced = di->result ();
				}
			}
			else
			{
				delete di;
				return;
			}
			delete di;
			if (priced == -1)
			{
				return;
			}
		}
		QString name = this->name_ (row);
		int amount = this->amount_ (row);
		vector <int> save = rowData_ (row, res, priced);
		if (adena_ == -1)
		{
			if (res == this->item (row, 1)->text ().toInt ())
			{
				deleteItem_ (row);
			}
			else
			{
				this->setAmount_ (row, amount - res);
			}
		}
		if (adena_ == -1)
		{
			emit signalAddItem (name, save);
			emit signalChangeIncome ();
		}
		else
		{
			emit signalAddItem (name, save);
		}
	}
}

bool BuyWidget::isStackable_ (int type2)
{
	if (type2 == 5)
	{
		return true;
	}
	else
	{
		return false;
	}
}

