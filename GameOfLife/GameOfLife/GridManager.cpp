#include "GridManager.h"

GridManager::GridManager()
{
        numOfRow = 50;
        numOfCol = 40;
        initGrid.assign(50, vector<bool>(40, false));
}

vector< vector<bool> >& GridManager::setInitGrid()
{
    return initGrid;
}

unsigned int& GridManager::setRow()
{
    return numOfRow;
}

unsigned int& GridManager::setCol()
{
    return numOfCol;
}


const vector< vector<bool> >& GridManager::getSaveGrid()
{
    return initGrid;
}

unsigned int GridManager::getNumOfRow()
{
    return numOfRow;
}

unsigned int GridManager::getNumOfCol()
{
    return numOfCol;
}

void GridManager::resize(unsigned int row, unsigned int col)
{
    gridUpdate.resizeGrid(row, col);   
}

const vector< vector<bool> >& GridManager::clear()
{
    return gridUpdate.clear();
}

void GridManager::setGnrtGrid(const vector< vector<bool> >& grid)
{
    gridUpdate.setGnrtGrid(grid);
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

void GridManager::setByClick(unsigned int row, unsigned  int col, vector< vector<bool> >& grid)
{
    if (grid[row][col])
        grid[row][col] = false;
    else
        gir[row][col] = true;
    
    gridUpdate.changeStatus(row, col);
}
