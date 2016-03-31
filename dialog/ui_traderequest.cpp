#include "trade.h"

TradeRequest::TradeRequest (const string & name)
{
	okButton_ = new QPushButton ("Ok");
	timer_ = new QTimer;
	progress_ = new QProgressBar;
	connect (timer_, SIGNAL (timeout ()), SLOT (slotTimeout ()));
	timer_->start (100);
	connect (okButton_, SIGNAL (pressed ()), SLOT (accept ()));
	cancelButton_ = new QPushButton ("Cancel");
	connect (cancelButton_, SIGNAL (pressed ()), SLOT (reject ()));
	buttonsLayout_ = new QHBoxLayout;
	buttonsLayout_->addWidget (okButton_);
	buttonsLayout_->addWidget (cancelButton_);
	motd_ = new QLabel ("Would you like to trade with <b>" + QString (name.c_str ()) + "</b>?");
	mainLayout_ = new QVBoxLayout;
	mainLayout_->addWidget (motd_);
	mainLayout_->addWidget (progress_);
	mainLayout_->addLayout (buttonsLayout_);
	this->setLayout (mainLayout_);
	this->resize (200, 100);
	this->setFixedSize (200, 100);
	this->move (400, 300);
	this->setWindowTitle ("Trade Request");
}

TradeRequest::~TradeRequest ()
{
	delete okButton_;
	delete cancelButton_;
	delete motd_;
	delete buttonsLayout_;
	delete mainLayout_;
}

void TradeRequest::slotTimeout ()
{
	progress_->setValue (progress_->value () + 1);
	if (progress_->value () == 100)
	{
		QDialog::reject ();
	}
}
