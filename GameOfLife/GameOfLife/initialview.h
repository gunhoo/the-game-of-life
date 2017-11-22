#ifndef INITIALVIEW_H
#define INITIALVIEW_H

#include <QDialog>
#include "ui_initialview.h"

class InitialView : public QDialog
{
	Q_OBJECT

public:
	InitialView(QWidget *parent = 0);
	~InitialView();
	bool InitialView::initialViewFinished(QString& fileName);

private slots:
	void newButtonClicked();
	void openButtonClicked();

private:
	Ui::InitialView ui;
	QString fileName;
};

#endif // INITIALVIEW_H
