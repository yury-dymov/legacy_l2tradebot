#include "npcsellbuy.h"

NpcTradeBuy::NpcTradeBuy (int adena, const vector <NpcBuyItem> & items)
{
	upLabel_ = new QLabel ("Bag");
	downLabel_ = new QLabel ("Sell List");
	okButton_ = new QPushButton ("Ok");
	connect (okButton_, SIGNAL (pressed ()), SLOT (accept ()));
	cancelButton_ = new QPushButton ("Cancel");
	connect (cancelButton_, SIGNAL (pressed ()), SLOT (reject ()));
	buttonsLayout_ = new QHBoxLayout ();
	buttonsLayout_->addWidget (okButton_);
	buttonsLayout_->addWidget (cancelButton_);
	adenaLabel_ = new QLabel (QString ("Adena: ") + DataFunc::number (adena).c_str ());
	totalLabel_ = new QLabel ("Income: 0");
	upWidget_ = new NpcBuyWidget (0, 3);
	for (unsigned int i = 0; i < items.size (); ++i)
	{
		vector <int> add;
		add.push_back (items[i].itemType1);
		add.push_back (items[i].itemId);
		add.push_back (items[i].itemType2);
		add.push_back (items[i].refPrice);
		add.push_back (items[i].count);
		add.push_back (items[i].objectId);
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
	downWidget_ = new NpcBuyWidget (0, 3);
	connect (downWidget_, SIGNAL (changeTotal (int)), SLOT (changeTotal (int)));
	connect (downWidget_, SIGNAL (signalAddItem (const QString &, const vector <int> &)), upWidget_, SLOT (addItem (const QString &, const vector <int> &)));
	connect (upWidget_, SIGNAL (signalAddItem (const QString &, const vector <int> &)), downWidget_, SLOT (addItem (const QString &, const vector <int> &)));
	QList <QString> labels;
	labels.push_back ("Item");
	labels.push_back ("Amount");
	labels.push_back ("Price");
	upWidget_->setHorizontalHeaderLabels (QStringList (labels));
	upWidget_->verticalHeader ()->hide ();
	downWidget_->setHorizontalHeaderLabels (QStringList (labels));
	downWidget_->verticalHeader ()->hide ();
	upWidget_->setColumnWidth (0, 230);
	upWidget_->setMaximumHeight (150);
	upWidget_->setMinimumHeight (150);
	downWidget_->setColumnWidth (0, 230);
	downWidget_->setMinimumHeight (150);
	downWidget_->setMaximumHeight (150);
	mainLayout_ = new QVBoxLayout ();
	mainLayout_->addWidget (upLabel_);
	mainLayout_->addWidget (upWidget_);
	mainLayout_->addWidget (downLabel_);
	mainLayout_->addWidget (downWidget_);
	mainLayout_->addWidget (totalLabel_);
	mainLayout_->addWidget (adenaLabel_);
	mainLayout_->addLayout (buttonsLayout_);
	this->setLayout (mainLayout_);
	this->setWindowTitle (tr ("Npc Store"));
	this->setMinimumWidth (478);
	this->setFixedSize (478, 500);
	this->move (400, 200);
	this->show ();
}

NpcTradeBuy::~NpcTradeBuy ()
{
	delete adenaLabel_;
	delete totalLabel_;
	delete upLabel_;
	delete downLabel_;
	delete okButton_;
	delete cancelButton_;
	delete upWidget_;
	delete downWidget_;
	delete buttonsLayout_;
	delete mainLayout_;
}

void NpcTradeBuy::changeTotal (int total)
{
	totalLabel_->setText (QString ("Income: ") + DataFunc::number (total).c_str ());
}

string NpcTradeBuy::packet ()
{
	return downWidget_->packet ();
}
