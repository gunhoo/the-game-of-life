#include "initialview.h"
#include <QtWidgets\QFileDialog>
#include <QtWidgets\QMessageBox>

InitialView::InitialView(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.newButton, SIGNAL(released()), this, SLOT(newButtonClicked()));
	connect(ui.openButton, SIGNAL(released()), this, SLOT(openButtonClicked()));
}

InitialView::~InitialView()
{

}

bool InitialView::initialViewFinished(QString& fileName) {
	if (this->fileName != NULL) 
	{
		fileName = this->fileName;
		return true;
	}
	
	return false;
}

void InitialView::newButtonClicked() {
	this->close();
	this->setResult(QDialog::Accepted);
}

void InitialView::openButtonClicked() {
	QString tempFileName = QFileDialog::getOpenFileName(this,
		tr("Open game file"), "./", tr("Game file (*.txt)"));

	if (tempFileName == NULL) 
	{
		QMessageBox warningBox;
		warningBox.setText("Load error !!");
		warningBox.setStandardButtons(QMessageBox::Ok);
		warningBox.setDefaultButton(QMessageBox::Ok);

		warningBox.exec();
	}
	else 
	{
		this->fileName = tempFileName;

		// close the initialView
		this->close();

		// emit event of closing initial view to handle in GameOfLifeView
		this->setResult(QDialog::Accepted);
	}
}


