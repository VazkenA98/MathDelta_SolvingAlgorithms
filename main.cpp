#include "Delta_QT.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Delta_QT w;
	w.show();
	return a.exec();
}
