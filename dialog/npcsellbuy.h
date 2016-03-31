#ifndef __NPC_SELL_BUY__
#define __NPC_SELL_BUY__

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QHeaderView>
#include "npcsellbuywidget.h"
#include "../game_struct.h"
#include "../data.h"

class NpcTradeSell : public QDialog
{
	Q_OBJECT
	private:
		QLabel * adenaLabel_;
		QLabel * totalLabel_;
		QLabel * upLabel_;
		QLabel * downLabel_;
		QPushButton * okButton_;
		QPushButton * cancelButton_;
		QHBoxLayout * buttonsLayout_;
		QVBoxLayout * mainLayout_;
		NpcSellWidgetUp * upWidget_;
		NpcSellWidgetDown * downWidget_;
	public:
		NpcTradeSell (int adena, const vector <NpcSellItem> &);
		~NpcTradeSell ();
		string packet ();
	private slots:
		void changeTotal (int);
};

class NpcTradeBuy : public QDialog
{
	Q_OBJECT
	private:
		QLabel * adenaLabel_;
		QLabel * totalLabel_;
		QLabel * upLabel_;
		QLabel * downLabel_;
		QPushButton * okButton_;
		QPushButton * cancelButton_;
		QHBoxLayout * buttonsLayout_;
		QVBoxLayout * mainLayout_;
		NpcBuyWidget * upWidget_;
		NpcBuyWidget * downWidget_;
	public:
		NpcTradeBuy (int adena, const vector <NpcBuyItem> &);
		~NpcTradeBuy ();
		string packet ();
	private slots:
		void changeTotal (int);
};


#endif
