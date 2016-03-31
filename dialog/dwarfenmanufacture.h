#ifndef __DWARFEN_MANUFACTURE__
#define __DWARFEN_MANUFACTURE__

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QHeaderView>

#include "dwarfenmanufacturewidget.h"
#include "setmessagedialog.h"
#include "../game_struct.h"
#include "../datafunc.h"
#include "../data.h"

#include <string>

using namespace std;

class DwarfenManufacture : public QDialog
{
	Q_OBJECT
	private:
		QLabel * upLabel_;
		QLabel * downLabel_;
		QPushButton * okButton_;
		QPushButton * cancelButton_;
		QPushButton * messageButton_;
		QHBoxLayout * buttonsLayout_;
		QVBoxLayout * mainLayout_;
		DwarfenManufactureWidgetUp * upWidget_;
		DwarfenManufactureWidgetDown * downWidget_;
		string message_;
	public:
		DwarfenManufacture (const vector <DwarfenManufactureItem> &, const vector <DwarfenManufactureItem> &);
		~DwarfenManufacture ();
		string packet ();
		string message () const;
	private slots:
		void slotMessage ();
};

#endif
