#include "playersellbuy.h"

PlayerSellWidget::PlayerSellWidget (int p1, int p2, int adena, int package) : TableWidget (p1, p2, adena), package_ (package)
{
}

string PlayerSellWidget::packet ()
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

void PlayerSellWidget::deleteItem_ (int row)
{
	for (int i = row + 1; i < this->rowCount (); ++i)
	{
		for (int j = 0; j < this->columnCount (); ++j)
		{
			this->item (i - 1, j)->setText (this->item (i, j)->text ());
		}
		this->type2_[i - 1] = this->type2_ [i];
		this->objectId_[i - 1] = this->objectId_ [i];
		this->itemId_[i - 1] = this->itemId_ [i];
		this->h1_[i - 1] = this->h1_ [i];
		this->enchant_[i - 1] = this->enchant_ [i];
		this->h2_[i - 1] = this->h2_ [i];
		this->bodyPart_[i - 1] = this->bodyPart_ [i];
		this->storePrice_[i - 1] = this->storePrice_ [i];
	}
	for (int j = 0; j < this->columnCount (); ++j)
	{
		delete this->item (this->rowCount () - 1, j);
	}
	this->setRowCount (this->rowCount () - 1);
}

void PlayerSellWidget::addItem (const QString & name, const vector <int> & data)
{
	// data[0] - type2, data[1] - objId, data[2] - itemId, data[3] - count, data[4] - h1, data[5] - enchant, data[6] - h2. data[7] - bodyPart, body[8] - price, body[9] - storePrice
	int size = this->rowCount ();
	for (int i = 0; i < size; ++i)
	{
		if (objectId_ [i] == data[1])
		{
			this->setAmount_ (i, this->amount_ (i) + data[3]);
			if (adena_ == -1)
			{
				this->setPrice_ (i, data[8]);
				emit signalChangeIncome ();
			}
			return;
		}
	}
	this->objectId_ [this->rowCount ()] = data[1];
	this->itemId_ [this->rowCount ()] = data[2];
	this->h1_ [this->rowCount ()] = data[4];
	this->enchant_ [this->rowCount ()] = data[5];
	this->h2_ [this->rowCount ()] = data[6];
	this->bodyPart_ [this->rowCount ()] = data[7];
	this->storePrice_ [this->rowCount ()] = data[9];
	this->setRowCount (this->rowCount () + 1);
	QTableWidgetItem * wiName = new QTableWidgetItem;
	wiName->setFlags (Qt::ItemIsSelectable | Qt::ItemIsEnabled);
	wiName->setText (name);
	wiName->setToolTip (Dat::itemDesc (data[2]).c_str ());
	this->setItem (this->rowCount () - 1, 0, wiName);		
	QTableWidgetItem * wiCount = new QTableWidgetItem;
	wiCount->setFlags (Qt::ItemIsSelectable | Qt::ItemIsEnabled);
	wiCount->setText (DataFunc::number (data[3]).c_str ());
	this->setItem (this->rowCount () - 1, 1, wiCount);		
	QTableWidgetItem * wiPrice = new QTableWidgetItem;
	wiPrice->setFlags (Qt::ItemIsSelectable | Qt::ItemIsEnabled);
	wiPrice->setText (DataFunc::number (data[8]).c_str ());
	this->setItem (this->rowCount () - 1, 2, wiPrice);
	if (adena_ == -1)
	{
		emit signalChangeIncome ();
	}
}

vector <int> PlayerSellWidget::rowData_ (int row, int amount, int price)
{
	vector <int> ret;
	ret.push_back (type2_ [row]);
	ret.push_back (objectId_ [row]);
	ret.push_back (itemId_ [row]);
	ret.push_back (amount);
	ret.push_back (h1_ [row]);
	ret.push_back (enchant_ [row]);
	ret.push_back (h2_ [row]);
	ret.push_back (bodyPart_ [row]);
	ret.push_back (price);
	ret.push_back (storePrice_ [row]);
	return ret;
}

void PlayerSellWidget::dialog_ (int row)
{
	if (package_)
	{
		int count = this->rowCount ();
		for (int i = 0; i < count; ++i)
		{
			emit signalAddItem (this->name_ (0), this->rowData_ (0, this->amount_ (0), this->price_ (0)));
			this->deleteItem_ (0);
			if (adena_ == -1)
			{
				emit signalChangeIncome ();
			}
		}
	}
	else
	{
		int res = 0;
		if (this->amount_ (row) > 1)
		{
			CountDialog * di = new CountDialog ("How many <b>" + this->name_ (row) + "</b> would you like to buy? (max: " + QString (DataFunc::number (this->amount_ (row)).c_str ()) + ")", this->amount_ (row));
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
			int priced = this->price_ (row);
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
}

PlayerBuyWidget::PlayerBuyWidget (int p1, int p2, int adena) : TableWidget (p1, p2, adena)
{
}

string PlayerBuyWidget::packet ()
{
	string ret;
	if (this->rowCount ())
	{
		ret += DataFunc::intToString (this->rowCount ());
		for (int i = 0; i < this->rowCount (); ++i)
		{
			ret += DataFunc::intToString (this->objectId_ [i]);
			ret += DataFunc::intToString (this->itemId_ [i]);
			ret += DataFunc::intToString (this->h1_ [i], 2);
			ret += DataFunc::intToString (this->h1_ [i], 2);
			ret += DataFunc::intToString (this->amount_ (i));
			ret += DataFunc::intToString (this->price_ (i));
		}
	}
	return ret;
}

void PlayerBuyWidget::deleteItem_ (int row)
{
	for (int i = row + 1; i < this->rowCount (); ++i)
	{
		for (int j = 0; j < this->columnCount (); ++j)
		{
			this->item (i - 1, j)->setText (this->item (i, j)->text ());
		}
		this->objectId_[i - 1] = this->objectId_ [i];
		this->itemId_[i - 1] = this->itemId_ [i];
		this->enchant_[i - 1] = this->enchant_ [i];
		this->refPrice_[i - 1] = this->refPrice_ [i];
		this->h1_[i - 1] = this->h1_ [i];
		this->bodyPart_[i - 1] = this->bodyPart_ [i];
		this->type2_[i - 1] = this->type2_ [i];
		this->playerCount_ [i - 1] = this->playerCount_ [i];
	}
	for (int j = 0; j < this->columnCount (); ++j)
	{
		delete this->item (this->rowCount () - 1, j);
	}
	this->setRowCount (this->rowCount () - 1);
}

void PlayerBuyWidget::addItem (const QString & name, const vector <int> & data)
{
	// data[0] - objectId, data[1] - itemId, data[2] - enchant, data[3] - count, data[4] - refPrice, data[5] - h1, data[6] - bodyPart. data[7] - type2, body[8] - price, body[9] - count
	int size = this->rowCount ();
	for (int i = 0; i < size; ++i)
	{
		if (objectId_ [i] == data[0])
		{
			this->setAmount_ (i, this->amount_ (i) + data[3]);
			if (adena_ == -1)
			{
				this->setPrice_ (i, data[8]);
				emit signalChangeIncome ();
			}
			return;
		}
	}
	this->objectId_ [this->rowCount ()] = data[0];
	this->itemId_ [this->rowCount ()] = data[1];
	this->enchant_ [this->rowCount ()] = data[2];
	this->refPrice_ [this->rowCount ()] = data[4];
	this->h1_ [this->rowCount ()] = data[5];
	this->bodyPart_ [this->rowCount ()] = data[6];
	this->type2_ [this->rowCount ()] = data[7];
	this->playerCount_ [this->rowCount ()] = data [9];
	this->setRowCount (this->rowCount () + 1);
	QTableWidgetItem * wiName = new QTableWidgetItem;
	if (data[9])
	{
		wiName->setFlags (Qt::ItemIsSelectable | Qt::ItemIsEnabled);
	}
	else
	{
		wiName->setFlags (Qt::NoItemFlags);
	}
	wiName->setText (name);
	wiName->setToolTip (Dat::itemDesc (data[1]).c_str ());
	this->setItem (this->rowCount () - 1, 0, wiName);		
	QTableWidgetItem * wiCount = new QTableWidgetItem;
	if (data[9])
	{
		wiCount->setFlags (Qt::ItemIsSelectable | Qt::ItemIsEnabled);
	}
	else
	{
		wiName->setFlags (Qt::NoItemFlags);
	}
	wiCount->setText (DataFunc::number (data[3]).c_str ());
	this->setItem (this->rowCount () - 1, 1, wiCount);		
	QTableWidgetItem * wiPrice = new QTableWidgetItem;
	if (data[9])
	{
		wiPrice->setFlags (Qt::ItemIsSelectable | Qt::ItemIsEnabled);
	}
	else
	{
		wiName->setFlags (Qt::NoItemFlags);
	}
	wiPrice->setText (DataFunc::number (data[8]).c_str ());
	this->setItem (this->rowCount () - 1, 2, wiPrice);
	if (adena_ == -1)
	{
		emit signalChangeIncome ();
	}
}

vector <int> PlayerBuyWidget::rowData_ (int row, int amount, int price)
{
	vector <int> ret;
	ret.push_back (objectId_ [row]);
	ret.push_back (itemId_ [row]);
	ret.push_back (enchant_ [row]);
	ret.push_back (amount);
	ret.push_back (refPrice_ [row]);
	ret.push_back (h1_ [row]);
	ret.push_back (bodyPart_ [row]);
	ret.push_back (type2_ [row]);
	ret.push_back (price);
	ret.push_back (playerCount_ [row]);
	return ret;
}

void PlayerBuyWidget::dialog_ (int row)
{
	int res = 0;
	if (this->amount_ (row) > 1)
	{
		CountDialog * di = new CountDialog ("How many <b>" + this->name_ (row) + "</b> would you like to sell? (max: " + QString (DataFunc::number (min (this->amount_ (row), this->playerCount_ [row])).c_str ()) + ")", min (this->amount_ (row), this->playerCount_ [row]));
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
		int priced = this->price_ (row);
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
			playerCount_ [row] -= res;
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
