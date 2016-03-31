#ifndef __SET_MESSAGE_DIALOG__
#define __SET_MESSAGE_DIALOG__

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QString>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include "../data.h"

class SetMessageDialog : public QDialog
{
	Q_OBJECT
	private:
		QVBoxLayout * mainLayout_;
		QHBoxLayout * buttonsLayout_;
		QLineEdit * input_;
		QPushButton * okButton_;
		QPushButton * cancelButton_;
		QLabel * motd_;
	public:
		SetMessageDialog (const QString & msg = "", const QString & motd = "");
		~SetMessageDialog ();
		QString result () const;
};

#endif
