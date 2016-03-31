#ifndef __MAP_SCENE__
#define __MAP_SCENE__

#include <QGraphicsScene>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>
#include "map_item.h"

#include "../data.h"
#include "../game/packet/gamepacket.h"
#include "../game/gamethread.h"

#include <math.h>

#define STEP 20
#define TIME_UPDATE 10

struct Maps
{
	int x0;
	int y0;
	QString file;
};


class MapScene : public QGraphicsScene
{
	Q_OBJECT
	private:
		static int waitType_;
		static vector <Maps> maps_;
		static int x0_;
		static int y0_;
		double scale_;
		static QImage map_;
		static QPointF l2ToWindowCoordinate_ (const int x, const int y);
		static void loadMap_ (const CatXPoint &);
		template <class T> bool move_ (T *);
		template <class T> bool init_ (T *);
		template <class T, class F> static void moveToPawn_ (T *, F *, const CatXPoint &, const int);
	protected:
		void drawBackground (QPainter * painter, const QRectF & rect);
		void timerEvent (QTimerEvent * event);
		void mousePressEvent (QGraphicsSceneMouseEvent * mouseEvent);
		void mouseDoubleClickEvent (QGraphicsSceneMouseEvent * mouseEvent);
	public:
		static void setWaitType (int);
		void restart () const;
		double scale () const;
		void setScale (double);
		static vector <Npc> vNpc;
		static vector <Char> vChar;
		static User user;
		static void teleportToLocation (int objectId, const CatXPoint & pos);
		static void moveToLocation (const int objectId, const CatXPoint &, const CatXPoint &);
		static void moveToPawn (const int objectId, const int target, const CatXPoint &, const int);
		static void stopMove (const int, const CatXPoint &);
		static void setAlt (const int objectId, const string & msg);
		static void actionFail ();
		static bool ignoreMouse;
		MapScene (QObject * parent = 0);
	signals:
		void signalMap (const string &);
		void signalAddItem (const int, const int, const string &);
		void signalDeleteItem (const int, const int);
	public slots:
		void slotCreateNpc (const Npc &);
		void slotCreateUser (const User &);
		void slotCreateChar (const Char &);
		void slotDeleteObject (const int id);
		void slotInfoBarSelected (const int, const int);
};

#endif
