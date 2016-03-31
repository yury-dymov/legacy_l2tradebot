#ifndef __MAP_ITEM__
#define __MAP_ITEM__

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QList>
#include <QPainter>
#include <QColor>
#include <QStyleOption>
#include <QGraphicsSceneMouseEvent>
#include <QString>

enum
{
	E_NPC = 0,
	E_SELL = 1,
	E_BUY = 2,
	E_CRAFT = 3,
	E_CHAR = 4,
	E_USER = 5
};

class MapItem : public QGraphicsItem
{
	//Q_OBJECT
	private:
		bool show_;
		int stereotype_;
		bool active_;
		int objectId_;
		QString name_;
		bool isVisible_ () const;
	private:
		static bool npcShow_;
		static bool charShow_;
		static bool craftShow_;
		static bool sellShow_;
		static bool buyShow_;
	protected:
		QRectF boundingRect () const;
		void paint (QPainter *, const QStyleOptionGraphicsItem *, QWidget *);
		void mousePressEvent (QGraphicsSceneMouseEvent * event);
		void mouseReleaseEvent (QGraphicsSceneMouseEvent * event);
		void mouseDoubleClickEvent (QGraphicsSceneMouseEvent * mouseEvent);
	public:
		static void setView (int, bool);
		int stereotype () const;
		bool isActive () const;
		void setActive (const bool);
		bool isShow () const;
		void setShow (const bool);
		int objectId () const;
		void setStereotype (int);
		void setAlt (const QString & alt);
		void setName (const QString & name);
		MapItem (int stereotype, int objectId = 0, QGraphicsItem * parent = 0);
};

#endif
