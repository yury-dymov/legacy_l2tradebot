#include "dwarfenmanufacture.h"

DwarfenManufacture::DwarfenManufacture (const vector <DwarfenManufactureItem> & recipe, const vector <DwarfenManufactureItem> & trade)
{
	upLabel_ = new QLabel ("Recipe List");
	downLabel_ = new QLabel ("Sell List");
	okButton_ = new QPushButton ("Ok");
	connect (okButton_, SIGNAL (pressed ()), SLOT (accept ()));
	cancelButton_ = new QPushButton ("Cancel");
	connect (cancelButton_, SIGNAL (pressed ()), SLOT (reject ()));
	messageButton_ = new QPushButton ("Message");
	connect (messageButton_, SIGNAL (pressed ()), SLOT (slotMessage ()));
	buttonsLayout_ = new QHBoxLayout ();
	buttonsLayout_->addWidget (okButton_);
	buttonsLayout_->addWidget (messageButton_);
	buttonsLayout_->addWidget (cancelButton_);
	upWidget_ = new DwarfenManufactureWidgetUp (0, 1);
	for (unsigned int i = 0; i < recipe.size (); ++i)
	{
		upWidget_->addItem (Data::recipeName (recipe[i].recipeId).c_str (), recipe[i].recipeId);
	}
	downWidget_ = new DwarfenManufactureWidgetDown (0, 2);
	for (unsigned int i = 0; i < trade.size (); ++i)
	{
		downWidget_->addItem (Data::recipeName (trade[i].recipeId).c_str (), trade[i].recipeId, trade[i].price);
	}
	connect (upWidget_, SIGNAL (signalAddItem (const QString &, const int, const int)), downWidget_, SLOT (addItem (const QString &, const int, const int)));
	QList <QString> labels;
	labels.push_back ("Recipe");
	upWidget_->setHorizontalHeaderLabels (QStringList (labels));
	upWidget_->verticalHeader ()->hide ();
	labels.push_back ("Price");
	downWidget_->setHorizontalHeaderLabels (QStringList (labels));
	downWidget_->verticalHeader ()->hide ();
	upWidget_->setColumnWidth (0, 430);
	upWidget_->setMaximumHeight (150);
	upWidget_->setMinimumHeight (150);
	downWidget_->setColumnWidth (0, 230);
	downWidget_->setColumnWidth (1, 200);
	downWidget_->setMinimumHeight (150);
	downWidget_->setMaximumHeight (150);
	mainLayout_ = new QVBoxLayout ();
	mainLayout_->addWidget (upLabel_);
	mainLayout_->addWidget (upWidget_);
	mainLayout_->addWidget (downLabel_);
	mainLayout_->addWidget (downWidget_);
	mainLayout_->addLayout (buttonsLayout_);
	this->setLayout (mainLayout_);
	this->setWindowTitle (tr ("Npc Store"));
	this->setMinimumWidth (478);
	this->move (400, 200);
	this->show ();
}

DwarfenManufacture::~DwarfenManufacture ()
{
	delete upLabel_;
	delete downLabel_;
	delete okButton_;
	delete messageButton_;
	delete cancelButton_;
	delete upWidget_;
	delete downWidget_;
	delete buttonsLayout_;
	delete mainLayout_;
}

void DwarfenManufacture::slotMessage ()
{
	SetMessageDialog * di = new SetMessageDialog ("", "Set message");
	if (di->exec () == QDialog::Accepted)
	{
		message_ = di->result ().toStdString ();
	}
	delete di;
}

string DwarfenManufacture::packet ()
{
	return downWidget_->packet ();
}

string DwarfenManufacture::message () const
{
	return message_;
}

