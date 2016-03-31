#include "trade.h"

Trade::Trade (const string & name, int /*objectId*/, const vector <TradeItem> & items)
{
	QList <QString> labels;
	labels.push_back ("Item");
	labels.push_back ("Amount");
	bagLabel_ = new QLabel ("Bag");
	userLabel_ = new QLabel ("My Trade");
	charLabel_ = new QLabel (name.c_str ());
	okButton_ = new QPushButton ("Ok");
	upper_ = new TradeUpperWidget ();
	connect (upper_, SIGNAL (sendPacket (const string &)), SLOT (slotRecievePacket (const string &)));
	upper_->setHorizontalHeaderLabels (QStringList (labels));
	upper_->verticalHeader ()->hide ();
	upper_->setColumnWidth (0, 230);
	upper_->setMaximumHeight (150);
	upper_->setMinimumHeight (150);		
	for (unsigned int i = 0; i < items.size (); ++i)
	{
		vector <int> add;
		add.push_back (items[i].objectId);
		add.push_back (items[i].count);
		add.push_back (items[i].itemId);
		if (items[i].enchantLevel)
		{
			upper_->addItem ((Data::itemName (items[i].itemId) + " +" + Convert (items[i].enchantLevel).toString ()).c_str (), add);
		}
		else
		{
			upper_->addItem (Data::itemName (items[i].itemId).c_str (), add);
		}
	}
	char_ = new TradeCharWidget ();
	char_->setHorizontalHeaderLabels (QStringList (labels));
	char_->verticalHeader ()->hide ();
	char_->setColumnWidth (0, 230);
	char_->setMaximumHeight (150);
	char_->setMinimumHeight (150);		
	user_ = new TradeUserWidget ();
	user_->setHorizontalHeaderLabels (QStringList (labels));
	user_->verticalHeader ()->hide ();
	user_->setColumnWidth (0, 230);
	user_->setMaximumHeight (150);
	user_->setMinimumHeight (150);		
	connect (okButton_, SIGNAL (pressed ()), SLOT (slotOk ()));
	cancelButton_ = new QPushButton ("Cancel");
	connect (cancelButton_, SIGNAL (pressed ()), SLOT (slotCancel ()));
	buttonsLayout_ = new QHBoxLayout ();
	buttonsLayout_->addWidget (okButton_);
	buttonsLayout_->addWidget (cancelButton_);
	mainLayout_ = new QVBoxLayout ();
	mainLayout_->addWidget (bagLabel_);
	mainLayout_->addWidget (upper_);
	mainLayout_->addWidget (userLabel_);
	mainLayout_->addWidget (user_);
	mainLayout_->addWidget (charLabel_);
	mainLayout_->addWidget (char_);
	mainLayout_->addLayout (buttonsLayout_);
	this->setLayout (mainLayout_);
	this->resize (380, 400);
	this->move (300, 100);
	this->setFixedSize (380, 540);
	this->setWindowTitle ("Trade");
	this->show ();
}

Trade::~Trade ()
{
	delete bagLabel_;
	delete userLabel_;
	delete charLabel_;
	delete okButton_;
	delete cancelButton_;
	delete upper_;
	delete char_;
	delete user_;
	delete buttonsLayout_;
	delete mainLayout_;
}

void Trade::slotRecievePacket (const string & pck)
{
	emit sendPacket (pck);
}

void Trade::tradeOwnAdd (const vector <TradeItem> & items)
{
	for (unsigned int i = 0; i < items.size (); ++i)
	{
		upper_->deleteItem (items[i].objectId, items[i].itemId, items[i].count);
		user_->addItem (Data::itemName (items[i].itemId).c_str (), items[i].count);
	}
}

void Trade::tradeOtherAdd (const vector <TradeItem> & items)
{
	for (unsigned int i = 0; i < items.size (); ++i)
	{
		char_->addItem (Data::itemName (items[i].itemId).c_str (), items[i].count);
	}
}

void Trade::slotOk ()
{
	emit sendPacket (GamePacket::tradeDone (1));
}

void Trade::slotCancel ()
{
	emit sendPacket (GamePacket::tradeDone (0));
}

void Trade::tradePressOwnOk ()
{
	upper_->froze ();
	user_->froze ();
	okButton_->setEnabled (false);
}

void Trade::tradePressOtherOk ()
{
	char_->froze ();
}
