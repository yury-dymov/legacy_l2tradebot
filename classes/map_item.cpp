#include "map_item.h"

bool MapItem::npcShow_ = true;
bool MapItem::charShow_ = true;
bool MapItem::sellShow_ = true;
bool MapItem::buyShow_ = true;
bool MapItem::craftShow_ = true;


MapItem::MapItem (int stereotype, int objectId, QGraphicsItem * parent) : QGraphicsItem (parent), show_ (false), stereotype_ (stereotype), active_ (false), objectId_ (objectId)
{
	this->setCacheMode (DeviceCoordinateCache);
	this->setZValue (1);
}

void MapItem::setName (const QString & name)
{
	this->name_ = name;
	this->setToolTip (name);
}

void MapItem::setAlt (const QString & alt)
{
	if (alt.length ())
	{
		this->setToolTip (name_ + "\n" + alt);
	}
	else
	{
		this->setToolTip (name_);
	}
}

QRectF MapItem::boundingRect () const
{
	qreal ad = 2;
	return QRectF (-3 -ad, -3 -ad, 3 + ad, 3 + ad);
}

void MapItem::paint (QPainter * painter, const QStyleOptionGraphicsItem *, QWidget *)
{
	painter->setPen (Qt::NoPen);
	if (active_ && stereotype_ != E_USER)
	{
		painter->setBrush (Qt::red);
	}
	else
	{
		if (stereotype_ == E_NPC)
		{
			painter->setBrush (Qt::blue);
		}
		else if (stereotype_ == E_CHAR)
		{
			painter->setBrush (Qt::white);
		}
		else if (stereotype_ == E_USER)
		{
			painter->setBrush (Qt::green);
		}
		else if (stereotype_ == E_SELL)
		{
			painter->setBrush (Qt::darkMagenta);
		}
		else if (stereotype_ == E_BUY)
		{
			painter->setBrush (Qt::yellow);
		}
		else if (stereotype_ == E_CRAFT)
		{
			painter->setBrush (QColor (0xff, 0xa5, 0x00));
		}
	}
	if (isVisible_ ())
	{
		painter->drawEllipse (-5, -5, 5, 5);
	}
}

bool MapItem::isShow () const
{
	return show_;
}

void MapItem::mousePressEvent (QGraphicsSceneMouseEvent * event)
{
	if (isVisible_ ())
	{
		setActive (true);
		if (event->button () & Qt::LeftButton)
		{
			update ();
			QGraphicsItem::mousePressEvent (event);
		}
	}
}

void MapItem::mouseReleaseEvent (QGraphicsSceneMouseEvent * event)
{
	update ();
	QGraphicsItem::mouseReleaseEvent (event);
}

void MapItem::mouseDoubleClickEvent (QGraphicsSceneMouseEvent * event)
{
	update ();
	QGraphicsItem::mouseDoubleClickEvent (event);
}

void MapItem::setShow (bool show)
{
	this->show_ = show;
}

bool MapItem::isActive () const
{
	return active_;
}

void MapItem::setActive (const bool val)
{
	if (active_ != val)
	{
		this->active_ = val;
		update ();
	}
}

int MapItem::objectId () const
{
	return objectId_;
}

void MapItem::setStereotype (int val)
{
	if (val == 0 || val == 2 || val == 4)
	{
		stereotype_ = E_CHAR;
	}
	else if (val == 1 || val == 8)
	{
		stereotype_ = E_SELL;
	}
	else if (val == 3)
	{
		stereotype_ = E_BUY;
	}
	else if (val == 5)
	{
		stereotype_ = E_CRAFT;
	}
	update ();
}

int MapItem::stereotype () const
{
	return stereotype_;
}

void MapItem::setView (int stereotype, bool val)
{
	if (stereotype == E_NPC)
	{
		npcShow_ = val;
	}
	else if (stereotype == E_CHAR)
	{
		charShow_ = val;
	}
	else if (stereotype == E_SELL)
	{
		sellShow_ = val;
	}
	else if (stereotype == E_BUY)
	{
		buyShow_ = val;
	}
	else if (stereotype == E_CRAFT)
	{
		craftShow_ = val;
	}
}

bool MapItem::isVisible_ () const
{
	if (show_)
	{
		if (stereotype_ == E_NPC || stereotype_ == E_CHAR || stereotype_ == E_BUY || stereotype_ == E_SELL || stereotype_ == E_CRAFT)
		{
			if ((stereotype_ == E_NPC && npcShow_) ||
				(stereotype_ == E_SELL && sellShow_) ||
				(stereotype_ == E_BUY && buyShow_) ||
				(stereotype_ == E_CHAR && charShow_) ||
				(stereotype_ == E_CRAFT && craftShow_))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return true;
		}
	}
	else
	{
		return false;
	}
}
