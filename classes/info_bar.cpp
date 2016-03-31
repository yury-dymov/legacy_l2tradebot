#include "info_bar.h"

InfoBar::InfoBar ()
{
	this->setHeaderLabel ("Objects");
	this->setMinimumWidth (240);
	QStringList list;
	this->addTopLevelItem (new QTreeWidgetItem (QStringList ("NPC")));
	this->addTopLevelItem (new QTreeWidgetItem (QStringList ("Players")));
	this->addTopLevelItem (new QTreeWidgetItem (QStringList ("Sell")));
	this->addTopLevelItem (new QTreeWidgetItem (QStringList ("Buy")));
	this->addTopLevelItem (new QTreeWidgetItem (QStringList ("Craft")));
	connect (this, SIGNAL (currentItemChanged (QTreeWidgetItem *, QTreeWidgetItem *)), SLOT (slotCurrentItemChanged (QTreeWidgetItem *, QTreeWidgetItem *)));
 	connect (this, SIGNAL (itemActivated (QTreeWidgetItem *, int)), SLOT (slotItemActivated (QTreeWidgetItem*, int)));
}

InfoBar::~InfoBar ()
{
}

void InfoBar::slotAddItem (const int objectId, const int stereotype, const string & str)
{
	QTreeWidgetItem * child = new QTreeWidgetItem (QStringList (str.c_str ()));
	this->topLevelItem (stereotype)->addChild (child);
	objectId_ [child] = objectId;
	for (unsigned int i = 0; i < data_ [objectId].size (); ++i)
	{
		if (data_ [objectId][i].stereotype == stereotype)
		{
			data_ [objectId][i].item = child;
			update ();
			return;
		}
	}
	Object_s elem;
	elem.item = child;
	elem.stereotype = stereotype;
	data_[objectId].push_back (elem);
	update ();
}

void InfoBar::slotDeleteItem (const int objectId, const int stereotype)
{
	vector <Object_s> data = data_ [objectId];
	for (unsigned int i = 0; i < data.size (); ++i)
	{
		if (data[i].stereotype == stereotype)
		{
			QTreeWidgetItem * child = data[i].item;
			this->topLevelItem (data[i].stereotype)->removeChild (child);
			update ();
			break;
		}
	}
}

void InfoBar::slotItemActivated (QTreeWidgetItem * item, int)
{
	if (this->indexOfTopLevelItem (item) == -1)
	{
		emit signalInfoBarSelected (objectId_ [item], 2);
	}
}

void InfoBar::slotCurrentItemChanged (QTreeWidgetItem * now, QTreeWidgetItem *)
{
	if (this->indexOfTopLevelItem (now) == -1)
	{
		emit signalInfoBarSelected (objectId_ [now], 1);
	}
}

void InfoBar::slotEnterWorld (bool)
{
	this->clear ();
	this->addTopLevelItem (new QTreeWidgetItem (QStringList ("NPC")));
	this->addTopLevelItem (new QTreeWidgetItem (QStringList ("Players")));
	this->addTopLevelItem (new QTreeWidgetItem (QStringList ("Sell")));
	this->addTopLevelItem (new QTreeWidgetItem (QStringList ("Buy")));
	this->addTopLevelItem (new QTreeWidgetItem (QStringList ("Craft")));
}
