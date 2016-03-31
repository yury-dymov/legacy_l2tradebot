#ifndef __SYSTEM_MESSAGE_WIDGET__
#define __SYSTEM_MESSAGE_WIDGET__

#include <QTextEdit>
#include <QString>
#include <string>

using namespace std;

class SystemMessageWidget : public QTextEdit
{
	Q_OBJECT
	public:
		SystemMessageWidget ();
	private slots:
		void addSystemMessage (const string &);
		void slotEnterWorld (bool);
};

#endif
