#ifndef GAMEOFLIFEVIEW_H
#define GAMEOFLIFEVIEW_H

#include <QtWidgets/QMainWindow>
#include "ui_gameoflifeview.h"
#include "initialview.h"
#include "GameOfLife.h"

class GameOfLifeView : public QMainWindow
{
	Q_OBJECT

public:
	GameOfLifeView(QWidget *parent = 0);
	void GameOfLifeView::initialize();
	~GameOfLifeView();

private slots:
	void newButtonClicked();
	void openButtonClicked();
	void saveButtonClicked();
	void saveAsButtonClicked();
	void quitButtonClicked();

private:
	Ui::GameOfLifeViewClass ui;
	InitialView *initialView;
	GameOfLife *gameOfLife;

	void GameOfLifeView::loadFile(QString fileName);
};

#endif // GAMEOFLIFEVIEW_H
