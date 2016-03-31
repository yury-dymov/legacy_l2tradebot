#ifndef __LOGIN_DIALOG__
#define __LOGIN_DIALOG__

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
#include <QString>

class LoginDialog : public QDialog
{
	Q_OBJECT
	private:
		QGridLayout * layout_;
		QPushButton * okButton_;
		QPushButton * cancelButton_;
		QLabel * accountLabel_;
		QLabel * passwordLabel_;
		QLineEdit * accountEdit_;
		QLineEdit * passwordEdit_;
	public:
		LoginDialog ();
		~LoginDialog ();
		QString account () const;
		QString password () const;
};

#endif
