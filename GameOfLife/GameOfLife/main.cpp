#include "gameoflifeview.h"
#include "initialview.h"
#include "GameOfLife.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	GameOfLifeView gameOfLifeView;
	gameOfLifeView.showNormal();
	gameOfLifeView.initialize();

	return app.exec();
}
