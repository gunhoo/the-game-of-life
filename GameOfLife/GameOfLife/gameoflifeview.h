#ifndef GAMEOFLIFEVIEW_H
#define GAMEOFLIFEVIEW_H

#include <QtWidgets/QMainWindow>
#include "ui_gameoflifeview.h"
#include "initialview.h"
#include "GameOfLife.h"
#include "gamewidget.h"
#include <QMouseEvent>
#include <QTimer>

class GameWidget;

class GameOfLifeView : public QMainWindow
{
	Q_OBJECT

public:
	GameOfLifeView(QWidget *parent = 0);
	void GameOfLifeView::initialize();
	~GameOfLifeView();
	void setGameOfLifeController(GameOfLife& controller);
	void setMousePosition(int x, int y);
	int universeRow;
	int universeCol;

private slots:
	void newButtonClicked();
	void openButtonClicked();
	void saveButtonClicked();
	void saveAsButtonClicked();
	void saveResultButtonClicked();
	void quitButtonClicked();
	void runButtonClicked();
	void stopButtonClicked();
	void nextButtonClicked();
	void resizeButtonClicked();
	void clearButtonClicked();
	void setCellNumberRow(int row);
	void setCellNumberCol(int col);
	void getNextGeneration();

private:
	void GameOfLifeView::newFile();
	int loadFile(QString fileName);
	void saveFileWithFileDialog();
	void clear();
	Ui::GameOfLifeViewClass *ui;
	InitialView *initialView;
	GameOfLife *controller;
	GameWidget *game;
	vector< vector<bool> > grid;
	QTimer* timer;
	bool isStop;
};

#endif // GAMEOFLIFEVIEW_H
