#ifndef __PRIVATE_STORE__
#define __PRIVATE_STORE__

#include <QDialog>
#include <QHeaderView>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QCheckBox>
#include <QPushButton>
#include <QLabel>

#include <string>
#include <vector>

#include "sellbuywidget.h"
#include "setmessagedialog.h"
#include "../data.h"

using namespace std;

class PrivateStoreManageList : public QDialog
{
	Q_OBJECT
	private:
		QVBoxLayout * la_;
		int package_;
		int adena_;
		QLabel * adenaLabel_;
		QLabel * incomeLabel_;
		QLabel * packageLabel_;
		QCheckBox * packageCheckbox_;
		SellWidget * pOwn_;
		QPushButton * okButton_;
		QPushButton * messageButton_;
		QPushButton * cancelButton_;
		QHBoxLayout * buttonsLayout_;
		QHBoxLayout * infoLayout_;
	public:
		PrivateStoreManageList (const int package, const int adena, const vector <SellItem> & items);
		~PrivateStoreManageList ();
		string packet ();
	private slots:
		void slotChangeIncome ();
		void slotSetMessage ();
};

class PrivateStoreManageBuyList : public QDialog
{
	Q_OBJECT
	private:
		QVBoxLayout * la_;
		int adena_;
		QLabel * adenaLabel_;
		QLabel * incomeLabel_;
		QLabel * packageLabel_;
		BuyWidget * pOwn_;
		QPushButton * okButton_;
		QPushButton * messageButton_;
		QPushButton * cancelButton_;
		QHBoxLayout * buttonsLayout_;
		QHBoxLayout * infoLayout_;
		int pack_ (int, int);
	public:
		PrivateStoreManageBuyList (int adena, const vector <BuyItem> & items);
		~PrivateStoreManageBuyList ();
		string packet ();
	private slots:
		void slotChangeIncome ();
		void slotSetMessage ();
};


#endif
