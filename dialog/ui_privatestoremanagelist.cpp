#include "privatestore.h"

PrivateStoreManageList::PrivateStoreManageList (const int package, const int adena, const vector <SellItem> & items) : package_ (package), adena_ (adena)
{
	pOwn_ = new SellWidget (0, 3, adena_);
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
		addMe.push_back (items[i].count);
		addMe.push_back (items[i].price);
		addMe.push_back (items[i].objectId);
		addMe.push_back (items[i].itemId);
		if (items[i].enchant)
		{
			pOwn_->addItem ((Data::itemName (items[i].itemId) + " +" + Convert (items[i].enchant).toString ()).c_str (), addMe);
		}
		else
		{
			pOwn_->addItem (Data::itemName (items[i].itemId).c_str (), addMe);
		}
	}
	la_ = new QVBoxLayout;
	la_->addWidget (new QLabel (tr ("Bag")));
	la_->addWidget (pOwn_);
	la_->addWidget (new QLabel (tr ("Private Store: Sell")));
	connect (Data::sellWidget (), SIGNAL (signalDeselect ()), pOwn_, SLOT (slotDeselect ()));
	connect (pOwn_, SIGNAL (signalDeselect ()), Data::sellWidget (), SLOT (slotDeselect ()));
	connect (Data::sellWidget (), SIGNAL (signalAddItem (const QString &, const vector <int> &)), pOwn_, SLOT (slotAddRow (const QString &, const vector <int> &)));
	connect (pOwn_, SIGNAL (signalAddItem (const QString &, const vector <int> &)), Data::sellWidget (), SLOT (slotAddRow (const QString &, const vector <int> &)));
	connect (Data::sellWidget (), SIGNAL (signalChangeIncome ()), SLOT (slotChangeIncome ()));
	Data::sellWidget ()->setHorizontalHeaderLabels (QStringList (labels));
	Data::sellWidget ()->verticalHeader ()->hide ();
	Data::sellWidget ()->setColumnWidth (0, 230);
	Data::sellWidget ()->setMaximumHeight (150);
	adenaLabel_ = new QLabel ("Adena: " + QString (DataFunc::number (adena_).c_str ()));
	incomeLabel_ = new QLabel;
	slotChangeIncome ();
	la_->addWidget (Data::sellWidget ());
	infoLayout_ = new QHBoxLayout;
	packageCheckbox_ = new QCheckBox;
	packageCheckbox_->setChecked (Data::sellWidget ()->package ());
	packageLabel_ = new QLabel ("Package");
	infoLayout_->addWidget (packageCheckbox_);
	infoLayout_->addWidget (packageLabel_);
	infoLayout_->addSpacing (200);
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
	this->setWindowTitle (tr ("Private Store: Sell"));
	this->setMinimumWidth (478);
	this->setFixedSize (478, 500);
	this->move (400, 200);
}

void PrivateStoreManageList::slotChangeIncome ()
{
	incomeLabel_->setText ("Income: " + QString (DataFunc::number (Data::sellWidget ()->income ()).c_str ()));
	pOwn_->setIncome (Data::sellWidget ()->income ());
}

void PrivateStoreManageList::slotSetMessage ()
{
	SetMessageDialog * di = new SetMessageDialog ("", "Set message for private store");
	if (di->exec () == QDialog::Accepted)
	{
		Data::sellWidget ()->setMotd (di->result ().toStdString ());
	}
	delete di;
}

string PrivateStoreManageList::packet ()
{
	string ret;
	if (Data::sellWidget ()->rowCount () > 1)
	{
		ret += DataFunc::intToString (packageCheckbox_->isChecked ());
		Data::sellWidget ()->setPackage (packageCheckbox_->isChecked ());
		return ret + Data::sellWidget ()->packet ();
	}
	else
	{
		ret += DataFunc::intToString (0);
		return ret + Data::sellWidget ()->packet ();
	}
}

PrivateStoreManageList::~PrivateStoreManageList ()
{
	delete okButton_;
	delete cancelButton_;
	delete messageButton_;
	delete buttonsLayout_;
	delete incomeLabel_;
	delete adenaLabel_;
	delete packageLabel_;
	delete packageCheckbox_;
	delete infoLayout_;
	delete pOwn_;
	delete la_;
}

/* old
  this->setAcceptDrops(true);		
	QTableWidget * wid = new QTableWidget (6, 6);
	QTableWidget * wid2 = new QTableWidget (6, 6);
	wid2->horizontalHeader ()->hide ();
	wid2->verticalHeader ()->hide ();
	wid->horizontalHeader ()->hide ();
	wid->verticalHeader ()->hide ();
	wid->setDragEnabled (true);
	wid2->setDragEnabled (true);
	wid->setMaximumHeight (130);
	wid->setMaximumWidth (215);
	wid2->setMaximumWidth (215);
	wid2->setMaximumHeight (65);
	for (int i = 0; i < 6; ++i)
	{
		wid->setColumnWidth (i, 32);
		wid->setRowHeight (i, 32);
		wid2->setColumnWidth (i, 32);
		wid2->setRowHeight (i, 32);
	}
	for (unsigned int i = 0; i < items.size (); ++i)
	{
		QImage im;
		QString fil = "images/items/";
		fil += Data::itemIcon (items[i].itemId).c_str ();
		fil += "00.png";
		im.load (fil);
		QLabel * label = new QLabel ();
		label->setPixmap (QPixmap::fromImage (im));
		QString toolTip;
		toolTip += Data::itemName (items[i].itemId).c_str ();
		if (Data::itemDesc (items[i].itemId).length () > 2)
		{
			toolTip += "\n\n";
			toolTip == Data::itemDesc (items[i].itemId).c_str ();
		}
		toolTip += "\n\nCount: ";
		toolTip += CatX::Convert (items[i].count).toString ().c_str ();
		toolTip += "\nDefault price: ";
		toolTip += CatX::Convert (items[i].price).toString ().c_str ();
		label->setToolTip (toolTip);
		wid->setCellWidget (0, static_cast <int> (i), label);
		QTableWidgetItem * wi = new QTableWidgetItem;
		wi->setData (0, Qt::DisplayRole, QRectF (
		wid->setItem (0, static_cast <int> (i), wi);
	}
	QVBoxLayout * la = new QVBoxLayout;
	QHBoxLayout * hla = new QHBoxLayout;
	QHBoxLayout * hla3 = new QHBoxLayout;
	QVBoxLayout * vla2 = new QVBoxLayout;
	QHBoxLayout * hla4 = new QHBoxLayout;
	QHBoxLayout * hla5 = new QHBoxLayout;
	QLineEdit * leIncome = new QLineEdit ();
	leIncome->setReadOnly (true);
	leIncome->setMaximumWidth (60);
	hla4->addWidget (new QLabel ("Income"));
	hla4->addWidget (leIncome);
	QLineEdit * leAdena = new QLineEdit ();
	leAdena->setReadOnly (true);
	leAdena->setMaximumWidth (60);
	hla5->addWidget (new QLabel ("Adena"));
	hla5->addWidget (leAdena);
	QCheckBox * ch = new QCheckBox;
	hla3->addWidget (ch);
	hla3->addWidget (new QLabel ("Package"));
	QGridLayout * gla = new QGridLayout ();
	gla->addLayout (hla3, 0, 0);
	gla->addLayout (hla4, 0, 1);
	gla->addLayout (hla5, 1, 1);
	hla->addWidget (new QPushButton ("v"));
	hla->addWidget (new QPushButton ("^"));
	QLabel * sell = new QLabel ("Sell");
	la->addWidget (sell);
	la->addWidget (wid);
	la->addLayout (hla);
	la->addWidget (wid2);
	la->addLayout (gla);
	QHBoxLayout * downKeysLayout = new QHBoxLayout;
	downKeysLayout->addWidget (new QPushButton ("Cancel"));
	downKeysLayout->addWidget (new QPushButton ("Message"));
	downKeysLayout->addWidget (new QPushButton ("Sell"));
	la->addLayout (downKeysLayout);
	this->setLayout (la);
	this->setMinimumWidth (240);
	this->setMaximumWidth (240);
	this->move (500, 300);
*/
