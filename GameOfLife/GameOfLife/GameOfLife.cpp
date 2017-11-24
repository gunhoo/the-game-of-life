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
	int check = .saveFile(fileName, gridPart.getGrid(), gridPart.getRow(), gridPart.getColumn());
    if (check == -22)
        return -22;
    else
        return 0;
}

void GameOfLife::clear()
{
    gridManager.clear();
}

void GameOfLife::resizeGrid(unsigned int row, unsigned int col)
{
    gridManager.resize(row, col);
}

void GameOfLife::readFromOut(const vector< vector<bool> > &grid)
{
    gridManager.readFromOut(grid);
}

unsigned int GameOfLife::getNumOfRow()
{
    return gridManager.getNumOfRow();
}

unsigned int GameOfLife::getNumOfCol()
{
    return gridManager.getNumOfCol();
}