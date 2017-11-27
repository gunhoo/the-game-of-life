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
				grid = controller->getPattern();
				ui->rowSpinBox->setValue(grid.size());
				ui->colSpinBox->setValue(grid[0].size());
				game->setUniverseWithGrid(grid);
			}
			else {
				this->newButtonClicked();
			}
		}
		else {
			this->newFile();
		}
	}
}

void GameOfLifeView::newButtonClicked()
{
	this->newFile();
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
			grid = controller->getPattern();
			ui->rowSpinBox->setValue(grid.size());
			ui->colSpinBox->setValue(grid[0].size());
			game->setUniverseWithGrid(grid);
		}
		else {
			this->newFile();
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
	ui->stopButton->setEnabled(true);
	ui->runButton->setEnabled(false);
	ui->nextButton->setEnabled(false);
	ui->clearButton->setEnabled(false);
	ui->resizeButton->setEnabled(false);

	ui->rowSpinBox->setEnabled(false);
	ui->colSpinBox->setEnabled(false);

	ui->actionNew->setEnabled(false);
	ui->actionOpen->setEnabled(false);
	ui->actionSave->setEnabled(false);
	ui->actionSave_As->setEnabled(false);
	ui->actionSave_Result->setEnabled(false);

	if (!timer->isActive()) {
		timer->start(150);
	}	
}

void GameOfLifeView::stopButtonClicked()
{
	if (timer->isActive()) {
		timer->stop();
	}

	ui->stopButton->setEnabled(false);
	ui->runButton->setEnabled(true);
	ui->nextButton->setEnabled(true);
	ui->clearButton->setEnabled(true);
	ui->resizeButton->setEnabled(true);

	ui->rowSpinBox->setEnabled(true);
	ui->colSpinBox->setEnabled(true);

	ui->actionNew->setEnabled(true);
	ui->actionOpen->setEnabled(true);
	ui->actionSave->setEnabled(true);
	ui->actionSave_As->setEnabled(true);
	ui->actionSave_Result->setEnabled(true);
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
	this->clear();
}

void GameOfLifeView::newFile()
{
	this->controller->newFile();
	this->universeRow = 50;
	this->universeCol = 40;
	this->ui->rowSpinBox->setValue(this->universeRow);
	this->ui->colSpinBox->setValue(this->universeCol);
	game->setCellSize(this->universeRow, this->universeCol);
	this->clear();
}

int GameOfLifeView::loadFile(QString fileName)
{
	QMessageBox warningBox;

	this->clear();

	int errorCode = controller->loadFile(fileName.toStdString());
	if (errorCode == -11) {
		warningBox.setText("Load Error!");
		warningBox.setStandardButtons(QMessageBox::Ok);
		warningBox.setDefaultButton(QMessageBox::Ok);
	}
	else
	{
		warningBox.setText("Load Success!");
		warningBox.setStandardButtons(QMessageBox::Ok);
		warningBox.setDefaultButton(QMessageBox::Ok);
	}

	warningBox.exec();
	return errorCode;
}

void GameOfLifeView::clear()
{
	this->controller->clear();
	this->game->clear();
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