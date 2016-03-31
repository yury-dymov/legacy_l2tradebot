#include "dialog.h"

PrivateStoreManageBuyList::PrivateStoreManageBuyList (const int adena, const vector <BuyItem> & items) : adena_ (adena)
{
	pOwn_ = new BuyWidget (0, 3, adena_);
	QList <QString> labels;
	labels.push_back ("Item");
	labels.push_back ("Amount");
	labels.push_back ("Price");
	pOwn_->setHorizontalHeaderLabels (QStringList (labels));
	pOwn_->verticalHeader ()->hide ();
	pOwn_->setColumnWidth (0, 230);
	pOwn_->setMaximumHeight (150);
	for (unsigned int i = 0; i < items.size (); ++i)
	{
		vector <int> addMe;
		addMe.push_back (items[i].itemId);
		addMe.push_back (items[i].h1);
		addMe.push_back (items[i].h2);
		addMe.push_back (items[i].count);
		addMe.push_back (items[i].price);
		addMe.push_back (items[i].type2);
		pOwn_->addItem (Data::itemName (items[i].itemId).c_str (), addMe);
	}
	la_ = new QVBoxLayout;
	la_->addWidget (new QLabel (tr ("Bag")));
	la_->addWidget (pOwn_);
	la_->addWidget (new QLabel (tr ("Private Store: Buy")));
	connect (Data::buyWidget (), SIGNAL (signalDeselect ()), pOwn_, SLOT (slotDeselect ()));
	connect (pOwn_, SIGNAL (signalDeselect ()), Data::buyWidget (), SLOT (slotDeselect ()));
	//connect (Data::buyWidget (), SIGNAL (signalAddItem (const QString &, const vector <int> &)), pOwn_, SLOT (slotAddRow (const QString &, const vector <int> &)));
	connect (pOwn_, SIGNAL (signalAddItem (const QString &, const vector <int> &)), Data::buyWidget (), SLOT (slotAddRow (const QString &, const vector <int> &)));
	connect (Data::buyWidget (), SIGNAL (signalChangeIncome ()), SLOT (slotChangeIncome ()));
	Data::buyWidget ()->setHorizontalHeaderLabels (QStringList (labels));
	Data::buyWidget ()->verticalHeader ()->hide ();
	Data::buyWidget ()->setColumnWidth (0, 230);
	Data::buyWidget ()->setMaximumHeight (150);
	adenaLabel_ = new QLabel ("Adena: " + QString (DataFunc::number (adena_).c_str ()));
	incomeLabel_ = new QLabel;
	slotChangeIncome ();
	la_->addWidget (Data::buyWidget ());
	infoLayout_ = new QHBoxLayout;
	infoLayout_->addSpacing (300);
	infoLayout_->addWidget (incomeLabel_);
	infoLayout_->addWidget (adenaLabel_);
	buttonsLayout_ = new QHBoxLayout;
	okButton_ = new QPushButton ("Ok");
	connect (okButton_, SIGNAL (pressed ()), SLOT (accept ()));
	cancelButton_ = new QPushButton ("Cancel");
	connect (cancelButton_, SIGNAL (pressed ()), SLOT (reject ()));
	messageButton_ = new QPushButton ("Set Message");
	connect (messageButton_, SIGNAL (pressed ()), SLOT (slotSetMessage ()));
	buttonsLayout_->addWidget (okButton_);
	buttonsLayout_->addWidget (messageButton_);
	buttonsLayout_->addWidget (cancelButton_);
	la_->addLayout (infoLayout_);
	la_->addLayout (buttonsLayout_);
	this->setLayout (la_);
	this->setWindowTitle (tr ("Private Store: Buy"));
	this->setMinimumWidth (478);
	this->setFixedSize (478, 500);
	this->move (400, 200);
}

void PrivateStoreManageBuyList::slotChangeIncome ()
{
	incomeLabel_->setText ("Price: " + QString (DataFunc::number (Data::buyWidget ()->income ()).c_str ()));
	pOwn_->setIncome (Data::buyWidget ()->income ());
}

void PrivateStoreManageBuyList::slotSetMessage ()
{
	SetMessageDialog * di = new SetMessageDialog ("", "Set message for private store");
	if (di->exec () == QDialog::Accepted)
	{
		Data::buyWidget ()->setMotd (di->result ().toStdString ());
	}
	delete di;
}

string PrivateStoreManageBuyList::packet ()
{
	string ret;
	return ret + Data::buyWidget ()->packet ();
}

PrivateStoreManageBuyList::~PrivateStoreManageBuyList ()
{
	delete okButton_;
	delete cancelButton_;
	delete messageButton_;
	delete buttonsLayout_;
	delete incomeLabel_;
	delete adenaLabel_;
	delete infoLayout_;
	delete pOwn_;
	delete la_;
}
