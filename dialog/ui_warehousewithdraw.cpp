#include "warehouse.h"

WarehouseWithdraw::WarehouseWithdraw (int adena, const vector <WarehouseItem> & items)
{
	upLabel_ = new QLabel ("Warehouse");
	downLabel_ = new QLabel ("Bag");
	okButton_ = new QPushButton ("Ok");
	connect (okButton_, SIGNAL (pressed ()), SLOT (accept ()));
	cancelButton_ = new QPushButton ("Cancel");
	connect (cancelButton_, SIGNAL (pressed ()), SLOT (reject ()));
	buttonsLayout_ = new QHBoxLayout ();
	buttonsLayout_->addWidget (okButton_);
	buttonsLayout_->addWidget (cancelButton_);
	adenaLabel_ = new QLabel (QString ("Adena: ") + DataFunc::number (adena).c_str ());
	upWidget_ = new WarehouseDepositWidget (0, 2);
	for (unsigned int i = 0; i < items.size (); ++i)
	{
		vector <int> add;
		add.push_back (items[i].itemType1);
		add.push_back (items[i].itemId);
		add.push_back (items[i].itemType2);
		add.push_back (items[i].count);
		add.push_back (items[i].objectId);
		add.push_back (items[i].objectId2);
		add.push_back (items[i].enchantLevel);
		if (items[i].enchantLevel)
		{
			upWidget_->addItem ((Data::itemName (items[i].itemId) + " +" + Convert (items[i].enchantLevel).toString ()).c_str (), add);
		}
		else
		{
			upWidget_->addItem (Data::itemName (items[i].itemId).c_str (), add);
		}
	}
	downWidget_ = new WarehouseDepositWidget (0, 2);
	connect (downWidget_, SIGNAL (signalAddItem (const QString &, const vector <int> &)), upWidget_, SLOT (addItem (const QString &, const vector <int> &)));
	connect (upWidget_, SIGNAL (signalAddItem (const QString &, const vector <int> &)), downWidget_, SLOT (addItem (const QString &, const vector <int> &)));
	QList <QString> labels;
	labels.push_back ("Item");
	labels.push_back ("Amount");
	upWidget_->setHorizontalHeaderLabels (QStringList (labels));
	upWidget_->verticalHeader ()->hide ();
	downWidget_->setHorizontalHeaderLabels (QStringList (labels));
	downWidget_->verticalHeader ()->hide ();
	upWidget_->setColumnWidth (0, 230);
	upWidget_->setColumnWidth (1, 200);
	upWidget_->setMaximumHeight (150);
	upWidget_->setMinimumHeight (150);
	downWidget_->setColumnWidth (0, 230);
	downWidget_->setColumnWidth (1, 200);
	downWidget_->setMinimumHeight (150);
	downWidget_->setMaximumHeight (150);
	mainLayout_ = new QVBoxLayout ();
	mainLayout_->addWidget (upLabel_);
	mainLayout_->addWidget (upWidget_);
	mainLayout_->addWidget (downLabel_);
	mainLayout_->addWidget (downWidget_);
	mainLayout_->addWidget (adenaLabel_);
	mainLayout_->addLayout (buttonsLayout_);
	this->setLayout (mainLayout_);
	this->setWindowTitle (tr ("Warehouse Keeper"));
	this->setMinimumWidth (478);
	this->setFixedSize (478, 500);
	this->move (400, 200);
	this->show ();
}

WarehouseWithdraw::~WarehouseWithdraw ()
{
	delete adenaLabel_;
	delete upLabel_;
	delete downLabel_;
	delete okButton_;
	delete cancelButton_;
	delete upWidget_;
	delete downWidget_;
	delete buttonsLayout_;
	delete mainLayout_;
}

string WarehouseWithdraw::packet ()
{
	return downWidget_->packet ();
}


