#ifndef __COUNT_DIALOG__
#define __COUNT_DIALOG__

#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <string>

#include "../datafunc.h"

using namespace std;
using namespace CatX;

class CountDialog : public QDialog
{
	Q_OBJECT
	private:
		int max_;
		QPushButton * digits_ [10];
		QPushButton * okButton_; 
		QPushButton * cancelButton_;
		QPushButton * allButton_;
		QPushButton * clearButton_;
		QPushButton * delButton_;
		QLineEdit * lineEdit_;
		QLabel * motd_;
		QGridLayout * la_;
		QHBoxLayout * hlaMain_;
		QHBoxLayout * buttons_;
		QVBoxLayout * leftLayout_;
	public:
		CountDialog (const QString &, const int max = 0);
		int result () const;
		~CountDialog ();
	private slots:
		void slotDigitPressed_ ();
		void slotTextChanged_ (const QString &);
		void slotMax_ ();
		void slotClear_ ();
		void slotDel_ ();
};

#endif
