#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QColor>
#include <QWidget>
#include "initialview.h"
#include "GameOfLife.h"
#include "gameoflifeview.h"

class GameOfLifeView;

class GameWidget : public QWidget
{
	Q_OBJECT
public:
	explicit GameWidget(QWidget *parent = 0);
	~GameWidget();
	void GameWidget::setUniverseWithGrid(const vector< vector<bool> >& grid);
	void setCellSize(const int &row, const int &col);
	void setParentView(GameOfLifeView* parentView);
	double getCellHeight();
	double getCellWidth();

protected:
	void paintEvent(QPaintEvent *);
	void mousePressEvent(QMouseEvent *e);

signals:
	//when one of the cell has been changed,emit this signal to lock the universeSize
	void environmentChanged(bool ok);
	//when game is over or clear is called,emit it to unlock the universeSize
	void gameEnds(bool ok);

	public slots:
	void setCellNumber();
	void clear(); // clear

private slots:
	void paintGrid(QPainter &p);
	void paintUniverse(QPainter &p);

private:
	QColor m_masterColor;
	bool* universe; // map
	bool* next;
	int universeSizeRow;
	int universeSizeCol;
	void resetUniverse();// reset the size of universe
	GameOfLifeView* _parentView;
};

#endif // GAMEWIDGET_H