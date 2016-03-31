#include "bag.h"

BagWidget::BagWidget () : QTableWidget (0, 3)
{
	connect (this, SIGNAL (cellDoubleClicked (int, int)), SLOT (slotDoubleClicked (int, int)));
	connect (this, SIGNAL (cellClicked (int, int)), SLOT (slotCellClicked (int, int)));
	connect (this, SIGNAL (currentCellChanged (int, int, int, int)), SLOT (slotCurrentCellChanged (int, int, int, int)));
	QList <QString> labels;
	labels.push_back ("Item");
	labels.push_back ("Count");
	labels.push_back ("Equipped");
	this->setHorizontalHeaderLabels (QStringList (labels));
	this->installEventFilter (this);
	this->setColumnWidth (0, 190);
	this->verticalHeader ()->hide ();
	this->show ();
}

BagWidget::~BagWidget ()
{
}

void BagWidget::deleteRow_ (int row)
{
	for (int i = row + 1; i < this->rowCount (); ++i)
	{
		for (int j = 0; j < this->columnCount (); ++j)
		{
			this->item (i - 1, j)->setText (this->item (i, j)->text ());
		}
		this->item_ [i - 1] = this->item_[i];
	}
	for (int j = 0; j < this->columnCount (); ++j)
	{
		delete this->item (this->rowCount () - 1, j);
	}
	this->setRowCount (this->rowCount () - 1);
	Data::bag.clear ();
	for (int i = 0; i < this->rowCount (); ++i)
	{
		Data::bag.push_back (item_[i]);
	}
	item_.clear ();
	item_ = Data::bag;
}

void BagWidget::slotDoubleClicked (int row, int)
{
	BagDialog * ui = new BagDialog (item_ [row].objectId, item_[row].count, Data::itemCrystallizable (item_ [row].itemId));
	if (ui->exec () == QDialog::Accepted)
	{
		if (ui->pushed () == 0)
		{
			emit signalWrite (GamePacket::useItem (item_ [row].objectId, 0));
		}
		else if (ui->pushed () == 1)
		{
			emit signalWrite (GamePacket::requestDestroyItem (item_[row].objectId, ui->count ()));
		}
		else if (ui->pushed () == 2)
		{
			emit signalWrite (GamePacket::requestCrystallizeItem (item_ [row].objectId, 1));
		}
	}
	delete ui;
}

void BagWidget::setInventory (const vector <InventoryItem> & items)
{
	if (items.size ())
	{
		if (items[0].updateId == E_INVENTORY_NONE)
		{
			int count = this->rowCount ();
			for (int i = 0; i < count; ++i)
			{
				deleteRow_ (0);
			}
			item_ = items;
			for (unsigned int i = 0; i < item_.size (); ++i)
			{
				this->addRow_ (item_[i]);
			}
		}
		else
		{
			for (unsigned int i = 0; i < items.size (); ++i)
			{
				int row = 0;
				for (unsigned int j = 0; j < item_.size (); ++j)
				{
					if (items[i].objectId == item_[j].objectId)
					{
						row = j;
						break;
					}
				}
				switch (items[i].updateId)
				{
					case E_INVENTORY_REMOVE:
						deleteRow_ (row);
						break;
					case E_INVENTORY_ADD:
						this->addRow_ (items[i]);
						break;
					case E_INVENTORY_MOD:
						item_ [row] = items[i];
						Data::bag [row] = items[i];
						this->item (row, 1)->setText (DataFunc::number (item_[row].count).c_str ());
						if (item_ [row].isEquipped)
						{
							this->item (row, 2)->setText ("Yes");
						}
						else
						{
							this->item (row, 2)->setText ("");
						}
						break;
				}
			}
		}
	}
}

void BagWidget::addRow_ (const InventoryItem & item)
{
	Data::bag.push_back (item);
	int id = item.itemId;
	int isEquipped = item.isEquipped;
	int count = item.count;
	QString name = Data::itemName (id).c_str ();
	if (item.enchantLevel)
	{
		name += " +";
		name += Convert (item.enchantLevel).toString ().c_str ();
	}
	if (item.augId)
	{
		name += " Augmented";
	}
	this->setRowCount (this->rowCount () + 1);
	QTableWidgetItem * wiName = new QTableWidgetItem;
	wiName->setFlags (Qt::ItemIsSelectable | Qt::ItemIsEnabled);
	wiName->setText (name);
	wiName->setToolTip (Data::itemDesc (item.itemId).c_str ());
	this->setItem (this->rowCount () - 1, 0, wiName);		
	QTableWidgetItem * wiCount = new QTableWidgetItem;
	wiCount->setFlags (Qt::ItemIsSelectable | Qt::ItemIsEnabled);
	wiCount->setText (DataFunc::number (count).c_str ());
	wiCount->setToolTip (Data::itemDesc (item.itemId).c_str ());
	this->setItem (this->rowCount () - 1, 1, wiCount);		
	QTableWidgetItem * wiPrice = new QTableWidgetItem;
	wiPrice->setFlags (Qt::ItemIsSelectable | Qt::ItemIsEnabled);
	if (isEquipped)
	{
		wiPrice->setText ("Yes");
	}
	wiPrice->setToolTip (Data::itemDesc (item.itemId).c_str ());
	this->setItem (this->rowCount () - 1, 2, wiPrice);	
}

void BagWidget::slotCellClicked (int row, int)
{
	for (int i = 0; i < this->columnCount (); ++i)
	{
		this->item (row, i)->setSelected (true);
	}
}

void BagWidget::slotCurrentCellChanged (int row, int, int, int)
{
	if (row >= 0)
	{
		for (int i = 0; i < this->columnCount (); ++i)
		{
			this->item (row, i)->setSelected (true);
		}	
	}
}

void BagWidget::slotEnterWorld (bool)
{
	int count = this->rowCount ();
	for (int i = 0; i < count; ++i)
	{
		deleteRow_ (i);
	}
	item_.clear ();
}


