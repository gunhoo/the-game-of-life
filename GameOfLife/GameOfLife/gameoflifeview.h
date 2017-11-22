#ifndef GAMEOFLIFEVIEW_H
#define GAMEOFLIFEVIEW_H

#include <QtWidgets/QMainWindow>
#include "ui_gameoflifeview.h"

class GameOfLifeView : public QMainWindow
{
	Q_OBJECT

public:
	GameOfLifeView(QWidget *parent = 0);
	~GameOfLifeView();

private:
	Ui::GameOfLifeViewClass ui;
};

#endif // GAMEOFLIFEVIEW_H
