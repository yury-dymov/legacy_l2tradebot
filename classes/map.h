#ifndef __MAP__
#define __MAP__

#include <QGraphicsScene>
#include <QtGui>
#include <QtGui/QGraphicsView>

#include <vector>
#include <string>

#include <math.h>
#include "map_scene.h"

using namespace std;

class Map : public QGraphicsView
{
	Q_OBJECT
//	private:
	private:
		MapScene * myScene_;
		qreal scale_;
	protected:
		void mousePressEvent (QMouseEvent *);
		void mouseReleaseEvent (QMouseEvent *);
		void wheelEvent (QWheelEvent *);
	public:
		void fullUpdate () const;
		Map (QWidget * parent = 0);
		~Map ();
	signals:
		void signalMap (const string &);
		void signalAddItem (const int, const int, const string &);
		void signalDeleteItem (const int, const int);
		void signalCreateNpc (const Npc &);
		void signalCreateUser (const User &);
		void signalCreateChar (const Char &);
		void signalDeleteObject (const int);
		void signalInfoBarSelected (const int, const int);
	private slots:
		void slotMap (const string &);
		void slotAddItem (const int, const int, const string &);
		void slotDeleteItem (const int, const int);
		void slotCreateNpc (const Npc &);
		void slotCreateUser (const User &);
		void slotCreateChar (const Char &);
		void slotDeleteObject (const int);
		void slotInfoBarSelected (const int, const int);
		void enterWorld (bool);
};

#endif
