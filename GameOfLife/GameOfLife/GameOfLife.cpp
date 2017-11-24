#include "GameOfLife.h"

void GameOfLife::updateGrid()
{
    gridPart.updateGrid();
}

const vector< vector<bool> >& GameOfLife::getGrid()
{
    return gridPart.getGrid();
}

const vector< vector<bool> >& GameOfLife::run()
{
    // need to finish the while loop and stop
    return gridManager.generateGrid();   
}

const vector< vector<bool> >& GameOfLife::next()
{
    return gridManager.generateGrid();
}

int GameOfLife::load(string fileName)
{
    int check = fileManager.load(fileName, gridManager.setInitGrid(), gridManager.setRow(), gridManager.setCol()); 
    if (check == -11)
        return -11;

    gridManager.resize(gridManager.getNumOfRow(), gridManager.getNumOfCol());
    gridManager.setGnrtGrid(gridManager.getSaveGrid());
}

int GameOfLife::save(string fileName)
{
	return fileManager.save(gridManager.getSaveGrid(), gridManager.getNumOfRow(), gridManager.getNumOfCol());
}

int GameOfLife::saveAs(string fileName)
{
    return fileManager.saveAs(fileName, gridManager.getSaveGrid(), gridManager.getNumOfRow(), gridManager.getNumOfCol());
}

void GameOfLife::saveResult(string fileName)
{
    fileManager.saveResult(fileName, gridManager.getPattern(), gridManager.getNumOfRow(), gridManager.getNumOfCol());
}

const vector<vector<bool> >& GameOfLife::clear()
{
    return gridManager.clear();
}

void GameOfLife::resizeGrid(unsigned int row, unsigned int col)
{
    gridManager.resize(row, col);
}
/*
void GameOfLife::readFromOut(const vector< vector<bool> > &grid)
{
    gridManager.readFromOut(grid);
}
*/

unsigned int GameOfLife::getNumOfRow()
{
    return gridManager.getNumOfRow();
}

unsigned int GameOfLife::getNumOfCol()
{
    return gridManager.getNumOfCol();
}