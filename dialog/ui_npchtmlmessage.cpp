#include "npchtmlmessage.h"

NpcHtmlMessage::NpcHtmlMessage (const string & pck)
{
	pArea_ = new QScrollArea;
	pLayout_ = new QHBoxLayout;
	pLabel_ = new QLabel (l2ToHtml_ (pck).c_str ());
	pLabel_->setBackgroundRole (QPalette::Shadow);
	pLabel_->setWordWrap (true);
	pLabel_->setAlignment (Qt::AlignTop);
	pArea_->setWidget (pLabel_);
	pArea_->setWidgetResizable (true);
	pArea_->setMaximumWidth (320);
	pLabel_->setIndent (5);
	pLayout_->addWidget (pArea_);
	this->setLayout (pLayout_);
	this->move (500, 300);
	this->setFixedSize (300, 400);
	this->setMinimumHeight (300);
	this->setMinimumWidth (300);
	this->setWindowTitle ("Talking...");
	connect (pLabel_, SIGNAL (linkActivated (const QString &)), SLOT (slotLinkActivated (const QString &)));
}

NpcHtmlMessage::~NpcHtmlMessage ()
{
	delete pLabel_;
	delete pArea_;
	delete pLayout_;
}

string NpcHtmlMessage::l2ToHtml_ (const string & pck) const
{
	string ret;
	for (unsigned int i = 0; i < pck.length (); ++i)
	{
		if (pck.substr (i, 5) == "LEVEL")
		{
			ret += "YELLOW";
			i += 4;
		}
		else if (pck.substr (i, 6) == "action")
		{
			ret += "href";
			i += 5;
		}
		else if (pck.substr (i, 5) == "<br1>")
		{
			ret += "<br>";
			i += 4;
		}
		else if (pck.substr (i, 2) == "&$")
		{
			i += 2;
			string num;
			while (isdigit (pck[i]))
			{
				num += pck[i++];
			}
			ret += Data::sysstring (Convert (num).toInt ());
		}
		else
		{
			ret += pck[i];
		}
	}
	return ret;
}

void NpcHtmlMessage::slotLinkActivated (const QString & str)
{
	result_ = str.toStdString ();
	this->accept ();
}

string NpcHtmlMessage::result () const
{
	return result_;
}
