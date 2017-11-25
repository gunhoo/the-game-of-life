#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QColor>
#include <QWidget>
#include "initialview.h"
#include "GameOfLife.h"

class GameWidget : public QWidget
{
	Q_OBJECT
public:
	explicit GameWidget(QWidget *parent = 0);
	~GameWidget();

	void GameWidget::setUniverseWithGrid(vector< vector<bool> > grid);


protected:
	void paintEvent(QPaintEvent *);
	void mousePressEvent(QMouseEvent *e);
	//void mouseMoveEvent(QMouseEvent *e);

signals:
	//when one of the cell has been changed,emit this signal to lock the universeSize
	void environmentChanged(bool ok);
	//when game is over or clear is called,emit it to unlock the universeSize


public slots:
	void clear(); // clear

private slots:
	void paintGrid(QPainter &p);
	void paintUniverse(QPainter &p);

private:
	QColor m_masterColor;
	bool* universe; // map
	int universeSizeX;
	int universeSizeY;

	void resetUniverse(); // reset the size of universe

};

#endif // GAMEWIDGET_H