#include "gameoflifeview.h"
#include "initialview.h"
#include "GameOfLife.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	GameOfLife gameOfLifeController;
	GameOfLifeView gameOfLifeView;
	gameOfLifeView.setGameOfLifeController(gameOfLifeController);
	gameOfLifeView.showNormal();
	gameOfLifeView.initialize();

	return app.exec();
}
