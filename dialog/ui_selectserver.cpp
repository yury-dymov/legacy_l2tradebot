#include "selectserver.h"

SelectServerDialog::SelectServerDialog (const vector <Server_s> & slist)
{
	selected_ = 0;
	serverList_ = new QTableWidget (0, 3);
	okButton_ = new QPushButton ("Ok");
	connect (okButton_, SIGNAL (pressed ()), SLOT (accept ()));
	cancelButton_ = new QPushButton ("Cancel");
	connect (cancelButton_, SIGNAL (pressed ()), SLOT (reject ()));
	buttonLayout_ = new QHBoxLayout;
	buttonLayout_->addWidget (okButton_);
	buttonLayout_->addWidget (cancelButton_);
	serverList_ = new QTableWidget (0, 3);
	serverList_->setColumnWidth (0, 30);
	serverList_->setColumnWidth (1, 200);
	serverList_->setColumnWidth (2, 60);
	QList <QString> labels;
	labels.push_back ("Id");
	labels.push_back ("Server");
	labels.push_back ("Status");
	serverList_->setHorizontalHeaderLabels (QStringList (labels));
	serverList_->verticalHeader ()->hide ();
	for (unsigned int i = 0; i < slist.size (); ++i)
	{
		addRow_ (slist[i].id, Data::serverName (slist[i].id), slist[i].online);
	}
	connect (serverList_, SIGNAL (cellClicked (int, int)), SLOT (slotCellClicked (int, int)));
	connect (serverList_, SIGNAL (cellDoubleClicked (int, int)), SLOT (slotCellDoubleClicked (int, int)));
	connect (serverList_, SIGNAL (currentCellChanged (int, int, int, int)), SLOT (slotCurrentCellChanged (int, int, int, int)));
	mainLayout_ = new QVBoxLayout;
	mainLayout_->addWidget (serverList_);
	mainLayout_->addLayout (buttonLayout_);
	this->setLayout (mainLayout_);
	this->setWindowTitle ("Select Server");
	this->resize (320, 200);
	this->move (400, 300);
	this->setFixedSize (320, 200);
	this->show ();
}

void SelectServerDialog::addRow_ (int id, const string & name, bool online)
{
	serverList_->setRowCount (serverList_->rowCount () + 1);
	QTableWidgetItem * wiId = new QTableWidgetItem;
	wiId->setFlags (Qt::ItemIsSelectable | Qt::ItemIsEnabled);
	wiId->setText (Convert (id).toString ().c_str ());
	serverList_->setItem (serverList_->rowCount () - 1, 0, wiId);		
	QTableWidgetItem * wiName = new QTableWidgetItem;
	wiName->setFlags (Qt::ItemIsSelectable | Qt::ItemIsEnabled);
	wiName->setText (name.c_str ());
	serverList_->setItem (serverList_->rowCount () - 1, 1, wiName);		
	QTableWidgetItem * wiOnline = new QTableWidgetItem;
	wiOnline->setFlags (Qt::ItemIsSelectable | Qt::ItemIsEnabled);
	if (online)
	{
		wiOnline->setText ("On");
	}
	else
	{
		wiOnline->setText ("Off");
	}
	serverList_->setItem (serverList_->rowCount () - 1, 2, wiOnline);
}

SelectServerDialog::~SelectServerDialog ()
{
	delete okButton_;
	delete cancelButton_;
	delete buttonLayout_;
	for (int i = 0; i < serverList_->rowCount (); ++i)
	{
		for (int j = 0; j < serverList_->columnCount (); ++j)
		{
			delete serverList_->item (i, j);
		}
	}
	delete serverList_;
	delete mainLayout_;
}

void SelectServerDialog::slotCellClicked (int row, int)
{
	selected_ = row;
	for (int i = 0; i < serverList_->columnCount (); ++i)
	{
		serverList_->item (row, i)->setSelected (true);
	}	
}

void SelectServerDialog::slotCellDoubleClicked (int row, int)
{
	selected_ = row;
	accept ();
}

void SelectServerDialog::slotCurrentCellChanged (int row, int, int, int)
{
	selected_ = row;
	for (int i = 0; i < serverList_->columnCount (); ++i)
	{
		serverList_->item (row, i)->setSelected (true);
	}
}

int SelectServerDialog::serverId () const
{
	return selected_;
}

