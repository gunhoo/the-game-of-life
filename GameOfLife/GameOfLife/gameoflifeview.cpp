#include "gameoflifeview.h"
#include <QtWidgets\qmessagebox.h>
#include <QtWidgets\qfiledialog.h>
#include <qaction.h>

GameOfLifeView::GameOfLifeView(QWidget *parent)
	: QMainWindow(parent),
	ui(new Ui::GameOfLifeViewClass),
	game(new GameWidget(this))
{
	ui->setupUi(this);

	// initialize GameOfLife
	gameOfLife = new GameOfLife();

	connect(ui->actionNew, SIGNAL(triggered()), this, SLOT(newButtonClicked()));
	connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(openButtonClicked()));
	connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(saveButtonClicked()));
	connect(ui->actionSave_As, SIGNAL(triggered()), this, SLOT(saveAsButtonClicked()));
	connect(ui->actionQuit, SIGNAL(triggered()), this, SLOT(quitButtonClicked()));

	connect(ui->clearButton, SIGNAL(clicked()), game, SLOT(clear()));

	ui->gameLayout->addWidget(game);
}

GameOfLifeView::~GameOfLifeView()
{
	delete initialView;
	delete gameOfLife;
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
			this->loadFile(fileName);
		}
		else {
			// new file
		}
	}
}

void GameOfLifeView::newButtonClicked()
{
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
		this->loadFile(fileName);
	}
}

void GameOfLifeView::saveButtonClicked()
{

}

void GameOfLifeView::saveAsButtonClicked() 
{

}

void GameOfLifeView::quitButtonClicked()
{
	this->close();
}

void GameOfLifeView::loadFile(QString fileName)
{
	
	if (gameOfLife->load(fileName.toStdString()) != -11) {
		QMessageBox warningBox;
		warningBox.setText("Load Error!");
		warningBox.setStandardButtons(QMessageBox::Ok);
		warningBox.setDefaultButton(QMessageBox::Ok);

		warningBox.exec();
	}
	else
	{
		QMessageBox warningBox;
		warningBox.setText("Load Success!");
		warningBox.setStandardButtons(QMessageBox::Ok);
		warningBox.setDefaultButton(QMessageBox::Ok);

		warningBox.exec();
	}
}
