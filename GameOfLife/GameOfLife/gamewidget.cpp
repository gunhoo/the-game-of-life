#include "gamewidget.h"
#include <QPainter>
#include <QMouseEvent>
#include "initialview.h"
#include "GameOfLife.h"

GameWidget::GameWidget(QWidget *parent) :
QWidget(parent),
universeSizeRow(50),
universeSizeCol(40)
{
	m_masterColor = "#000";
	universe = new bool[(universeSizeRow + 2) * (universeSizeCol + 2)];
	next = new bool[(universeSizeRow + 2) * (universeSizeCol + 2)];
	memset(universe, false, sizeof(bool)*(universeSizeRow + 2) * (universeSizeCol + 2));
	memset(next, false, sizeof(bool)*(universeSizeRow + 2) * (universeSizeCol + 2));

	connect(this, SIGNAL(mousePressEvent(QMouseEvent*)),
		this->parent(), SLOT(setMousePosition(QMouseEvent*)));
}

GameWidget::~GameWidget()
{
	delete[] next;
	delete[] universe;
}

void GameWidget::setParentView(GameOfLifeView* parentView)
{
	this->_parentView = parentView;
}

void GameWidget::setUniverseWithGrid(const vector< vector<bool> >& grid) {
	
		int row = grid.size();
		int col = grid[0].size();
	
		if (row != this->universeSizeRow || col != this->universeSizeCol) {
			this->universeSizeCol = col;
			this->universeSizeRow = row;
			this->setCellNumber();
		}
	
		for (int i = 0; i < universeSizeRow; i++) {
			for (int j = 0; j < universeSizeCol; j++) {
				universe[(i + 1) * universeSizeCol + (j + 1)] =
					grid[i][j];
			}
		}

		update();
	
}

void GameWidget::clear()
{
	for (int k = 1; k <= universeSizeCol; k++) {
		for (int j = 1; j <= universeSizeRow; j++) {
			universe[k*universeSizeCol + j] = false;
		}
	}
	gameEnds(true);
	update();
}

void GameWidget::setCellNumber()
{
	resetUniverse();
	update();
}

void GameWidget::setCellSize(const int &row, const int &col)
{
	this->universeSizeRow = row;
	this->universeSizeCol = col;

	this->setCellNumber();

}


void GameWidget::resetUniverse()
{
	delete[] universe;
	delete[] next;
	universe = new bool[(universeSizeRow + 2) * (universeSizeCol + 2)];
	next = new bool[(universeSizeRow + 2) * (universeSizeCol + 2)];
	memset(universe, false, sizeof(bool)*(universeSizeRow + 2) * (universeSizeCol + 2));
	memset(next, false, sizeof(bool)*(universeSizeRow + 2) * (universeSizeCol + 2));
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
	double cellHeight = (double)height() / universeSizeRow;
	double cellWidth = (double)width() / universeSizeCol;
	int j = floor(e->x() / cellWidth)  + 1;//col
	int k = floor(e->y() / cellHeight) + 1;//row

	this->_parentView->setMousePosition(j, k);

	universe[k*universeSizeCol + j] = !universe[k*universeSizeCol + j];
	update();
	
}

/* mouseMoveEvent�� ���������� update������ ����ó������ ������ �ּ�ó�� �Ͽ���
void GameWidget::mouseMoveEvent(QMouseEvent *e)
{
	double cellWidth = (double)width() / universeSizeCol;
	double cellHeight = (double)height() / universeSizeRow;
	int k = floor(e->y() / cellHeight) + 1;
	int j = floor(e->x() / cellWidth) + 1;
	int currentLocation = k*universeSizeCol + j;
	if (!universe[currentLocation]){                //if current cell is empty,fill in it
		universe[currentLocation] = !universe[currentLocation];
		update();
	}
}
*/

void GameWidget::paintGrid(QPainter &p)
{
	QRect borders(0, 0, width() - 1, height() - 1); // borders of the universe
	QColor gridColor = m_masterColor; // color of the grid
	gridColor.setAlpha(10); // must be lighter than main color
	p.setPen(gridColor);
	double cellWidth = (double)width() / universeSizeCol; // width of the widget / number of cells at one row
	for (double k = cellWidth; k <= width(); k += cellWidth)
		p.drawLine(k, 0, k, height());
	double cellHeight = (double)height() / universeSizeRow; // height of the widget / number of cells at one row
	for (double k = cellHeight; k <= height(); k += cellHeight)
		p.drawLine(0, k, width(), k);
	p.drawRect(borders);
}

void GameWidget::paintUniverse(QPainter &p)
{
	double cellWidth = (double)width() / universeSizeCol;
	double cellHeight = (double)height() / universeSizeRow;
	for (int k = 1; k <= universeSizeRow; k++) {
		for (int j = 1; j <= universeSizeCol; j++) {
			if (universe[k*universeSizeCol + j] == true) { // if there is any sense to paint it
				qreal left = (qreal)(cellWidth*j - cellWidth); // margin from left
				qreal top = (qreal)(cellHeight*k - cellHeight); // margin from top
				QRectF r(left, top, (qreal)cellWidth, (qreal)cellHeight);
				p.fillRect(r, QBrush(m_masterColor)); // fill cell with brush of main color
			}
		}
	}
}

double GameWidget::getCellHeight()
{
	return (double)height();
}

double GameWidget::getCellWidth()
{
	return (double)width();
}