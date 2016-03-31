#include "loginthread.h"

LoginThread::LoginThread ()
{
	init_ = false;
	bFish_.init (bFish_.hex2str (BLOWFISH));
}

LoginThread::~LoginThread ()
{
}

void LoginThread::run ()
{
	pSocket_ = new QTcpSocket;
	connect (pSocket_, SIGNAL (readyRead ()), SLOT (slotLoginReadyRead_ ()));
	connect (pSocket_, SIGNAL (disconnected ()), SLOT (slotLoginDisconnected_ ()));
	bSize_ = 0;
	pSocket_->connectToHost (L2_HOST, L2_PORT);
	this->exec ();
}

void LoginThread::slotLoginReadyRead_ ()
{
	if (!bSize_ && pSocket_->bytesAvailable () >= 2)
	{
		QByteArray size = pSocket_->read (2);
		bSize_ = static_cast <int> (static_cast <unsigned char> (size.at (0))) + static_cast <int> (static_cast <unsigned char> (size.at (1))) * 0x100 - 2;
	}
	if (bSize_ > 0 && pSocket_->bytesAvailable () >= bSize_)
	{
		QByteArray data = pSocket_->read (bSize_);
		bSize_ = 0;
		string pck;
		for (int i = 0; i < data.size (); ++i)
		{
			pck += data.at (i);
		}
		if (init_)
		{
			pck = bFish_.decrypt (pck);
			if (pck[0] == E_LS_S_LOGIN_OK)
			{
				LoginPacket::key1 = pck.substr (1, 8);
				write_ (bFish_.encrypt (LoginPacket::requestServerList (LoginPacket::key1)));
			}
			else if (pck[0] == E_LS_S_RECIEVED_SERVER_LIST)
			{
				ServerList::init (pck);
				emit signalLoginSendData (E_LD_SELECT_SERVER, "");
			}
			else if (pck[0] == E_LS_S_PLAY_OK)
			{
				LoginData::key2 = pck.substr (1, 8);
				emit signalLoginSendData (E_LD_OK, pck.substr (1, 8));
			}
			else
			{
				emit signalLoginSendData (E_LD_FAIL, "");
			}
		}
		else
		{
			init_ = true;
			emit signalLoginSendData (E_LD_LOGIN, "");
		}
		slotLoginReadyRead_ ();
	}
}

void LoginThread::slotLoginDisconnected_ ()
{
	init_ = false;
	delete pSocket_;
	pSocket_ = 0;
	this->quit ();
}

void LoginThread::write_ (const string & str) const
{
	string pck;
	unsigned int len = str.length () + 2;
	pck += len % 0x100;
	pck += len / 0x100;
	pck += str;
	pSocket_->write (pck.c_str (), pck.length ());
}

void LoginThread::slotLoginRecvData (const int id, const string & data)
{
	if (id == E_LD_SERVER)
	{
		write_ (bFish_.encrypt (LoginPacket::requestServerLogin (LoginPacket::key1, Convert (data).toInt ())));
	}
	else if (id == E_LD_LOGIN_PASS)
	{
		unsigned int i = 0;
		string login;
		string pass;
		for (; i < data.length (); ++i)
		{
			if (data[i] == ' ')
			{
				break;
			}
			else
			{
				login += data[i];
			}
		}
		for (i += 1; i < data.length (); ++i)
		{
			pass += data[i];
		}
		write_ (bFish_.encrypt (LoginPacket::requestAuthLogin (login, pass)));
	}
}

void LoginThread::close ()
{
	pSocket_->close ();
	this->quit ();
}
