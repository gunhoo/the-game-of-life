#include "GridManager.h"

GridManager::GridManager()
{
        numOfRow = 50;
        numOfCol = 40;
        initGrid.assign(50, vector<bool>(40, false));
}

void GridManager::setInitGrid(const vector< vector<bool> >& input, unsigned int row, unsigned int col)
{
    initGrid = input;
    numOfRow = row;
    numOfCol = col;
}

int GridManager::getNumOfRow()
{
    return numOfRow;
}

int GridManager::getNumOfCol()
{
    return numOfCol;
}

const vector< vector<bool> >& GridManager::clear()
{
    return gridUpdate.clear();
}

void GridManager::newGrid()
{
    numOfRow = 50;
    numOfCol = 40;
    initGrid.assign(numOfRow, vector<bool>(numOfCol, false));
}

const vector< vector<bool> >& GridManager::generateGrid()
{
    return gridUpdate.updateGrid();
}
