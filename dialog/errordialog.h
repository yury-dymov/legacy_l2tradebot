#ifndef __ERROR_DIALOG__
#define __ERROR_DIALOG__

#include <QDialog>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>

class ErrorDialog : public QDialog
{
	private:
		QLabel * msg_;
		QPushButton * okButton_;
		QVBoxLayout * vla_;
	public:
		ErrorDialog (const char *);
		~ErrorDialog ();
};

#endif

