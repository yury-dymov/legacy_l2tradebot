#include "newchar.h"

NewChar::NewChar (const vector <CharTemplate> & chars)
{
	map <int, QString> className;
	className [0] = "Human Fighter";
	className [10] = "Human Mystic";
	className [18] = "Elven Fighter";
	className [25] = "Elven Mystic";
	className [31] = "Dark Elven Fighter";
	className [38] = "Dark Elven Mystic";
	className [44] = "Orc Fighter";
	className [49] = "Orc Mystic";
	className [53] = "Dwarven Fighter";
	sexBox_ = new QComboBox;
	sexBox_->addItem ("Male");
	sexBox_->addItem ("Female");
	faceBox_ = new QComboBox;
	faceBox_->addItem ("A");
	faceBox_->addItem ("B");
	faceBox_->addItem ("C");
	hairBox_ = new QComboBox;
	hairBox_->addItem ("A");
	hairBox_->addItem ("B");
	hairBox_->addItem ("C");
	hairBox_->addItem ("D");
	styleBox_ = new QComboBox;
	styleBox_->addItem ("A");
	styleBox_->addItem ("B");
	styleBox_->addItem ("C");
	styleBox_->addItem ("D");
	styleBox_->addItem ("E");
	templateBox_ = new QComboBox;
	for (unsigned int i = 0; i < chars.size (); ++i)
	{
		templateBox_->addItem (className [chars[i].classId]);
		classId_.push_back (chars[i].classId);
	}
	sexLabel_ = new QLabel ("Sex: ");
	faceLabel_ = new QLabel ("Face: ");
	hairLabel_ = new QLabel ("Hair Color: ");
	styleLabel_ = new QLabel ("Hair Style: ");
	nameLabel_ = new QLabel ("Char Name: ");
	templateLabel_ = new QLabel ("Template: ");
	okButton_ = new QPushButton ("Ok");
	connect (okButton_, SIGNAL (pressed ()), SLOT (accept ()));
	cancelButton_ = new QPushButton ("Cancel");
	connect (cancelButton_, SIGNAL (pressed ()), SLOT (reject ()));
	nameEdit_ = new QLineEdit;
	nameEdit_->setMaxLength (16);
	la_ = new QGridLayout;
	la_->addWidget (nameLabel_, 0, 0);
	la_->addWidget (nameEdit_, 0, 1);
	la_->addWidget (templateLabel_, 1, 0);
	la_->addWidget (templateBox_, 1, 1);
	la_->addWidget (sexLabel_, 2, 0);
	la_->addWidget (sexBox_, 2, 1);
	la_->addWidget (styleLabel_, 3, 0);
	la_->addWidget (styleBox_, 3, 1);
	la_->addWidget (hairLabel_, 4, 0);
	la_->addWidget (hairBox_, 4, 1);
	la_->addWidget (faceLabel_, 5, 0);
	la_->addWidget (faceBox_, 5, 1);
	la_->addWidget (okButton_, 6, 0);
	la_->addWidget (cancelButton_, 6, 1);
	this->setLayout (la_);
	this->setWindowTitle ("Create Char");
	this->move (450, 250);
	this->setFixedSize (250, 270);
	this->show ();
}

NewChar::~NewChar ()
{
	delete templateLabel_;
	delete templateBox_;
	delete nameLabel_;
	delete nameEdit_;
	delete sexLabel_;
	delete sexBox_;
	delete styleLabel_;
	delete styleBox_;
	delete hairLabel_;
	delete hairBox_;
	delete faceLabel_;
	delete faceBox_;
	delete cancelButton_;
	delete okButton_;
	delete la_;
}

int NewChar::classId () const
{
	return classId_ [templateBox_->currentIndex ()];
}

int NewChar::sex () const
{
	return sexBox_->currentIndex ();
}

int NewChar::face () const
{
	return faceBox_->currentIndex ();
}

int NewChar::style () const
{
	return styleBox_->currentIndex ();
}

int NewChar::hair () const
{
	return hairBox_->currentIndex ();
}

string NewChar::name () const
{
	return nameEdit_->text ().toStdString ();
}
