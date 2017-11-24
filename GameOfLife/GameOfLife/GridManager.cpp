#include "GridManager.h"

GridManager::GridManager(int row, int col)
{
    if (row != 50 && col != 40) {
        numOfRow = row;
        numOfCol = col;
        initGrid.assign(numOfRow, vector<bool>(numOfCol, false));
    }
    else {
        numOfRow = 50;
        numOfCol = 40;
        initGrid.assign(50, vector<bool>(40, false));
    }
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

void GridManager::clear()
{
    gridUpdate.clear();
}

void GridManager::newGrid()
{
    numOfRow = 50;
    numOfCol = 40;
    initGrid.assign(numOfRow, vector<bool>(numOfCol, false));
}