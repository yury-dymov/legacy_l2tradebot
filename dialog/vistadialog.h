#ifndef __VISTA_DIALOG__
#define __VISTA_DIALOG__

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

class VistaDialog : public QDialog
{
	private:
		QPushButton * okButton_;
		QPushButton * cancelButton_;
		QHBoxLayout * buttonLayout_;
		QVBoxLayout * vla_;
		QLabel * vistaLabel_;
	public:
		VistaDialog ();
		~VistaDialog ();
};

#endif
