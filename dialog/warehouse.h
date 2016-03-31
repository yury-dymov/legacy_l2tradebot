#ifndef __WAREHOUSE__
#define __WAREHOUSE__

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QHeaderView>

#include "warehousewidget.h"
#include "../game_struct.h"
#include "../datafunc.h"
#include "../data.h"

#include <string>

using namespace std;

class WarehouseDeposit : public QDialog
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
		WarehouseDepositWidget * upWidget_;
		WarehouseDepositWidget * downWidget_;
	public:
		WarehouseDeposit (int adena, const vector <WarehouseItem> &);
		~WarehouseDeposit ();
		string packet ();
	private slots:
		void changeTotal (int);
};

class WarehouseWithdraw : public QDialog
{
	Q_OBJECT
	private:
		QLabel * adenaLabel_;
		QLabel * upLabel_;
		QLabel * downLabel_;
		QPushButton * okButton_;
		QPushButton * cancelButton_;
		QHBoxLayout * buttonsLayout_;
		QVBoxLayout * mainLayout_;
		WarehouseDepositWidget * upWidget_;
		WarehouseDepositWidget * downWidget_;
	public:
		WarehouseWithdraw (int adena, const vector <WarehouseItem> &);
		~WarehouseWithdraw ();
		string packet ();
};


#endif
