#include "setmessagedialog.h"

SetMessageDialog::SetMessageDialog (const QString & def, const QString & motd)
{
	okButton_ = new QPushButton ("Ok");
	connect (okButton_, SIGNAL (pressed ()), SLOT (accept ()));
	cancelButton_ = new QPushButton ("Cancel");
	connect (cancelButton_, SIGNAL (pressed ()), SLOT (reject ()));
	buttonsLayout_ = new QHBoxLayout;
	buttonsLayout_->addWidget (okButton_);
	buttonsLayout_->addWidget (cancelButton_);
	motd_ = new QLabel (motd);
	input_ = new QLineEdit;
	input_->setText (def);
	input_->setMaxLength (MESSAGE_MAX_LENGTH);
	connect (input_, SIGNAL (returnPressed ()), SLOT (accept ()));
	mainLayout_ = new QVBoxLayout;
	mainLayout_->addWidget (motd_);
	mainLayout_->addWidget (input_);
	mainLayout_->addLayout (buttonsLayout_);
	this->setModal (true);
	this->setWindowTitle ("Set Message");
	this->setLayout (mainLayout_);
	this->resize (300, 100);
	this->move (400, 400);
	this->show ();
}

SetMessageDialog::~SetMessageDialog ()
{
	delete motd_;
	delete input_;
	delete okButton_;
	delete cancelButton_;
	delete buttonsLayout_;
	delete mainLayout_;
}

QString SetMessageDialog::result () const
{
	return input_->text ();
}
