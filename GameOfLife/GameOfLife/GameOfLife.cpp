#include "GameOfLife.h"

void GameOfLife::updateGrid()
{
	gridPart.updateGrid();
}

const vector< vector<bool> >& GameOfLife::getGrid()
{
	return gridPart.getGrid();
}

int GameOfLife::load(string fileName)
{
	int check = loadPart.loadFile(fileName);
	if (check == -11)
		return -11;

	gridPart.resizeGrid(loadPart.getRow(), loadPart.getCol());
	gridPart.readFromOut(loadPart.getGrid());
}

int GameOfLife::save(string fileName)
{
	int check = savePart.saveFile(fileName, gridPart.getGrid(), gridPart.getRow(), gridPart.getColumn());
	if (check == -22)
		return -22;
	else
		return 0;
}

void GameOfLife::resizeGrid(int row, int col)
{
	gridPart.resizeGrid(row, col);
}

void GameOfLife::readFromOut(const vector< vector<bool> > &grid)
{
	gridPart.readFromOut(grid);
}

int GameOfLife::getRow()
{
	return gridPart.getRow();
}

int GameOfLife::getCol()
{
	return gridPart.getColumn();
}