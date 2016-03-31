#include "tradewidget.h"

TradeWidget::TradeWidget (int p1, int p2) : QTableWidget (p1, p2)
{
	connect (this, SIGNAL (cellClicked (int, int)), SLOT (slotCellClicked (int, int)));
	connect (this, SIGNAL (cellDoubleClicked (int, int)), SLOT (slotCellDoubleClicked (int, int)));
	connect (this, SIGNAL (currentCellChanged (int, int, int, int)), SLOT (slotCurrentCellChanged (int, int, int, int)));
}

TradeWidget::~TradeWidget ()
{
	for (int i = 0; i < this->rowCount (); ++i)
	{
		for (int j = 0; j < this->columnCount (); ++j)
		{
			delete this->item (i, j);
		}
	}
}

void TradeWidget::froze ()
{
	for (int i = 0; i < this->rowCount (); ++i)
	{
		for (int j = 0; j < this->columnCount (); ++j)
		{
			this->item (i, j)->setFlags (Qt::NoItemFlags);
		}
	}
}

void TradeWidget::slotCellClicked (int row, int)
{
	for (int i = 0; i < this->columnCount (); ++i)
	{
		this->item (row, i)->setSelected (true);
	}
}

void TradeWidget::slotCellDoubleClicked (int row, int)
{
	dialog_ (row);
}

QString TradeWidget::name_ (int row) const
{
	return this->item (row, 0)->text ();
}

void TradeWidget::slotCurrentCellChanged (int row, int, int, int)
{
	if (row >= 0)
	{
		for (int i = 0; i < this->columnCount (); ++i)
		{
			this->item (row, i)->setSelected (true);
		}	
	}
}

void TradeWidget::setAmount_ (int row, int val)
{
	this->item (row, 1)->setText (DataFunc::number (val).c_str ());
}

int TradeWidget::amount_ (int row) const
{
	return DataFunc::toNumber (this->item (row, 1)->text ().toStdString ());
}

TradeUpperWidget::TradeUpperWidget (int x, int y) : TradeWidget (x, y), froze_ (false)
{
}

void TradeUpperWidget::dialog_ (int row)
{
	if (!froze_)
	{
		int res = 1;
		if (this->amount_ (row) > 1)
		{
			CountDialog * di = new CountDialog ("How many <b>" + this->name_ (row) + "</b> would you like to trade? (max: " + QString (DataFunc::number ( this->amount_ (row)).c_str ()) + ")", this->amount_ (row));
			if (di->exec () == QDialog::Accepted)
			{
				res = di->result ();
			}
			delete di;			
		}
		emit sendPacket (GamePacket::addTradeItem (1, this->objectId_ [row], res));
	}
}

void TradeUpperWidget::froze ()
{
	froze_ = true;
	TradeWidget::froze ();
}

void TradeUpperWidget::addItem (const QString & name, const vector <int> & data)
{
		// data[0] - objectId, data [1] - count, data[2] - itemId
	QTableWidgetItem * wiName = new QTableWidgetItem;
	wiName->setFlags (Qt::ItemIsSelectable | Qt::ItemIsEnabled);
	wiName->setText (name);
	this->setRowCount (rowCount () + 1);
	this->setItem (this->rowCount () - 1, 0, wiName);		
	this->objectId_ [this->rowCount () - 1] = data[0];
	this->itemId_ [this->rowCount () - 1] = data[2];
	QTableWidgetItem * wiCount = new QTableWidgetItem;
	wiCount->setFlags (Qt::ItemIsSelectable | Qt::ItemIsEnabled);
	wiCount->setText (DataFunc::number (data[1]).c_str ());
	wiName->setToolTip (Dat::itemDesc (data[2]).c_str ());
	this->setItem (this->rowCount () - 1, 1, wiCount);		
}

void TradeUpperWidget::deleteItem (int objectId, int itemId, int count)
{
	for (int i = 0; i < this->rowCount (); ++i)
	{
		if (this->objectId_[i] == objectId)
		{
			for (int k = i + 1; k < this->rowCount (); ++k)
			{
				for (int j = 0; j < this->columnCount (); ++j)
				{
					this->item (k - 1, j)->setText (this->item (k, j)->text ());
				}
				this->objectId_[k - 1] = this->objectId_ [k];
				this->itemId_[k - 1] = this->itemId_ [k];
			}
			for (int j = 0; j < this->columnCount (); ++j)
			{
				delete this->item (this->rowCount () - 1, j);
			}
			this->setRowCount (this->rowCount () - 1);
			return;
		}
	}
	for (int i = 0; i < this->rowCount (); ++i)
	{
		if (this->itemId_ [i] == itemId)
		{
			this->setAmount_ (i, this->amount_ (i) - count);
			return;
		}
	}
}

TradeCharWidget::TradeCharWidget (int x, int y) : TradeWidget (x, y)
{
}

void TradeCharWidget::dialog_ (int)
{
}

void TradeCharWidget::addItem (const QString & name, int count)
{
	QTableWidgetItem * wiName = new QTableWidgetItem;
	wiName->setFlags (Qt::ItemIsSelectable | Qt::ItemIsEnabled);
	wiName->setText (name);
	this->setRowCount (rowCount () + 1);
	this->setItem (this->rowCount () - 1, 0, wiName);		
	QTableWidgetItem * wiCount = new QTableWidgetItem;
	wiCount->setFlags (Qt::ItemIsSelectable | Qt::ItemIsEnabled);
	wiCount->setText (DataFunc::number (count).c_str ());
	this->setItem (this->rowCount () - 1, 1, wiCount);
}


TradeUserWidget::TradeUserWidget (int x, int y) : TradeWidget (x, y)
{
}

void TradeUserWidget::dialog_ (int)
{
}

void TradeUserWidget::addItem (const QString & name, int count)
{
	QTableWidgetItem * wiName = new QTableWidgetItem;
	wiName->setFlags (Qt::ItemIsSelectable | Qt::ItemIsEnabled);
	wiName->setText (name);
	this->setRowCount (rowCount () + 1);
	this->setItem (this->rowCount () - 1, 0, wiName);		
	QTableWidgetItem * wiCount = new QTableWidgetItem;
	wiCount->setFlags (Qt::ItemIsSelectable | Qt::ItemIsEnabled);
	wiCount->setText (DataFunc::number (count).c_str ());
	this->setItem (this->rowCount () - 1, 1, wiCount);
}



