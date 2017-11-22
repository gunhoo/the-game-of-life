#include "gameoflifeview.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	GameOfLifeView w;
	w.show();
	return a.exec();
}
