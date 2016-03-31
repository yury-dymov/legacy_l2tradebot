#ifndef __NPC_HTML_MESSAGE__
#define __NPC_HTML_MESSAGE__

#include <QDialog>
#include <QScrollArea>
#include <QHBoxLayout>
#include <QLabel>
#include <QString>

#include "../catx/convert.h"
#include "../data.h"

#include <string>

using namespace std;
using namespace CatX;

class NpcHtmlMessage : public QDialog
{
	Q_OBJECT
	private:
		QScrollArea * pArea_;
		QHBoxLayout * pLayout_;
		QLabel * pLabel_;
		string l2ToHtml_ (const string & pck) const;
		string result_;
	public:
		string result () const;
		NpcHtmlMessage (const string &);
		~NpcHtmlMessage ();
	private slots:
		void slotLinkActivated (const QString &);
};

#endif
