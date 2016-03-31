#include "chatwidget.h"

ChatWidget::ChatWidget ()
{
	chatTab_ = new QTabWidget;
	chatTab_->setTabPosition (QTabWidget::South);
	chatAll_ = new QTextEdit;
	chatParty_ = new QTextEdit;
	chatTrade_ = new QTextEdit;
	chatClan_ = new QTextEdit;
	chatAlly_ = new QTextEdit;
	chatSystem_ = new QTextEdit;
	chatInput_ = new QLineEdit;
	connect (chatInput_, SIGNAL (returnPressed ()), SLOT (slotChatSend ()));
	connect (chatTab_, SIGNAL (currentChanged (int)), SLOT (slotChatTab (int)));
	connect (chatInput_, SIGNAL (cursorPositionChanged (int, int)), SLOT (slotPM (int, int)));
	chatAll_->setReadOnly (true);
	chatParty_->setReadOnly (true);
	chatTrade_->setReadOnly (true);
	chatClan_->setReadOnly (true);
	chatAlly_->setReadOnly (true);
	chatSystem_->setReadOnly (true);
	chatTab_->resize (500, 300);
	chatTab_->addTab (chatAll_, "All");
	chatTab_->addTab (chatTrade_, "+Trade");
	chatTab_->addTab (chatParty_, "#Party");
	chatTab_->addTab (chatClan_, "@Clan");
	chatTab_->addTab (chatAlly_, "$Ally");
	chatTab_->addTab (chatSystem_, "System");
	qvbx_ = new QVBoxLayout;
	qvbx_->addWidget (chatTab_);
	qvbx_->addWidget (chatInput_);
	this->setLayout (qvbx_);
	this->show ();
}

ChatWidget::~ChatWidget ()
{
	delete chatAll_;
	delete chatParty_;
	delete chatTrade_;
	delete chatClan_;
	delete chatAlly_;
	delete chatSystem_;
	delete chatTab_;
	delete chatInput_;
	delete qvbx_;
}

void ChatWidget::slotChatTab (int indx)
{
	std::string a = chatInput_->text ().toStdString ();
	if (a[0] == '+' || a[0] == '@' || a[0] == '$' || a[0] == '#')
	{
		chatInput_->setText (a.substr (1, a.length () - 1).c_str ());
	}
	switch (indx)
	{
		case 1:
			chatInput_->setText ('+' + chatInput_->text ());
			break;
		case 2:
			chatInput_->setText ('#' + chatInput_->text ());
			break;
		case 3:
			chatInput_->setText ('@' + chatInput_->text ());
			break;
		case 4:
			chatInput_->setText ('$' + chatInput_->text ());
			break;
	}
}

void ChatWidget::slotSay2 (const std::string & msg)
{
	std::string str[2];
	std::string app;
	int type = static_cast <unsigned char> (msg[0]);
	int j = 0;
	for (unsigned int i = 4; i <msg.length (); ++i)
	{
		if (msg[i] != static_cast <char> (0))
		{
				str[j] += msg[i];
		}
		else
		{
			if (str[0].length () > 0)
			{
				++j;
			}
		}
	}		
	app += str[0];
	if (str[1].length () > 0)
	{
		app += ": ";
		app += str[1];
	}
	switch (type)
	{
		case SAY_ALL:
			chatAll_->setTextColor (QColor (0, 0, 0));
			break;
		case SAY_SHOUT:
			chatAll_->setTextColor (QColor (0xee, 0x76, 0));
			break;
		case SAY_PM:
			if (str[0][0] != '-' && str[0][1] != '>')
			{
				pm_ = str[0];
			}
			chatAll_->setTextColor (QColor (0xb0, 0x30, 0x60));
			chatTrade_->setTextColor (QColor (0xb0, 0x30, 0x60));
			chatTrade_->append (app.c_str ());
			chatClan_->setTextColor (QColor (0xb0, 0x30, 0x60));
			chatClan_->append (app.c_str ());
			chatParty_->setTextColor (QColor (0xb0, 0x30, 0x60));
			chatParty_->append (app.c_str ());
			chatAlly_->setTextColor (QColor (0xb0, 0x30, 0x60));
			chatAlly_->append (app.c_str ());
			break;
		case SAY_PARTY:
			chatAll_->setTextColor (QColor (0x00, 0xcd, 0x00));
			chatParty_->setTextColor (QColor (0x00, 0xcd, 0x00));
			chatParty_->append (app.c_str ());
			break;
		case SAY_CLAN:
			chatAll_->setTextColor (QColor (0x7d, 0x26, 0xcd));
			chatClan_->setTextColor (QColor (0x7d, 0x26, 0xcd));
			chatClan_->append (app.c_str ());
			break;
		case SAY_TRADE:
			chatAll_->setTextColor (QColor (0xee, 0x6a, 0xa7));
			chatTrade_->setTextColor (QColor (0xee, 0x6a, 0xa7));
			chatTrade_->append (app.c_str ());
			break;
		case SAY_ALLY:
			chatAll_->setTextColor (QColor (0, 0xcd, 0x6));
			chatAlly_->setTextColor (QColor (0, 0xcd, 0x6));
			chatAlly_->append (app.c_str ());
			break;
		case SAY_ANNOUNCE:
			app = "Annoucement: " + app;
			chatAll_->setTextColor (QColor (0, 0x8b, 0x8b));
			chatTrade_->setTextColor (QColor (0, 0x8b, 0x8b));
			chatTrade_->append (app.c_str ());
			chatClan_->setTextColor (QColor (0, 0x8b, 0x8b));
			chatClan_->append (app.c_str ());
			chatParty_->setTextColor (QColor (0, 0x8b, 0x8b));
			chatParty_->append (app.c_str ());
			chatAlly_->setTextColor (QColor (0, 0x8b, 0x8b));
			chatAlly_->append (app.c_str ());
			break;
		case SAY_HERO:
			chatAll_->setTextColor (QColor (0, 0, 0xcd));
			break;
	}
	chatAll_->append (app.c_str ());
}

void ChatWidget::slotPM (int old, int nw)
{
	std::string str = chatInput_->text ().toStdString ();
	if (str.length () == 1 && str[0] == '"' && old == 0 && nw == 1)
	{
		if (pm_.length () > 0)
		{
			str += pm_;
			str += " ";
		}
		chatInput_->setText (str.c_str());
	}
}

void ChatWidget::slotChatSend ()
{
	std::string msg = chatInput_->text ().toStdString ();
	if (msg.length () > 0)
	{
		if ((msg[0] == '+' && chatTab_->currentIndex () == 1) || (msg[0] == '#' && chatTab_->currentIndex () == 2) || (msg[0] == '@' && chatTab_->currentIndex () == 3) || (msg[0] == '$' && chatTab_->currentIndex () == 4))
		{
			if (msg.length () == 1)
			{
					return;
			}
		}
		chatInput_->clear ();
		unsigned int i = 0;
		switch (msg[0])
		{
			case '"':
				while (i < msg.length () && msg[i++] != ' ')
				{
					;
				}
				if (i == msg.length ())
				{
					return; 
				}
				emit signalSay2 (msg.substr (i, msg.length ()), SAY_PM, msg.substr (1, i - 2));
				pm_ = msg.substr (1, i - 2);
				break;
			case '#':
				emit signalSay2 (msg.substr (1, msg.length ()), SAY_PARTY);
				break;
			case '+':
				emit signalSay2 (msg.substr (1, msg.length ()), SAY_TRADE);
				break;
			case '@':
				emit signalSay2 (msg.substr (1, msg.length ()), SAY_CLAN);
				break;
			case '$':
				emit signalSay2 (msg.substr (1, msg.length ()), SAY_ALLY);
				break;
			default:
				emit signalSay2 (msg);
				break;
		}
	}
}

void ChatWidget::setPM (const string & name)
{
	pm_ = '"' + name;
	chatInput_->setText (QString (pm_.c_str ()) + " ");
}

void ChatWidget::slotSystemMessage (const string & msg)
{
	chatAll_->setTextColor (QColor (0x79, 0x9b, 0xb0/*, 0xff*/));
	chatAll_->append (msg.c_str ());	
	chatTrade_->setTextColor (QColor (0x79, 0x9b, 0xb0/*, 0xff*/));
	chatTrade_->append (msg.c_str ());
	chatSystem_->setTextColor (QColor (0x79, 0x9b, 0xb0/*, 0xff*/));
	chatSystem_->append (msg.c_str ());
}

void ChatWidget::slotEnterWorld (bool)
{
	chatAll_->clear ();
	chatTrade_->clear ();
	chatParty_->clear ();
	chatClan_->clear ();
	chatAlly_->clear ();
	chatSystem_->clear ();
}
