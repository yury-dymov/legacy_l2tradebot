#include "errordialog.h"

ErrorDialog::ErrorDialog (const char * msg)
{
	msg_ = new QLabel (msg);
	okButton_ = new QPushButton ("Ok");
	connect (okButton_, SIGNAL (pressed ()), SLOT (accept ()));
	vla_ = new QVBoxLayout;
	vla_->addWidget (msg_);
	vla_->addWidget (okButton_);
	this->setLayout (vla_);
	this->setWindowTitle ("Error");
	this->move (450, 300);
	this->show ();
	this->setFixedSize (200, 80);
}

ErrorDialog::~ErrorDialog ()
{
	delete msg_;
	delete okButton_;
	delete vla_;
}
