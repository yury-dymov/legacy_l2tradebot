#include "vistadialog.h"

VistaDialog::VistaDialog ()
{
	okButton_ = new QPushButton ("Ok");
	connect (okButton_, SIGNAL (pressed ()), SLOT (accept ()));
	cancelButton_ = new QPushButton ("Cancel");
	connect (cancelButton_, SIGNAL (pressed ()), SLOT (reject ()));
	vistaLabel_ = new QLabel ("Are you sure?");
	buttonLayout_ = new QHBoxLayout;
	buttonLayout_->addWidget (okButton_);
	buttonLayout_->addWidget (cancelButton_);
	vla_ = new QVBoxLayout;
	vla_->addWidget (vistaLabel_);
	vla_->addLayout (buttonLayout_);
	this->setWindowTitle ("Action Confirmation");
	this->setModal (true);
	this->setFixedSize (200, 100);
	this->move (400, 300);
	this->setLayout (vla_);
	this->show ();
}

VistaDialog::~VistaDialog ()
{
	delete okButton_;
	delete cancelButton_;
	delete buttonLayout_;
	delete vistaLabel_;
	delete vla_;
}
