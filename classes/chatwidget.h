#ifndef __CHAT_WIDGET__
#define __CHAT_WIDGET__

#include <QWidget>
#include <QTabWidget>
#include <QTextEdit>
#include <QLineEdit>
#include <QVBoxLayout>

#include <string>
#include "../data.h"

using namespace std;

class ChatWidget : public QWidget
{
	Q_OBJECT
	private:
		QTabWidget * chatTab_;
		QTextEdit * chatAll_;
		QTextEdit * chatParty_;
		QTextEdit * chatTrade_;
		QTextEdit * chatClan_;
		QTextEdit * chatAlly_;
		QTextEdit * chatSystem_;
		QLineEdit * chatInput_;
		QVBoxLayout * qvbx_;
		string pm_;
	public:
		void setPM (const string & name);
		ChatWidget ();
		~ChatWidget ();
	signals:
		void signalSay2 (const string & str1, const int type = SAY_ALL, const string & target = "");
	private slots:
		void slotPM (int, int);
		void slotChatTab (int);
		void slotChatSend ();
		void slotSay2 (const string &);
		void slotSystemMessage (const string &);
		void slotEnterWorld (bool);
};

#endif
