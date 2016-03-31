#ifndef __SELECT_CHAR__
#define __SELECT_CHAR__

#include <QDialog>
#include <QPushButton>
#include <QString>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include "../data.h"
#include "../datafunc.h"
#include "../game_struct.h"

class SelectCharDialog : public QDialog
{
	Q_OBJECT
	private:
		unsigned int count_;
		QVBoxLayout * la_;
		QHBoxLayout * buttons_;
		QPushButton * players_ [10];
		QPushButton * cancel_;
		QPushButton * create_;
		int selection_;
	public:
		int selection () const;
		SelectCharDialog (const vector <CharSelectItem> &);
		~SelectCharDialog ();
	private slots:
		void slotPressed ();
};

#endif
