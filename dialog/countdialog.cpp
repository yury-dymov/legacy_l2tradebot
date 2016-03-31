#include "countdialog.h"

CountDialog::CountDialog (const QString & text, int max) : max_ (max)
{
	this->setModal (true);
	for (int i = 0; i < 10; ++i)
	{
		digits_ [i] = new QPushButton (Convert (i).toString ().c_str ());
		connect (digits_ [i], SIGNAL (pressed ()), SLOT (slotDigitPressed_ ()));
		digits_[i] ->setMaximumWidth (20);
	}
	okButton_ = new QPushButton ("Ok");
	connect (okButton_, SIGNAL (pressed ()), SLOT (accept ()));
	cancelButton_ = new QPushButton (tr ("Cancel"));
	connect (cancelButton_, SIGNAL (pressed ()), SLOT (reject ()));
	allButton_ = new QPushButton ("Max");
	connect (allButton_, SIGNAL (pressed ()), SLOT (slotMax_ ()));
	allButton_->setMaximumWidth (50);
	lineEdit_ = new QLineEdit ("0");
	digits_[0]->setMaximumWidth (50);	
	connect (lineEdit_, SIGNAL (textChanged (const QString &)), SLOT (slotTextChanged_ (const QString &)));
	la_ = new QGridLayout;
	for (int j = 0; j < 3; ++j)
	{
		for (int i = 0; i < 3; ++i)
		{
			la_->addWidget (digits_[j * 3 + i + 1], i, j);
		}
	}
	la_->addWidget (allButton_, 3, 0, 1, 2);
	la_->addWidget (digits_[0], 3, 2, 1, 2);
	clearButton_ = new QPushButton ("C");
	clearButton_->setMaximumWidth (20);
	connect (clearButton_, SIGNAL (pressed ()), SLOT (slotClear_ ()));
	delButton_ = new QPushButton ("<");
	delButton_->setMaximumWidth (20);
	delButton_->setMinimumHeight (60);
	connect (delButton_, SIGNAL (pressed ()), SLOT (slotDel_ ()));
	la_->addWidget (delButton_, 0, 3, 2, 1);
	la_->addWidget (clearButton_, 2, 3);
	hlaMain_ = new QHBoxLayout;
	buttons_ = new QHBoxLayout;
	buttons_->addWidget (okButton_);
	buttons_->addWidget (cancelButton_);
	leftLayout_ = new QVBoxLayout;
	motd_ = new QLabel (text);
	leftLayout_->addWidget (motd_);
	leftLayout_->addWidget (lineEdit_);
	leftLayout_->addLayout (buttons_);
	hlaMain_->addLayout (leftLayout_);
	hlaMain_->addLayout (la_);
	this->setLayout (hlaMain_);
	this->setWindowTitle (tr ("Select amount"));
	this->resize (500, 140);
	this->move (300, 200);
	this->show ();
}

CountDialog::~CountDialog ()
{
	for (int i = 0; i < 10; ++i)
	{
		delete digits_ [i];
	}
	delete okButton_;
	delete cancelButton_;
	delete allButton_;
	delete delButton_;
	delete clearButton_;
	delete motd_;
	delete buttons_;
	delete leftLayout_;
	delete la_;
	delete hlaMain_;
}

void CountDialog::slotTextChanged_ (const QString & str)
{
	QString process;
	for (int i = 0; i < str.length (); ++i)
	{
		if (!i && str[i] == '0')
		{
			while (str[i] == '0' && i < str.length ())
			{
				++i;
			}
			--i;
			continue;
		}
		if (str[i] >= '0' && str[i] <= '9')
		{
			process += str[i];
		}
	}
	if (!process.length ())
	{
		process += '0';
	}
	if (max_ && process.length () && Convert (process.toStdString ()).toInt () > max_)
	{
		process = Convert (max_).toString ().c_str ();
	}
	lineEdit_->setText (DataFunc::number (Convert (process.toStdString ()).toInt ()).c_str ());
}

void CountDialog::slotDigitPressed_ ()
{
	lineEdit_->setText (lineEdit_->text () + dynamic_cast <QPushButton *> (sender ())->text ());
}

void CountDialog::slotMax_ ()
{
	lineEdit_->setText (Convert (max_).toString ().c_str ());
}

void CountDialog::slotClear_ ()
{
	lineEdit_->setText ("");
}

void CountDialog::slotDel_ ()
{
	QString text = lineEdit_->text ();
	text.truncate (text.length () - 1);
	lineEdit_->setText (text);
}

int CountDialog::result () const
{
	QString ret;
	QString str = lineEdit_->text ();
	for (int i = 0; i < str.length (); ++i)
	{
		if (str[i] != ',')
		{
			ret += str[i];
		}
	}
	return ret.toInt ();
}

