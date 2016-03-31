#include "map_scene.h"

int MapScene::waitType_ = 1;
vector <Npc> MapScene::vNpc;
User MapScene::user;
vector <Char> MapScene::vChar;
int MapScene::x0_;
int MapScene::y0_;
QImage MapScene::map_;
vector <Maps> MapScene::maps_;

bool	MapScene::ignoreMouse = false;

MapScene::MapScene (QObject * parent) : QGraphicsScene (parent)
{	
	scale_ = 1;
	maps_.clear ();
	Maps elem;
	elem.x0 = 640;
	elem.y0 = 9155;
	elem.file = "images/maps/map_dark_elven_village.jpg";
	maps_.push_back (elem);
	elem.x0 = -20000;
	elem.y0 = 117379;
	elem.file = "images/maps/map_gludio_castle_town.jpg";
	maps_.push_back (elem);
	elem.x0 = -89366;
	elem.y0 = 145715;
	elem.file = "images/maps/map_gludin_village.jpg";
	maps_.push_back (elem);
	elem.x0 = -90610;
	elem.y0 = 236402;
	elem.file = "images/maps/map_talkin_island_village.jpg";
	maps_.push_back (elem);
	elem.x0 = 110062;
	elem.y0 = -188040;
	elem.file = "images/maps/map_dwarven_village.jpg";
	maps_.push_back (elem);
	elem.x0 = -90000;
	elem.y0 = 235000;
	elem.file = "images/maps/map_talkin_island_village.jpg";
	maps_.push_back (elem);
	elem.x0 = 39158;
	elem.y0 = 42612;
	elem.file = "images/maps/map_elven_village.jpg";
	maps_.push_back (elem);
	elem.x0 = -52778;
	elem.y0 = -120862;
	elem.file = "images/maps/map_orc_village.jpg";
	maps_.push_back (elem);
	elem.x0 = 11766;
	elem.y0 = 138416;
	elem.file = "images/maps/map_dion_castle_town.jpg";
	maps_.push_back (elem);
	elem.x0 = 73556;
	elem.y0 = 139961;
	elem.file = "images/maps/map_giran_castle_town.jpg";
	maps_.push_back (elem);
	elem.x0 = 75063;
	elem.y0 = 48668;
	elem.file = "images/maps/map_town_of_oren.jpg";
	maps_.push_back (elem);
	elem.x0 = 139300;
	elem.y0 = 16296;
	elem.file = "images/maps/map_town_of_aden.jpg";
	maps_.push_back (elem);
	elem.x0 = 140240;
	elem.y0 = -64308;
	elem.file = "images/maps/map_godard_castle_town.jpg";
	maps_.push_back (elem);
	elem.x0 = 29713;
	elem.y0 = -55800;
	elem.file = "images/maps/map_rune_village.jpg";
	maps_.push_back (elem);
	elem.x0 = 77312;
	elem.y0 = -147500;
	elem.file = "images/maps/map_town_of_schuttgart.jpg";
	maps_.push_back (elem);
	elem.x0 = 101483;
	elem.y0 = 212606;
	elem.file = "images/maps/map_heine.jpg";
	maps_.push_back (elem);
	elem.x0 = 111063;
	elem.y0 = 69980;
	elem.file = "images/maps/map_hunters_village.jpg";
	maps_.push_back (elem);
	map_.load ("images/intro.jpg");
	startTimer (1000 / TIME_UPDATE);
}

void MapScene::loadMap_ (const CatXPoint & pos)
{
	int x = static_cast <int> (pos.x ());
	int y = static_cast <int> (pos.y ());
	for (unsigned int i = 0; i < maps_.size (); ++i)
	{
		if ((x > maps_[i].x0) && (x < maps_[i].x0 + STEP * 1024) && (y > maps_[i].y0) && (y < maps_[i].y0 + STEP * 1024))
		{
			x0_ = maps_[i].x0;
			y0_ = maps_[i].y0;
			map_.load (maps_[i].file);
			return;
		}
	}
	map_.load ("images/intro.jpg");
}

void MapScene::drawBackground (QPainter * painter, const QRectF &)
{
	painter->drawPixmap (0, 0, QPixmap::fromImage (map_));
}

void MapScene::slotDeleteObject (const int id)
{
	vector <Char> vCharNew;
	vector <Npc> vNpcNew;
	for (unsigned int i = 0; i < vChar.size (); ++i)
	{
		if (vChar[i].objectId () != id)
		{
			vCharNew.push_back (vChar [i]);
		}
		else
		{
			vChar[i].deleteMapItem ();
			vChar[i].setMapItem (NULL);
			emit signalDeleteItem (id, E_INFO_PLAYER);
			emit signalDeleteItem (id, E_INFO_BUY);
			emit signalDeleteItem (id, E_INFO_SELL);
			emit signalDeleteItem (id, E_INFO_CRAFT);
		}
	}
	for (unsigned int i = 0; i < vNpc.size (); ++i)
	{
		if (vNpc[i].objectId () != id)
		{
			vNpcNew.push_back (vNpc [i]);
		}
		else
		{
			vNpc[i].deleteMapItem ();
			vNpc[i].setMapItem (NULL);
			emit signalDeleteItem (id, E_INFO_NPC);
		}
	}
	if (user.objectId () == id)
	{
		user.deleteMapItem ();
		user.setMapItem (NULL);
	}
	vNpc = vNpcNew;
	vChar = vCharNew;
}

void MapScene::moveToLocation (const int objectId, const CatXPoint & to, const CatXPoint & from)
{
	for (unsigned int i = 0; i < vChar.size (); ++i)
	{
		if (vChar[i].objectId () == objectId)
		{
			vChar[i].setPos (from);
			vChar[i].setNext (to);
			return;
		}
	}
	for (unsigned int i = 0; i < vNpc.size (); ++i)
	{
		if (vNpc[i].objectId () == objectId)
		{
			vNpc[i].setPos (from);
			vNpc[i].setNext (to);
			return;
		}
	}
	if (user.objectId () == objectId)
	{
		user.setPos (from);
		user.setNext (to);
	}
}

void MapScene::slotCreateUser (const User & myUser)
{
	if (user.mapItem () == NULL)
	{
		user.setMapItem (new MapItem (E_USER));
		user.setName (myUser.name ().c_str ());
		loadMap_ (myUser.pos ());
		this->setFocusItem (user.mapItem ());
	}
	// dirty hack
	MapItem * save = user.mapItem ();
	user = myUser;
	user.setMapItem (save);
}

void MapScene::slotCreateNpc (const Npc & npc)
{
	for (unsigned int i = 0; i < vNpc.size (); ++i)
	{
		if (vNpc[i].objectId () == npc.objectId ())
		{
			MapItem * save = vNpc[i].mapItem ();
			vNpc[i] = npc;
			vNpc[i].setMapItem (save);
			return;
		}
	}
	vNpc.push_back (npc);
	emit signalAddItem (npc.objectId (), E_INFO_NPC, Data::npcName (npc.npcId ()));
	vNpc[vNpc.size () - 1].setMapItem (new MapItem (E_NPC, npc.objectId ()));
	vNpc[vNpc.size () - 1].mapItem ()->setName (Data::npcName (npc.npcId ()).c_str ());
}

void MapScene::slotCreateChar (const Char & ch)
{
	for (unsigned int i = 0; i < vChar.size (); ++i)
	{
		if (vChar[i].objectId () == ch.objectId ())
		{
			MapItem * save = vChar[i].mapItem ();
			save->setStereotype (ch.shop ());
			vChar[i] = ch;
			vChar[i].setMapItem (save);
			return;
		}
	}
	vChar.push_back (ch);
	emit signalAddItem (ch.objectId (), E_INFO_PLAYER, ch.name ());
	vChar[vChar.size () - 1].setMapItem (new MapItem (E_CHAR, ch.objectId ()));
	vChar[vChar.size () - 1].mapItem ()->setStereotype (vChar[vChar.size () - 1].shop ());
	vChar[vChar.size () - 1].mapItem ()->setName (ch.name ().c_str ());
}

QPointF MapScene::l2ToWindowCoordinate_ (const int x, const int y)
{
	QPointF ret;
	ret.setX ((x - x0_) / STEP);
	ret.setY ((y - y0_) / STEP);
	return ret;
}

void MapScene::timerEvent (QTimerEvent *)
{
	bool upd = false;
	for (unsigned int i = 0; i < vNpc.size (); ++i)
	{
		upd = max (init_ (&vNpc[i]), upd);
		upd = max (move_ (&vNpc[i]), upd);
	}
	for (unsigned int i = 0; i < vChar.size (); ++i)
	{
		upd = max (init_ (&vChar[i]), upd);
		upd = max (move_ (&vChar[i]), upd);
	}
	if (user.mapItem ())
	{
		upd = max (init_ (&user), upd);
		upd = max (move_ (&user), upd);
	}
	if (upd)
	{
		this->update ();
	}
}

template <class T> bool MapScene::move_ (T * el)
{
	if ((abs (static_cast <int> (el->next ().x ())) > 1 || abs (static_cast <int> (el->next ().y ())) > 1) && (el->pos ().x () != el->next ().x () || el->pos ().y () != el->next ().y ()))
	{
		double hipo = sqrt ((el->pos ().x () - el->next ().x ()) * (el->pos ().x () - el->next ().x ()) + (el->pos ().y () - el->next ().y ()) * (el->pos ().y () - el->next ().y ()));
		if (hipo > 1)
		{
			double dSpeed;
			if (el->isRun ())
			{
				dSpeed = el->speed () / TIME_UPDATE;
			}
			else
			{
				dSpeed = el->walkSpeed () / TIME_UPDATE;
			}
			dSpeed *= 1.2; /* why??? */
			if (hipo <= dSpeed)
			{
				el->setPos (CatXPoint (el->next ().x (), el->next ().y (), el->pos ().z ()));
			}
			else
			{
				el->setPos (CatXPoint (el->pos ().x () + dSpeed * (el->next ().x () - el->pos ().x ()) / hipo, el->pos ().y () + dSpeed * (el->next ().y () - el->pos ().y ()) / hipo, el->pos ().z ()));
			}
			el->mapItem ()->setPos (l2ToWindowCoordinate_ (static_cast <int> (el->pos ().x ()), static_cast <int> (el->pos ().y ())));
			return true;
		}
	}
	return false;
}

template <class T> bool MapScene::init_ (T * el)
{
		if (el->pos ().x () && el->pos ().y () && !el->mapItem ()->isShow ())
		{
			el->mapItem ()->setShow (true);
			this->addItem (el->mapItem ());
			el->mapItem ()->setPos (l2ToWindowCoordinate_ (static_cast <int> (el->pos ().x ()), static_cast <int> (el->pos ().y ())));
			return true;
		}
		else
		{
			return false;
		}
}

void MapScene::mousePressEvent (QGraphicsSceneMouseEvent * mouseEvent)
{
	foreach (QGraphicsItem * item, this->items ())
	{
		MapItem * it = qgraphicsitem_cast <MapItem *> (item);
		it->setActive (false);
	}
	QGraphicsScene::mousePressEvent (mouseEvent);
	foreach (QGraphicsItem * item, this->items ())
	{
		MapItem * it = qgraphicsitem_cast <MapItem *> (item);
		if (it->isActive ())
		{
			return;
		}
	}
	if (!ignoreMouse)
	{
		if (mouseEvent->button () & Qt::LeftButton)
		{
			if (GameThread::enterWorld ())
			{
				if (waitType_)
				{
					user.setNext (CatXPoint (mouseEvent->scenePos ().x () * STEP + x0_, mouseEvent->scenePos ().y () * STEP + y0_, user.pos ().z ()));
					emit signalMap (GamePacket::moveBackwardToLocation (user.next (), user.pos ()));
				}
			}
		}
	}
}

void MapScene::mouseDoubleClickEvent (QGraphicsSceneMouseEvent * mouseEvent)
{
	foreach (QGraphicsItem * item, this->items ())
	{
		MapItem * it = qgraphicsitem_cast <MapItem *> (item);
		it->setActive (false);
	}
	QGraphicsScene::mousePressEvent (mouseEvent);
	foreach (QGraphicsItem * item, this->items ())
	{
		MapItem * it = qgraphicsitem_cast <MapItem *> (item);
		if (it->isActive ())
		{
			for (unsigned int i = 0; i < vNpc.size (); ++i)
			{
				if (vNpc[i].objectId () == it->objectId ())
				{
					emit signalMap (GamePacket::action (vNpc[i].objectId (), static_cast <int> (vNpc[i].pos ().x ()), static_cast <int> (vNpc[i].pos ().y ()), static_cast <int> (vNpc[i].pos ().z ())));
					return;
				}
			}
			for (unsigned int i = 0; i < vChar.size (); ++i)
			{
				if (vChar[i].objectId () == it->objectId ())
				{
					emit signalMap (GamePacket::action (vChar[i].objectId (), static_cast <int> (vChar[i].pos ().x ()), static_cast <int> (vChar[i].pos ().y ()), static_cast <int> (vChar[i].pos ().z ())));
					if (!vChar[i].isTrading ())
					{
						emit signalMap (GamePacket::tradeRequest (vChar[i].objectId ()));
					}
					return;
				}
			}
		}
	}
}

void MapScene::slotInfoBarSelected (const int object, const int clicks)
{
	if (clicks == 1)
	{
		foreach (QGraphicsItem * item, this->items ())
		{
			MapItem * it = qgraphicsitem_cast <MapItem *> (item);
			if (it->objectId () == object)
			{
				foreach (QGraphicsItem * items, this->items ())
				{
					MapItem * ite = qgraphicsitem_cast <MapItem *> (items);
					ite->setActive (false);
				}
				it->setActive (true);
				return;
			}
		}
	}
	else if (clicks == 2)
	{
		foreach (QGraphicsItem * item, this->items ())
		{
			MapItem * it = qgraphicsitem_cast <MapItem *> (item);
			if (it->objectId () == object)
			{
				for (unsigned int i = 0; i < vNpc.size (); ++i)
				{
					if (vNpc[i].objectId () == it->objectId ())
					{
						emit signalMap (GamePacket::action (vNpc[i].objectId (), static_cast <int> (vNpc[i].pos ().x ()), static_cast <int> (vNpc[i].pos ().y ()), static_cast <int> (vNpc[i].pos ().z ())));
						return;
					}
				}
				for (unsigned int i = 0; i < vChar.size (); ++i)
				{
					if (vChar[i].objectId () == it->objectId ())
					{
						emit signalMap (GamePacket::action (vChar[i].objectId (), static_cast <int> (vChar[i].pos ().x ()), static_cast <int> (vChar[i].pos ().y ()), static_cast <int> (vChar[i].pos ().z ())));
						if (!vChar[i].isTrading ())
						{
							emit signalMap (GamePacket::tradeRequest (vChar[i].objectId ()));
						}
						return;
					}
				}
			}
		}
	}
}

template <class T, class F> void MapScene::moveToPawn_ (T * object, F * target, const CatXPoint & pnt, const int dist)
{
	double path = sqrt ((object->pos ().x () - target->pos ().x ()) * (object->pos ().x () - target->pos ().x ()) + (object->pos ().y () - target->pos ().y ()) * (object->pos ().y () - target->pos ().y ()));
	double newX = target->pos ().x () - dist * (target->pos ().x () - pnt.x ()) / path;
	double newY = target->pos ().y () - dist * (target->pos ().y () - pnt.y ()) / path;
	object->setPos (pnt);
	object->setNext (CatXPoint (newX, newY, target->pos ().z ()));
}

void MapScene::moveToPawn (const int object, const int target, const CatXPoint & pnt, const int dist)
{
	if (user.objectId () == object)
	{
		user.setPos (pnt);
		for (unsigned int i = 0; i < vNpc.size (); ++i)
		{
			if (vNpc[i].objectId () == target)
			{
				moveToPawn_ (&user, &vNpc[i], pnt, dist);
				return;
			}
		}
		for (unsigned int i = 0; i < vChar.size (); ++i)
		{
			if (vChar[i].objectId () == target)
			{
				moveToPawn_ (&user, &vChar[i], pnt, dist);
				return;
			}
		}
	}
	for (unsigned int i = 0; i < vChar.size (); ++i)
	{
		if (vChar[i].objectId () == object)
		{
			if (user.objectId () == target)
			{
				moveToPawn_ (&vChar[i], &user, pnt, dist);
				return;
			}
			for (unsigned int j = 0; j < vNpc.size (); ++j)
			{
				if (vNpc[j].objectId () == target)
				{
					moveToPawn_ (&vChar[i], &vNpc[j], pnt, dist);
					return;
				}
			}
			for (unsigned int j = 0; j < vChar.size (); ++j)
			{
				if (vChar[j].objectId () == target)
				{
					moveToPawn_ (&vChar[i], &vChar[j], pnt, dist);
					return;
				}
			}
		}
	}
	for (unsigned int i = 0; i < vNpc.size (); ++i)
	{
		if (vNpc[i].objectId () == object)
		{
			if (user.objectId () == target)
			{
				moveToPawn_ (&vNpc[i], &user, pnt, dist);
				return;
			}
			for (unsigned int j = 0; j < vChar.size (); ++j)
			{
				if (vChar[j].objectId () == target)
				{
					moveToPawn_ (&vNpc[i], &vChar[j], pnt, dist);
					return;
				}
			}
			for (unsigned int j = 0; j < vNpc.size (); ++j)
			{
				if (vNpc[j].objectId () == target)	
				{
					moveToPawn_ (&vNpc[i], &vNpc[j], pnt, dist);
					return;
				}
			}
		}
	}
}

void MapScene::actionFail ()
{
	user.setNext (user.pos ());
}

void MapScene::stopMove (const int objectId, const CatXPoint & pos)
{
	if (user.objectId () == objectId)
	{
		user.setNext (pos);
		return;
	}
	for (unsigned int i = 0; i < vChar.size (); ++i)
	{
		if (vChar[i].objectId () == objectId)
		{
			vChar[i].setNext (pos);
			return;
		}
	}
	for (unsigned int i = 0; i < vNpc.size (); ++i)
	{
		if (vNpc[i].objectId () == objectId)
		{
			vNpc[i].setNext (pos);
			return;
		}
	}
}

void MapScene::setAlt (const int objectId, const string & msg)
{
	for (unsigned int i = 0; i < vChar.size (); ++i)
	{
		if (vChar[i].objectId () == objectId)
		{
			vChar[i].mapItem ()->setAlt (msg.c_str ());
			break;
		}
	}
}

void MapScene::teleportToLocation (int objectId, const CatXPoint & pos)
{
	if (user.objectId () == objectId)
	{
		loadMap_ (pos);
		user.setPos (pos);
		user.setNext (pos);
		user.mapItem ()->setPos (l2ToWindowCoordinate_ (static_cast <int> (user.pos ().x ()), static_cast <int> (user.pos ().y ())));
	}
	else
	{
		for (unsigned int i = 0; i < vNpc.size (); ++i)
		{
			if (vNpc[i].objectId () == objectId)
			{
				vNpc[i].setPos (pos);
				vNpc[i].setNext (pos);
				vNpc[i].mapItem ()->setPos (l2ToWindowCoordinate_ (static_cast <int> (vNpc[i].pos ().x ()), static_cast <int> (vNpc[i].pos ().y ())));
				return;
			}
		}
		for (unsigned int i = 0; i < vChar.size (); ++i)
		{
			if (vChar[i].objectId () == objectId)
			{
				vChar[i].setPos (pos);
				vChar[i].setNext (pos);
				vChar[i].mapItem ()->setPos (l2ToWindowCoordinate_ (static_cast <int> (vChar[i].pos ().x ()), static_cast <int> (vChar[i].pos ().y ())));
				return;
			}
		}
	}
}

void MapScene::setScale (double scale)
{
	scale_ = scale;
}

double MapScene::scale () const
{
	return scale_;
}

void MapScene::restart () const
{
	map_.load ("images/intro.jpg");
}

void MapScene::setWaitType (int val)
{
	waitType_ = val;
}
