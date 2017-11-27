#include "gameoflifeview.h"
#include <QtWidgets\qmessagebox.h>
#include <QtWidgets\qfiledialog.h>
#include <qaction.h>
#include <QTextStream>
#include <Windows.h>
#include <thread>
#include <time.h>

GameOfLifeView::GameOfLifeView(QWidget *parent)
	: QMainWindow(parent),
	ui(new Ui::GameOfLifeViewClass),
	game(new GameWidget(this))
{
	ui->setupUi(this);

	game->setParentView(this);

	this->timer = new QTimer(this);

	connect(ui->actionNew, SIGNAL(triggered()), this, SLOT(newButtonClicked()));
	connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(openButtonClicked()));
	connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(saveButtonClicked()));
	connect(ui->actionSave_As, SIGNAL(triggered()), this, SLOT(saveAsButtonClicked()));
	connect(ui->actionSave_Result, SIGNAL(triggered()), this, SLOT(saveResultButtonClicked()));
	connect(ui->actionQuit, SIGNAL(triggered()), this, SLOT(quitButtonClicked()));
	
	connect(ui->rowSpinBox, SIGNAL(valueChanged(int)), this, SLOT(setCellNumberRow(int)));
	connect(ui->colSpinBox, SIGNAL(valueChanged(int)), this, SLOT(setCellNumberCol(int)));

	connect(ui->runButton, SIGNAL(clicked()), this, SLOT(runButtonClicked()));
	connect(ui->stopButton, SIGNAL(clicked()), this, SLOT(stopButtonClicked()));
	connect(ui->nextButton, SIGNAL(clicked()), this, SLOT(nextButtonClicked()));
	
	connect(ui->resizeButton, SIGNAL(clicked()), this, SLOT(resizeButtonClicked()));
	connect(ui->clearButton, SIGNAL(clicked()), this, SLOT(clearButtonClicked()));

	connect(this->timer, SIGNAL(timeout()), this, SLOT(getNextGeneration()));

	ui->gameLayout->addWidget(game);
	
}


GameOfLifeView::~GameOfLifeView()
{
	delete initialView;
}

void GameOfLifeView::setGameOfLifeController(GameOfLife& controller)
{
	this->controller = &controller;
}

void GameOfLifeView::initialize() 
{
	initialView = new InitialView(this);
	initialView->setModal(true);

	// show initialView
	if (initialView->exec() == QDialog::Accepted)
	{
		QString fileName;

		// true : open file, false : new file
		if (initialView->initialViewFinished(fileName))
		{
			if (this->loadFile(fileName) != -11) {
				game->setUniverseWithGrid(controller->getPattern());
			}
			else {
				this->newButtonClicked();
			}
		}
		else {
			controller->newFile();
		}
	}
}

void GameOfLifeView::newButtonClicked()
{
	controller->newFile();
}

void GameOfLifeView::openButtonClicked()
{
	QString fileName = QFileDialog::getOpenFileName(this,
		tr("Open game file"), "./", tr("Game file (*.txt)"));

	if (fileName == NULL)
	{
		QMessageBox warningBox;
		warningBox.setText("Load error !!");
		warningBox.setStandardButtons(QMessageBox::Ok);
		warningBox.setDefaultButton(QMessageBox::Ok);

		warningBox.exec();
	}
	else {
		if (this->loadFile(fileName) != -11) {
			game->setUniverseWithGrid(controller->getPattern());
		}
		else {
			this->newButtonClicked();
		}
		
	}
}

void GameOfLifeView::saveButtonClicked()
{
	if (controller->saveFile() == -1)
	{
		this->saveFileWithFileDialog();
	}
}

void GameOfLifeView::saveAsButtonClicked() 
{
	this->saveFileWithFileDialog();
}

void GameOfLifeView::saveResultButtonClicked()
{
	QString fileName = QFileDialog::getSaveFileName(this,
		tr("Save Game Of Life result file"), "",
		tr("txt file (*.txt)"));

	controller->saveResultFile(fileName.toStdString());
}

void GameOfLifeView::quitButtonClicked()
{
	this->close();
}

void GameOfLifeView::runButtonClicked()
{
	if (!timer->isActive()) {
		timer->start(100);
	}	
}

void GameOfLifeView::stopButtonClicked()
{
	if (timer->isActive()) {
		timer->stop();
	}
}

void GameOfLifeView::nextButtonClicked()
{
	this->getNextGeneration();
}

void GameOfLifeView::resizeButtonClicked()
{
	controller->resizeGrid(
		this->universeRow, 
		this->universeCol);

	game->setCellSize(
		this->universeRow, 
		this->universeCol);

}

void GameOfLifeView::clearButtonClicked()
{
	this->controller->clear();
	this->game->clear();
}

int GameOfLifeView::loadFile(QString fileName)
{
	QMessageBox warningBox;

	int errorCode = controller->loadFile(fileName.toStdString());
	if (errorCode == -11) {

		this->controller->clear();
		this->game->clear();
		
		warningBox.setText("Load Error!");
		warningBox.setStandardButtons(QMessageBox::Ok);
		warningBox.setDefaultButton(QMessageBox::Ok);
	}
	else
	{
		QMessageBox warningBox;
		warningBox.setText("Load Success!");
		warningBox.setStandardButtons(QMessageBox::Ok);
		warningBox.setDefaultButton(QMessageBox::Ok);
	}

	warningBox.exec();
	return errorCode;
}

void GameOfLifeView::saveFileWithFileDialog()
{
	QString fileName = QFileDialog::getSaveFileName(this,
		tr("Save Game Of Life file"), "",
		tr("txt file (*.txt)"));

	controller->saveAsFile(fileName.toStdString());
}

void GameOfLifeView::getNextGeneration()
{
	grid = controller->next();
	game->setUniverseWithGrid(grid);
}

void GameOfLifeView::setCellNumberRow(int row)
{
	this->universeRow = row;
}

void GameOfLifeView::setCellNumberCol(int col)
{
	this->universeCol = col;
}

void GameOfLifeView::setMousePosition(int x, int y)
{
	this->controller->setByClick(y - 1, x - 1);
}