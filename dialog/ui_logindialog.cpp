#include "logindialog.h"

LoginDialog::LoginDialog ()
{
	okButton_ = new QPushButton ("Login");
	connect (okButton_, SIGNAL (pressed ()), SLOT (accept ()));
	cancelButton_ = new QPushButton ("Cancel");
	connect (cancelButton_, SIGNAL (pressed ()), SLOT (reject ()));
	accountLabel_ = new QLabel ("Account");
	passwordLabel_ = new QLabel ("Password");
	accountEdit_ = new QLineEdit;
	passwordEdit_ = new QLineEdit;
	passwordEdit_->setEchoMode (QLineEdit::Password);
	layout_ = new QGridLayout;
	layout_->addWidget (accountLabel_, 0, 0);
	layout_->addWidget (passwordLabel_, 1, 0);
	layout_->addWidget (accountEdit_, 0, 1);
	layout_->addWidget (passwordEdit_, 1, 1);
	layout_->addWidget (okButton_, 2, 0);
	layout_->addWidget (cancelButton_, 2, 1);
	this->setWindowTitle ("Login");
	this->move (500, 350);
	this->setFixedSize (230, 100);
	this->setLayout (layout_);
	this->show ();
}

LoginDialog::~LoginDialog ()
{
	delete okButton_;
	delete cancelButton_;
	delete accountLabel_;
	delete passwordLabel_;
	delete accountEdit_;
	delete passwordEdit_;
	delete layout_;
}

QString LoginDialog::account () const
{
	return accountEdit_->text ();
}

QString LoginDialog::password () const
{
	return passwordEdit_->text ();
}
