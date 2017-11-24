#include "gamewidget.h"
#include <QPainter>
#include <QMouseEvent>
#include "initialview.h"
#include "GameOfLife.h"

GameWidget::GameWidget(QWidget *parent) :
QWidget(parent),
universeSizeX(50),
universeSizeY(40)
{
	m_masterColor = "#000";
	universe = new bool[(universeSizeX + 2) * (universeSizeY + 2)];
	memset(universe, false, sizeof(bool)*(universeSizeX + 2) * (universeSizeY + 2));

}

GameWidget::~GameWidget()
{
	delete[] universe;
}


void GameWidget::clear()
{
	for (int k = 1; k <= universeSizeX; k++) {
		for (int j = 1; j <= universeSizeY; j++) {
			universe[k*universeSizeX + j] = false;
		}
	}
	update();
}

void GameWidget::resetUniverse()
{
	delete[] universe;
	universe = new bool[(universeSizeX + 2) * (universeSizeY + 2)];
	memset(universe, false, sizeof(bool)*(universeSizeX + 2) * (universeSizeY + 2));
}


void GameWidget::paintEvent(QPaintEvent *)
{
	QPainter p(this);
	paintGrid(p);
	paintUniverse(p);
}

void GameWidget::mousePressEvent(QMouseEvent *e)
{
	emit environmentChanged(true);
	double cellWidth = (double)width() / universeSizeX;
	double cellHeight = (double)height() / universeSizeY;
	int k = floor(e->y() / cellHeight) + 1;
	int j = floor(e->x() / cellWidth) + 1;
	universe[k*universeSizeX + j] = !universe[k*universeSizeX + j];
	update();
}
/*
void GameWidget::mouseMoveEvent(QMouseEvent *e)
{
	double cellWidth = (double)width() / universeSizeX;
	double cellHeight = (double)height() / universeSizeY;
	int k = floor(e->y() / cellHeight) + 1;
	int j = floor(e->x() / cellWidth) + 1;
	int currentLocation = k*universeSizeX + j;
	if (!universe[currentLocation]){                //if current cell is empty,fill in it
		universe[currentLocation] = !universe[currentLocation];
		update();
	}
}*/

void GameWidget::paintGrid(QPainter &p)
{
	QRect borders(0, 0, width() - 1, height() - 1); // borders of the universe
	QColor gridColor = m_masterColor; // color of the grid
	gridColor.setAlpha(10); // must be lighter than main color
	p.setPen(gridColor);
	double cellWidth = (double)width() / universeSizeX; // width of the widget / number of cells at one row
	for (double k = cellWidth; k <= width(); k += cellWidth)
		p.drawLine(k, 0, k, height());
	double cellHeight = (double)height() / universeSizeY; // height of the widget / number of cells at one row
	for (double k = cellHeight; k <= height(); k += cellHeight)
		p.drawLine(0, k, width(), k);
	p.drawRect(borders);
}

void GameWidget::paintUniverse(QPainter &p)
{
	double cellWidth = (double)width() / universeSizeX;
	double cellHeight = (double)height() / universeSizeY;
	for (int k = 1; k <= universeSizeX; k++) {
		for (int j = 1; j <= universeSizeY; j++) {
			if (universe[k*universeSizeX + j] == true) { // if there is any sense to paint it
				qreal left = (qreal)(cellWidth*j - cellWidth); // margin from left
				qreal top = (qreal)(cellHeight*k - cellHeight); // margin from top
				QRectF r(left, top, (qreal)cellWidth, (qreal)cellHeight);
				p.fillRect(r, QBrush(m_masterColor)); // fill cell with brush of main color
			}
		}
	}
}