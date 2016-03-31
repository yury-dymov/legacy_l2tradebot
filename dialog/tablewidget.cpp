#include "tablewidget.h"

TableWidget::TableWidget (int p1, int p2, int adena) : QTableWidget (p1, p2), adena_ (adena), income_ (0)
{
	connect (this, SIGNAL (cellClicked (int, int)), SLOT (slotCellClicked (int, int)));
	connect (this, SIGNAL (cellDoubleClicked (int, int)), SLOT (slotCellDoubleClicked (int, int)));
	connect (this, SIGNAL (currentCellChanged (int, int, int, int)), SLOT (slotCurrentCellChanged (int, int, int, int)));
}

void TableWidget::slotCellClicked (int row, int)
{
	for (int i = 0; i < this->columnCount (); ++i)
	{
		this->item (row, i)->setSelected (true);
	}
	emit signalDeselect ();
}

void TableWidget::slotCellDoubleClicked (int row, int)
{
	dialog_ (row);
}

void TableWidget::slotCurrentCellChanged (int row, int, int, int)
{
	if (row >= 0)
	{
		for (int i = 0; i < this->columnCount (); ++i)
		{
			this->item (row, i)->setSelected (true);
		}	
		emit signalDeselect ();
	}
}


int TableWidget::income () const
{
	int ret = 0;
	for (int i = 0; i < this->rowCount (); ++i)
	{
		ret += price_ (i) * amount_ (i);
	}
	return ret;
}

QString TableWidget::name_ (int row) const
{
	return this->item (row, 0)->text ();
}

int TableWidget::price_ (int row) const
{
	return DataFunc::toNumber (this->item (row, 2)->text ().toStdString ());
}

void TableWidget::setIncome (int val)
{
	income_ = val;
}

void TableWidget::setPrice_ (int row, int price)
{
	this->item (row, 2)->setText (DataFunc::number (price).c_str ());
}

void TableWidget::slotAddRow (const QString & name, const vector <int> & data)
{
	addItem (name, data);
}

void TableWidget::slotDeselect ()
{
	for (int i = 0; i < this->columnCount (); ++i)
	{
		for (int j = 0; j < this->rowCount (); ++j)
		{
			this->item (j, i)->setSelected (false);
		}
	}
}

void TableWidget::setAmount_ (int row, int val)
{
	this->item (row, 1)->setText (DataFunc::number (val).c_str ());
}

int TableWidget::amount_ (int row) const
{
	return DataFunc::toNumber (this->item (row, 1)->text ().toStdString ());
}

void TableWidget::setMotd (const string & str)
{
	motd_ = str;
}

string TableWidget::motd () const
{
	return motd_;
}

TableWidget::~TableWidget ()
{
	for (int i = 0; i < this->rowCount (); ++i)
	{
		for (int j = 0; j < this->columnCount (); ++j)
		{
			delete this->item (i, j);
		}
	}
}

