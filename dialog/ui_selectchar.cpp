#include "selectchar.h"

SelectCharDialog::SelectCharDialog (const vector <CharSelectItem> & data)
{
	count_ = data.size ();
	la_ = new QVBoxLayout;
	for (unsigned int i = 0; i < data.size (); ++i)
	{
		players_[i] = new QPushButton (QString (data[i].name.c_str ()) + QString (" - ") + Data::className (data[i].cls).c_str ());
		connect (players_ [i], SIGNAL (pressed ()), SLOT (slotPressed ()));
		la_->addWidget (players_ [i]);
	}
	cancel_ = new QPushButton ("Cancel");
	connect (cancel_, SIGNAL (pressed ()), SLOT (reject ()));
	create_ = 0;
	if (count_ == 7)
	{
		la_->addWidget (cancel_);
	}
	else
	{
		buttons_ = new QHBoxLayout;
		create_ = new QPushButton ("Create");
		connect (create_, SIGNAL (pressed ()), SLOT (slotPressed ()));
		buttons_->addWidget (create_);
		buttons_->addWidget (cancel_);
		la_->addLayout (buttons_);
	}
	this->setLayout (la_);
	this->setWindowTitle ("Select Char");
	this->resize (250,300);
	this->move (400, 200);
	this->show ();
}

SelectCharDialog::~SelectCharDialog ()
{
	for (unsigned int i = 0; i < count_; ++i)
	{
		delete players_ [i];
	}
	delete cancel_;
	if (create_)
	{
		delete buttons_;
		delete create_;
	}
	delete la_;
}

void SelectCharDialog::slotPressed ()
{
	if (sender () == create_)
	{
		selection_ = -1;
		accept ();
		return;
	}
	for (unsigned int i = 0; i < count_; ++i)
	{
		if (sender () == players_ [i])
		{
			selection_ = i;
			accept ();
			break;
		}
	}
}

int SelectCharDialog::selection () const
{
	return selection_;
}
