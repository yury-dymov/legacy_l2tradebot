#ifndef __L2BOT__
#define __L2BOT__

#include "login/loginthread.h"
#include "game/gamethread.h"

#include "login/classes/logindata.h"
#include "login/classes/serverlist.h"

#include "catx/convert.h"
#include "catx/catxfunc.h"

#include "classes/info_bar.h"
#include "classes/map.h"
#include "classes/chatwidget.h"
#include "classes/map_scene.h"
#include "classes/bag.h"
#include "classes/systemmessagewidget.h"

#include "dialog/logindialog.h"

#include <QMainWindow>
#include <QTabWidget>
#include <QLineEdit>
#include <QImage>
#include <QScrollArea>
#include <QLabel>
#include <QPrinter>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
class QAction;
class QLabel;
class QMenu;
class QScrollArea;
class QScrollBar;
QT_END_NAMESPACE


#include <string>

using namespace std;
using namespace CatX;

class L2Bot : public QMainWindow
{
	Q_OBJECT
	private:
		QSystemTrayIcon * tray_	;
		LoginThread * loginThread_;
		GameThread * gameThread_;
		ChatWidget * chatWidget_;
		QTabWidget * widgets_;
		SystemMessageWidget * systemWidget_;
		BagWidget * bag_;
		void createMenu_ ();
		string login_;
		string pass_;
		QVBoxLayout * vla_;
		Map * map_;
	private:
		QAction * npcViewAction_;
		QAction * playerViewAction_;
		QAction * sellViewAction_;
		QAction * buyViewAction_;
		QAction * craftViewAction_;
	protected:
		void changeEvent(QEvent *);
	public:
		L2Bot ();
		~L2Bot ();
	signals:
		void signalLoginSendData (const int, const string &);
		void signalGameSendData (const int, const string &);
		void signalPlaceToTray ();
		void signalInfoBarSelected (const int, const int);
	private slots:
		void slotLoginRecvData (const int, const string &);
		void slotPlaceToTray ();
		void slotGetFromTray (QSystemTrayIcon::ActivationReason);
		void slotInfoBarSelected (const int, const int);
		void slotConnect (bool);
		void slotQuit (bool);
		void slotView (bool);
};

#endif
