#include "bagdialog.h"

BagDialog::BagDialog (int objectId, int count, bool crystallize) : objectId_ (objectId), count_ (count)
{
	vla_ = new QVBoxLayout;
	useButton_ = new QPushButton ("Use");
	connect (useButton_, SIGNAL (pressed ()), SLOT (slotButtonPressed ()));
	deleteButton_ = new QPushButton ("Delete");
	connect (deleteButton_, SIGNAL (pressed ()), SLOT (slotButtonPressed ()));
	crystallizeButton_ = new QPushButton ("Crystallize");
	connect (crystallizeButton_, SIGNAL (pressed ()), SLOT (slotButtonPressed ()));
	crystallizeButton_->setEnabled (crystallize);
	cancelButton_ = new QPushButton ("Cancel");
	connect (cancelButton_, SIGNAL (pressed ()), SLOT (slotButtonPressed ()));
	vla_->addWidget (useButton_);
	vla_->addWidget (deleteButton_);
	vla_->addWidget (crystallizeButton_);
	vla_->addWidget (cancelButton_);
	this->setLayout (vla_);
	this->setFixedSize (200, 150);
	this->setWindowTitle ("Item Dialog");
	this->move (400, 300);
	this->show ();
}

BagDialog::~BagDialog ()
{
	delete useButton_;
	delete cancelButton_;
	delete crystallizeButton_;
	delete deleteButton_;
	delete vla_;
}

int BagDialog::count () const
{
	return count_;
}

int BagDialog::pushed () const
{
	return pushed_;
}

void BagDialog::slotButtonPressed ()
{
	if (sender () == useButton_)
	{
		pushed_ = 0;
		this->accept ();
	}
	else if (sender () == deleteButton_)
	{
		if (count_ > 1)
		{
			CountDialog * di = new CountDialog ("How many items would you like to delete?", count_);
			if (di->exec () == QDialog::Accepted)
			{
				pushed_ = 1;
				count_ = di->result ();
				delete di;
				this->accept ();
			}
			else
			{
				delete di;
			}
		}
		else
		{
			VistaDialog * di = new VistaDialog;
			if (di->exec () == QDialog::Accepted)
			{
				pushed_ = 1;
				delete di;
				this->accept ();
			}
			else
			{
				delete di;
			}
		}
	}
	else if (sender () == crystallizeButton_)
	{
		VistaDialog * di = new VistaDialog;
		if (di->exec () == QDialog::Accepted)
		{
			pushed_ = 2;
			delete di;
			this->accept ();
		}
		else
		{
			delete di;
		}
	}
	else if (sender () == cancelButton_)
	{
		this->reject ();
	}
}




