#include "GridManager.h"

GridManager::GridManager()
{
        numOfRow = 50;
        numOfCol = 40;
        initGrid.assign(50, vector<bool>(40, false));
}
/*
vector< vector<bool> >& GridManager::setInitGrid()
{
    return initGrid;
}
*/
void GridManager::setInitGrid(const vector< vector<bool> >& pattern, unsigned int row, unsigned int col)
{
    numOfRow = row;
    numOfCol = col;
    initGrid = pattern;
}

unsigned int& GridManager::rowRef()
{
    return gridUpdate.rowRef();
}

unsigned int& GridManager::colRef()
{
    return gridUpdate.colRef();
}

vector< vector<bool> >& GridManager::gridRef()
{
    return gridUpdate.gridRef();
}

const vector< vector<bool> >& GridManager::getSaveGrid()
{
    return initGrid;
}


unsigned int GridManager::getNumOfRow()
{
    return gridUpdate.getNumOfRow();
}

unsigned int GridManager::getNumOfCol()
{
    return gridUpdate.getNumOfCol();
}

void GridManager::resize(unsigned int row, unsigned int col)
{
    gridUpdate.resizeGrid(row, col);   
}

void GridManager::setTmpSize(unsigned int row, unsigned int col)
{
    gridUpdate.setTmpSize(row, col);
}

const vector< vector<bool> >& GridManager::clear()
{
    return gridUpdate.clear();
}

void GridManager::updateLivingList()
{
    gridUpdate.updateCurrLive();
}

void GridManager::newGrid()
{
    numOfRow = 50;
    numOfCol = 40;
    initGrid.assign(numOfRow, vector<bool>(numOfCol, false));
    gridUpdate.resizeGrid(50, 40);
}

const vector< vector<bool> >& GridManager::generateGrid()
{
    return gridUpdate.updateGrid();
}

const vector< vector<bool> >& GridManager::getPattern()
{
    return gridUpdate.getPattern();
}

void GridManager::setByClick(unsigned int row, unsigned  int col)
{
    gridUpdate.changeStatus(row, col);
}
