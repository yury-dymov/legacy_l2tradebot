#ifndef __BAG_DIALOG__
#define __BAG_DIALOG__

#include <QDialog>
#include <QPushButton>
#include <QVBoxLayout>

#include "countdialog.h"
#include "vistadialog.h"

class BagDialog : public QDialog
{
	Q_OBJECT
	private:
		QVBoxLayout * vla_;
		QPushButton * useButton_;
		QPushButton * deleteButton_;
		QPushButton * cancelButton_;
		QPushButton * crystallizeButton_;
		int pushed_;
		int objectId_;
		int count_;
	public:
		int count () const;
		int pushed () const;
		BagDialog (int objectId, int count, bool crystallize);
		~BagDialog ();
	private slots:
		void slotButtonPressed ();
};

#endif
