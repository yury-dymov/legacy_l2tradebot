#include "map.h"


Map::Map (QWidget * parent) : QGraphicsView (parent)
{
 //   setCacheMode(CacheBackground);
	//myScene_ = new MapScene;
	this->setMinimumWidth (400);
	this->setSceneRect (0, 0, 1024, 1024);
	this->setDragMode (QGraphicsView::NoDrag);
	this->scale (0.45, 0.45);
	scale_ = 0.45;
	this->setTransformationAnchor (QGraphicsView::AnchorViewCenter);
	myScene_ = new MapScene;
	connect (myScene_, SIGNAL (signalMap (const string &)), SLOT (slotMap (const string &)));
	connect (myScene_, SIGNAL (signalDeleteItem (const int, const int)), SLOT (slotDeleteItem (const int, const int)));
	connect (myScene_, SIGNAL (signalAddItem (const int, const int, const string &)), SLOT (slotAddItem (const int, const int, const string &)));
	connect (this, SIGNAL (signalCreateUser (const User &)), myScene_, SLOT (slotCreateUser (const User &)));
	connect (this, SIGNAL (signalCreateNpc (const Npc &)), myScene_, SLOT (slotCreateNpc (const Npc &)));
	connect (this, SIGNAL (signalCreateChar (const Char &)), myScene_, SLOT (slotCreateChar (const Char &)));
	connect (this, SIGNAL (signalDeleteObject (const int)), myScene_, SLOT (slotDeleteObject (const int)));
	connect (this, SIGNAL (signalInfoBarSelected (const int, const int)), myScene_, SLOT (slotInfoBarSelected (const int, const int)));	
	this->setScene (myScene_);
}

Map::~Map ()
{
	delete myScene_;
}

void Map::mousePressEvent (QMouseEvent * event)
{
	if (event->button () & Qt::RightButton)
	{
		this->setDragMode (QGraphicsView::ScrollHandDrag);
		MapScene::ignoreMouse = true;
		QGraphicsView::mousePressEvent (new QMouseEvent (event->type (), event->pos (), Qt::LeftButton, Qt::LeftButton, event->modifiers ()));
	}
	else
	{
		QGraphicsView::mousePressEvent (event);
	}
}

void Map::mouseReleaseEvent (QMouseEvent *)
{
	this->setDragMode (QGraphicsView::NoDrag);
	MapScene::ignoreMouse = false;
}

void Map::wheelEvent (QWheelEvent * event)
{
	if (event->delta () > 0)
	{
		scale_ *= 1.1;
		this->scale (1.1, 1.1);
		myScene_->setScale (myScene_->scale () * 1.1);
	}
	else
	{
		scale_ /= 1.1;
		this->scale (1/1.1, 1/1.1);
		myScene_->setScale (myScene_->scale () / 1.1);
	}
}

void Map::slotMap (const string & id)
{
	emit signalMap (id);
}

void Map::slotAddItem (const int p1, const int p2, const string & p3)
{
	emit signalAddItem (p1, p2, p3);
}

void Map::slotDeleteItem (const int p1, const int p2)
{
	emit signalDeleteItem (p1, p2);
}

void Map::slotCreateNpc (const Npc & p)
{
	emit signalCreateNpc (p);
}

void Map::slotCreateChar (const Char & p)
{
	emit signalCreateChar (p);
}

void Map::slotCreateUser (const User & p)
{
	emit signalCreateUser (p);
	this->centerOn (MapScene::user.mapItem ()->pos ());
	this->update ();
}

void Map::slotDeleteObject (const int p)
{
	emit signalDeleteObject (p);
}

void Map::slotInfoBarSelected (const int p, const int p2)
{
	emit signalInfoBarSelected (p, p2);
}

void Map::fullUpdate () const
{
	foreach (QGraphicsItem * item, myScene_->items ())
	{
		MapItem * it = qgraphicsitem_cast <MapItem *> (item);
		it->update ();
	}
}

void Map::enterWorld (bool enter)
{
	if (enter)
	{
		this->scale (1 / scale_, 1/ scale_);
		scale_ = 1;
	}
	else
	{
		this->scale (0.45 / scale_, 0.45 / scale_);
		myScene_->restart ();
		scale_ = 0.45;
	}
}
