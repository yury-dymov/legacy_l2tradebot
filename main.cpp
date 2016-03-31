#include <QApplication>
#include "l2bot.h"

int main (int argc, char ** argv)
{
	QTextCodec * codec = QTextCodec::codecForName ("windows-1251");
	QTextCodec::setCodecForCStrings (codec);
	QApplication app (argc, argv);
	L2Bot a;
	return app.exec ();
}

