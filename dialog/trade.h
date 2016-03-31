#ifndef __TRADE_H__
#define __TRADE_H__

#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QProgressBar>
#include <QTimer>
#include <QHeaderView>

#include <string>
#include <vector>

#include "tradewidget.h"
#include "../game_struct.h"
#include "../data.h"

using namespace std;

class TradeRequest : public QDialog
{
	Q_OBJECT
	private:
		QPushButton * okButton_;
		QPushButton * cancelButton_;
		QLabel * motd_;
		QHBoxLayout * buttonsLayout_;
		QVBoxLayout * mainLayout_;
		QProgressBar * progress_;
		QTimer * timer_;
	public:
		TradeRequest (const string & name);
		~TradeRequest ();
	private slots:
		void slotTimeout ();
};

class Trade : public QDialog
{
	Q_OBJECT
	private:
		QPushButton * okButton_;
		QPushButton * cancelButton_;
		QLabel * bagLabel_;
		QLabel * userLabel_;
		QLabel * charLabel_;
		QHBoxLayout * buttonsLayout_;
		QVBoxLayout * mainLayout_;
		TradeUpperWidget * upper_;
		TradeCharWidget * char_;
		TradeUserWidget * user_;
	signals:
		void sendPacket (const string & str);
	public:
		void tradePressOwnOk ();
		void tradePressOtherOk ();
		void tradeOwnAdd (const vector <TradeItem> &);
		void tradeOtherAdd (const vector <TradeItem> &);
		Trade (const string & name, int objectId, const vector <TradeItem> &);
		~Trade ();
	public slots:
		void slotCancel ();
	private slots:
		void slotRecievePacket (const string & str);
		void slotOk ();
};

#endif
