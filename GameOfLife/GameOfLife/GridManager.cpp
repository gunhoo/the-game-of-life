#include "GridManager.h"

GridManager::GridManager()
{
        numOfRow = 50;
        numOfCol = 40;
        initGrid.assign(50, vector<bool>(40, false));
}

vector< vector<bool> > & GridManager::getInitGrid()
{
    return initGrid;
}

int GridManager::getNumOfRow()
{
    return numOfRow;
}

int GridManager::getNumOfCol()
{
    return numOfCol;
}

void GridManager::setNumOfRow(unsigned int row)
{
    numOfRow = row;
}

void GridManager::setNumOfCol(unsigned int col)
{
    numOfCol = col;
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
