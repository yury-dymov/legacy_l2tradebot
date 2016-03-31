#ifndef __PLAYER_STORE__
#define __PLAYER_STORE__

#include <QDialog>
#include <QHeaderView>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QCheckBox>
#include <QPushButton>
#include <QLabel>

#include <string>
#include <vector>

#include "playersellbuy.h"
#include "../data.h"

using namespace std;


class PlayerStoreList : public QDialog
{
	Q_OBJECT
	private:
		QVBoxLayout * la_;
		int package_;
		int adena_;
		QLabel * adenaLabel_;
		QLabel * incomeLabel_;
		PlayerSellWidget * pOwn_;
		PlayerSellWidget * pShow_;		
		QPushButton * okButton_;
		QPushButton * cancelButton_;
		QHBoxLayout * buttonsLayout_;
		QHBoxLayout * infoLayout_;
	public:
		PlayerStoreList (const int package, const int adena, const vector <PlayerSellItem> & items);
		~PlayerStoreList ();
		string packet ();
	private slots:
		void slotChangeIncome ();
};

class PlayerStoreListBuy : public QDialog
{
	Q_OBJECT
	private:
		QVBoxLayout * la_;
		int adena_;
		QLabel * adenaLabel_;
		QLabel * incomeLabel_;
		PlayerBuyWidget * pOwn_;
		PlayerBuyWidget * pShow_;		
		QPushButton * okButton_;
		QPushButton * cancelButton_;
		QHBoxLayout * buttonsLayout_;
		QHBoxLayout * infoLayout_;
	public:
		PlayerStoreListBuy (const int adena, const vector <PlayerBuyItem> & items);
		~PlayerStoreListBuy ();
		string packet ();
	private slots:
		void slotChangeIncome ();
};

#endif
