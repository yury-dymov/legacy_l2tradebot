#include "systemmessagewidget.h"

SystemMessageWidget::SystemMessageWidget ()
{
	this->setReadOnly (true);
	this->setMaximumHeight (50);
	this->show ();
}

void SystemMessageWidget::addSystemMessage (const string & msg)
{
	this->append (msg.c_str ());
}

void SystemMessageWidget::slotEnterWorld (bool)
{
	this->clear ();
}

