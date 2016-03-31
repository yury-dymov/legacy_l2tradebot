#ifndef __NEW_CHAR__
#define __NEW_CHAR__

#include <QDialog>
#include <QComboBox>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QGridLayout>
#include <QString>

#include "../game_struct.h"

#include <string>
#include <map>
#include <vector>

using namespace std;

class NewChar : public QDialog
{
	private:
		QComboBox * sexBox_;
		QComboBox * styleBox_;
		QComboBox * hairBox_;
		QComboBox * faceBox_;
		QComboBox * templateBox_;
		QLineEdit * nameEdit_;
		QLabel * nameLabel_;
		QLabel * sexLabel_;
		QLabel * styleLabel_;
		QLabel * hairLabel_;
		QLabel * faceLabel_;
		QLabel * templateLabel_;
		QPushButton * okButton_;
		QPushButton * cancelButton_;
		QGridLayout * la_;
		vector <int> classId_;
	public:
		int style () const;
		int hair () const;
		int sex () const;
		int face () const;
		int classId () const;
		string name () const;
		NewChar (const vector <CharTemplate> &);
		~NewChar ();
};

#endif
