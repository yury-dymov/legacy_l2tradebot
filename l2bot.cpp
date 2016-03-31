#include "l2bot.h"

L2Bot::L2Bot ()
{
	Data::init ();
	tray_ = new QSystemTrayIcon (QIcon("images/adena.png"), this);
	connect (this, SIGNAL (signalPlaceToTray ()), this, SLOT(slotPlaceToTray()), Qt::QueuedConnection);
	connect (tray_, SIGNAL (activated (QSystemTrayIcon::ActivationReason)), SLOT (slotGetFromTray (QSystemTrayIcon::ActivationReason)));
	gameThread_ = new GameThread;
	createMenu_ ();
	map_ = new Map;
	chatWidget_ = new ChatWidget;
	widgets_ = new QTabWidget;
	widgets_->resize (300, 300);
	widgets_->addTab (map_, "Map");
	bag_ = new BagWidget;
	widgets_->addTab (bag_, "Bag");
	widgets_->addTab (chatWidget_, "Chat");
	QWidget * window = new QWidget;
	QHBoxLayout * la = new QHBoxLayout;
	InfoBar * info = new InfoBar;
	connect (map_, SIGNAL (signalAddItem (const int, const int, const string &)), info, SLOT (slotAddItem (const int, const int, const string &)));
	connect (gameThread_, SIGNAL (enterWorld (bool)), map_, SLOT (enterWorld (bool)));
	connect (gameThread_, SIGNAL (signalAddItem (const int, const int, const string &)), info, SLOT (slotAddItem (const int, const int, const string &)));
	connect (gameThread_, SIGNAL (signalSystemMessage (const string &)), chatWidget_, SLOT (slotSystemMessage (const string &)));
	connect (gameThread_, SIGNAL (enterWorld (bool)), chatWidget_, SLOT (slotEnterWorld (bool)));
	connect (map_, SIGNAL (signalDeleteItem (const int, const int)), info, SLOT (slotDeleteItem (const int, const int)));
	connect (info, SIGNAL (signalInfoBarSelected (const int, const int)), this, SLOT (slotInfoBarSelected (const int, const int)));
	connect (gameThread_, SIGNAL (enterWorld (bool)), info, SLOT (slotEnterWorld (bool)));
	connect (this, SIGNAL (signalInfoBarSelected (const int, const int)), map_, SLOT (slotInfoBarSelected (const int, const int)));
	connect (chatWidget_, SIGNAL (signalSay2 (const string &, const int, const string &)), gameThread_, SLOT (slotSay2 (const string &, const int, const string &)));
	connect (gameThread_, SIGNAL (signalSay2 (const string &)), chatWidget_, SLOT (slotSay2 (const string &)));
	connect (gameThread_, SIGNAL (signalItemList (const vector <InventoryItem> &)), bag_, SLOT (setInventory (const vector <InventoryItem> &)));
	connect (gameThread_, SIGNAL (enterWorld (bool)), bag_, SLOT (slotEnterWorld (bool)));
	connect (bag_, SIGNAL (signalWrite (const string &)), gameThread_, SLOT (slotMap (const string &)));
	vla_ = new QVBoxLayout;
	systemWidget_ = new SystemMessageWidget;
	connect (gameThread_, SIGNAL (signalSystemMessage (const string &)), systemWidget_, SLOT (addSystemMessage (const string &)));
	connect (gameThread_, SIGNAL (enterWorld (bool)), systemWidget_, SLOT (slotEnterWorld (bool)));
	vla_->addWidget (widgets_);
	vla_->addWidget (systemWidget_);
	la->addLayout (vla_);
	la->addWidget (info);
	window->setLayout (la);
	this->setFixedSize (700, 460);
	this->setCentralWidget (window);
	this->resize(500, 460);
	this->show ();
	this->move (300, 200);
	this->setWindowTitle ("F1reCaT's Trade Bot");
	this->setWindowIcon (QIcon ("images/adena.png"));

	loginThread_ = new LoginThread; 
	connect (loginThread_, SIGNAL (signalLoginSendData (const int, const string &)), SLOT (slotLoginRecvData (const int, const string &)));
	connect (this, SIGNAL (signalLoginSendData (const int, const string &)), loginThread_, SLOT (slotLoginRecvData (const int, const string &)));
	connect (gameThread_, SIGNAL (signalCreateNpc (const Npc &)), map_, SLOT (slotCreateNpc (const Npc &)));
	connect (gameThread_, SIGNAL (signalCreateUser (const User &)), map_, SLOT (slotCreateUser (const User &)));
	connect (gameThread_, SIGNAL (signalCreateChar (const Char &)), map_, SLOT (slotCreateChar (const Char &)));
	connect (gameThread_, SIGNAL (signalDeleteObject (const int)), map_, SLOT (slotDeleteObject (const int)));
	connect (gameThread_, SIGNAL (signalDeleteItem (const int, const int)), info, SLOT (slotDeleteItem (const int, const int)));
	connect (map_, SIGNAL (signalMap (const string &)), gameThread_, SLOT (slotMap (const string &)));
}

L2Bot::~L2Bot ()
{
}

void L2Bot::slotLoginRecvData (const int id, const string & /*pck*/)
{
	if (id == E_LD_LOGIN)
	{
		LoginData::login = login_;
		emit signalLoginSendData (E_LD_LOGIN_PASS, login_ + " " + pass_);
	}
	else if (id == E_LD_SELECT_SERVER)
	{
		int serverId = 1;
		SelectServerDialog * ui = new SelectServerDialog (ServerList::data);
		if (ui->exec () == QDialog::Accepted)
		{
			serverId = ServerList::data[ui->serverId ()].id;
			delete ui;
		}
		else
		{
			loginThread_->close ();
			delete ui;
			return;
		}
		for (unsigned int i = 0; i < ServerList::data.size (); ++i)
		{
			if (ServerList::data[i].id == serverId)
			{
				LoginData::ip = ServerList::data[i].ip;
				LoginData::port = ServerList::data[i].port;
				break;
			}
		}
		emit signalLoginSendData (E_LD_SERVER, Convert (serverId).toString ());
	}
	else if (id == E_LD_FAIL)
	{
		ErrorDialog * di = new ErrorDialog ("Login Fail");
		di->exec ();
		loginThread_->close ();
	}
	else if (id == E_LD_OK)
	{
		loginThread_->close ();
		gameThread_->start ();
	}
}

void L2Bot::createMenu_ ()
{
	QMenu * file = menuBar ()->addMenu ("Bot");
	QMenu * actions = menuBar ()->addMenu ("Actions");
	QAction * sell = new QAction ("Sell", this);
	QAction * buy = new QAction ("Buy", this);
	QAction * manufacture = new QAction ("Manufacture", this);
	sell->setEnabled (false);
	buy->setEnabled (false);
	manufacture->setEnabled (false);
	connect (sell, SIGNAL (triggered (bool)), gameThread_, SLOT (slotSell_ (bool)));
	connect (buy, SIGNAL (triggered (bool)), gameThread_, SLOT (slotBuy_ (bool)));
	connect (manufacture, SIGNAL (triggered (bool)), gameThread_, SLOT (slotDwarfenManufacture_ (bool)));
	connect (gameThread_, SIGNAL (enterWorld (bool)), sell, SLOT (setEnabled (bool)));
	connect (gameThread_, SIGNAL (enterWorld (bool)), buy, SLOT (setEnabled (bool)));
	connect (gameThread_, SIGNAL (enterWorld (bool)), manufacture, SLOT (setEnabled (bool)));
	QAction * con = new QAction ("Connect", this);
	QAction * discon = new QAction ("Logout", this);
	discon->setEnabled (false);
	connect (discon, SIGNAL (triggered (bool)), gameThread_, SLOT (slotLogout (bool)));
	QAction * restart = new QAction ("Restart", this);
	connect (restart, SIGNAL (triggered (bool)), gameThread_, SLOT (slotRestart (bool)));
	restart->setEnabled (false);
	QAction * quit = new QAction ("Quit", this);
	connect (quit, SIGNAL (triggered (bool)), SLOT (slotQuit (bool)));
	connect (con, SIGNAL (triggered (bool)), SLOT (slotConnect (bool)));
	connect (gameThread_, SIGNAL (enterWorld (bool)), con, SLOT (setDisabled (bool)));
	connect (gameThread_, SIGNAL (enterWorld (bool)), restart, SLOT (setEnabled (bool)));
	connect (gameThread_, SIGNAL (enterWorld (bool)), discon, SLOT (setEnabled (bool)));
	actions->addAction (sell);
	actions->addAction (buy);
	actions->addAction (manufacture);
	file->addAction (con);
	file->addAction (restart);
	file->addAction (discon);
	file->addSeparator ();
	file->addAction (quit);
	QMenu * view = menuBar ()->addMenu ("View");
	npcViewAction_ = new QAction ("Npc", this);
	npcViewAction_->setCheckable (true);
	npcViewAction_->setChecked (true);
	connect (npcViewAction_, SIGNAL (triggered (bool)), SLOT (slotView (bool)));
	view->addAction (npcViewAction_);
	playerViewAction_ = new QAction ("Players", this);
	playerViewAction_->setCheckable (true);
	playerViewAction_->setChecked (true);
	connect (playerViewAction_, SIGNAL (triggered (bool)), SLOT (slotView (bool)));
	view->addAction (playerViewAction_);
	sellViewAction_ = new QAction ("Sell", this);
	sellViewAction_->setCheckable (true);
	sellViewAction_->setChecked (true);
	connect (sellViewAction_, SIGNAL (triggered (bool)), SLOT (slotView (bool)));
	view->addAction (sellViewAction_);
	buyViewAction_ = new QAction ("Buy", this);
	buyViewAction_->setCheckable (true);
	buyViewAction_->setChecked (true);
	connect (buyViewAction_, SIGNAL (triggered (bool)), SLOT (slotView (bool)));
	view->addAction (buyViewAction_);
	craftViewAction_ = new QAction ("Craft", this);
	craftViewAction_->setCheckable (true);
	craftViewAction_->setChecked (true);
	connect (craftViewAction_, SIGNAL (triggered (bool)), SLOT (slotView (bool)));
	view->addAction (craftViewAction_);
}

void L2Bot::changeEvent (QEvent *event)
{
	if (event->type() == QEvent::WindowStateChange)
	{
		if (isMinimized())
		{
			event->ignore();
			emit signalPlaceToTray();
			return;
		}
	}
	QMainWindow::changeEvent (event);
}

void L2Bot::slotPlaceToTray ()
{
	tray_->show();
	hide();
}

void L2Bot::slotGetFromTray (QSystemTrayIcon::ActivationReason)
{
	tray_->hide ();
	show ();
}

void L2Bot::slotInfoBarSelected (const int objectId, const int clicks)
{
	if (clicks == 2 && widgets_->currentIndex () == E_MAIN_CHAT)
	{
		for (unsigned int i = 0; i < MapScene::vChar.size (); ++i)
		{
			if (MapScene::vChar[i].objectId () == objectId)
			{
				chatWidget_->setPM (MapScene::vChar[i].name ());
				break;
			}
		}
	}
	else
	{
		emit signalInfoBarSelected (objectId, clicks);
	}
}

void L2Bot::slotConnect (bool)
{
		LoginDialog * di = new LoginDialog;
		if (di->exec () == QDialog::Accepted)
		{
			login_ = di->account ().toStdString ();
			pass_ = di->password ().toStdString ();
			loginThread_->start ();
		}
		delete di;
}

void L2Bot::slotQuit (bool)
{
	exit (0);
}

void L2Bot::slotView (bool val)
{
	if (sender () == craftViewAction_)
	{
		MapItem::setView (E_CRAFT, val);
	}
	else if (sender () == sellViewAction_)
	{
		MapItem::setView (E_SELL, val);
	}
	else if (sender () == buyViewAction_)
	{
		MapItem::setView (E_BUY, val);
	}
	else if (sender () == playerViewAction_)
	{
		MapItem::setView (E_CHAR, val);
	}
	else if (sender () == npcViewAction_)
	{
		MapItem::setView (E_NPC, val);
	}
	map_->fullUpdate ();
}

