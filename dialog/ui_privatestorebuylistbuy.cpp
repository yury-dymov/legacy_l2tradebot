#include "playerstore.h"

PlayerStoreListBuy::PlayerStoreListBuy (const int adena, const vector <PlayerBuyItem> & items) : adena_ (adena)
{
	pOwn_ = new PlayerBuyWidget (0, 3, adena_);
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
		addMe.push_back (items[i].objectId);
		addMe.push_back (items[i].itemId);
		addMe.push_back (items[i].enchant);
		addMe.push_back (items[i].count);
		addMe.push_back (items[i].refPrice);
		addMe.push_back (items[i].h1);
		addMe.push_back (items[i].bodyPart);
		addMe.push_back (items[i].type2);
		addMe.push_back (items[i].buyersPrice);
		addMe.push_back (items[i].playerCount);
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
	la_->addWidget (new QLabel (tr ("Private Store: Buy")));
	la_->addWidget (pOwn_);
	la_->addWidget (new QLabel (tr ("Sell List")));
	pShow_ = new PlayerBuyWidget (0, 3, -1);
	connect (pShow_, SIGNAL (signalDeselect ()), pOwn_, SLOT (slotDeselect ()));
	connect (pOwn_, SIGNAL (signalDeselect ()), pShow_, SLOT (slotDeselect ()));
	connect (pShow_, SIGNAL (signalAddItem (const QString &, const vector <int> &)), pOwn_, SLOT (slotAddRow (const QString &, const vector <int> &)));
	connect (pOwn_, SIGNAL (signalAddItem (const QString &, const vector <int> &)), pShow_, SLOT (slotAddRow (const QString &, const vector <int> &)));
	connect (pShow_, SIGNAL (signalChangeIncome ()), SLOT (slotChangeIncome ()));
	pShow_->setHorizontalHeaderLabels (QStringList (labels));
	pShow_->verticalHeader ()->hide ();
	pShow_->setColumnWidth (0, 230);
	pShow_->setMaximumHeight (150);
	adenaLabel_ = new QLabel ("Adena: " + QString (DataFunc::number (adena_).c_str ()));
	incomeLabel_ = new QLabel;
	slotChangeIncome ();
	la_->addWidget (pShow_);
	infoLayout_ = new QHBoxLayout;
	infoLayout_->addSpacing (200);
	infoLayout_->addWidget (incomeLabel_);
	infoLayout_->addWidget (adenaLabel_);
	buttonsLayout_ = new QHBoxLayout;
	okButton_ = new QPushButton ("Ok");
	connect (okButton_, SIGNAL (pressed ()), SLOT (accept ()));
	cancelButton_ = new QPushButton ("Cancel");
	connect (cancelButton_, SIGNAL (pressed ()), SLOT (reject ()));
	buttonsLayout_->addWidget (okButton_);
	buttonsLayout_->addWidget (cancelButton_);
	la_->addLayout (infoLayout_);
	la_->addLayout (buttonsLayout_);
	this->setLayout (la_);
	this->setWindowTitle (tr ("Private Store: Buy"));
	this->setMinimumWidth (478);
	this->setFixedSize (478, 500);
	this->move (400, 200);
}

void PlayerStoreListBuy::slotChangeIncome ()
{
	incomeLabel_->setText ("Price: " + QString (DataFunc::number (pShow_->income ()).c_str ()));
	pOwn_->setIncome (pShow_->income ());
}

string PlayerStoreListBuy::packet ()
{
	return pShow_->packet ();
}

PlayerStoreListBuy::~PlayerStoreListBuy ()
{
	delete okButton_;
	delete cancelButton_;
	delete buttonsLayout_;
	delete incomeLabel_;
	delete adenaLabel_;
	delete infoLayout_;
	delete pShow_;
	delete pOwn_;
	delete la_;
}
