#ifndef _LOGIN_THREAD_
#define _LOGIN_THREAD_

#include <QThread>
#include <QTcpSocket>
#include <string>
#include <map>

#include "../data.h"
#include "classes/bfish.h"
#include "classes/serverlist.h"
#include "classes/logindata.h"
#include "packet/loginpacket.h"


using namespace std;

class LoginThread : public QThread
{
	Q_OBJECT
	private:
		bool init_;
		int bSize_;
		QTcpSocket * pSocket_;
		Blowfish bFish_;
		void write_ (const string &) const;
	signals:
		void signalLoginSendData (const int id, const string & data);
	public:
		void close ();
		LoginThread ();
		~LoginThread ();
		void run ();
	public slots:
		void slotLoginRecvData (const int id, const string & data);
	private slots:
		void slotLoginReadyRead_ ();
		void slotLoginDisconnected_ ();
};

#endif
