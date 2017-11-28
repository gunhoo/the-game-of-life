#include "GameOfLife.h"

const vector< vector<bool> >& GameOfLife::run()
{
    // need to finish the while loop and stop
    return gridManager.generateGrid();   
}

const vector< vector<bool> >& GameOfLife::next()
{
    
    if (!notFstRun)
        gridManager.setInitGrid(gridManager.getPattern(), gridManager.getNumOfRow(), gridManager.getNumOfCol());
    return gridManager.generateGrid();

}

const vector< vector<bool> >& GameOfLife::newFile()
{
	gridManager.newGrid();
    fileManager.initName();

    notFstRun = false;

    return gridManager.getPattern();
}

int GameOfLife::loadFile(string fileName)
{
	this->clear();

    int check = fileManager.load(fileName, gridManager.gridRef(), gridManager.rowRef(), gridManager.colRef()); 
    if (check == -11)
        return -11;

	gridManager.setInitGrid(gridManager.getPattern(), gridManager.getNumOfRow(), gridManager.getNumOfCol());
    gridManager.setTmpSize(gridManager.getNumOfRow(), gridManager.getNumOfCol());
    gridManager.updateLivingList();
	return 0;
}

int GameOfLife::saveFile()
{
	return fileManager.save(gridManager.getSaveGrid(), gridManager.getNumOfRow(), gridManager.getNumOfCol());
}

int GameOfLife::saveAsFile(string fileName)
{
    return fileManager.saveAs(fileName, gridManager.getSaveGrid(), gridManager.getNumOfRow(), gridManager.getNumOfCol());
}

void GameOfLife::saveResultFile(string fileName)
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
	gridManager.setInitGrid(gridManager.getPattern(), gridManager.getNumOfRow(), gridManager.getNumOfCol());
}

void GameOfLife::setByClick(unsigned int row, unsigned int col)
{
    gridManager.setByClick(row, col);
	if (notFstRun)
		gridManager.setInitGrid(gridManager.getPattern(), gridManager.getNumOfRow(), gridManager.getNumOfCol());
}

const vector< vector<bool> >& GameOfLife::getPattern()
{
    return gridManager.getPattern();
}


unsigned int GameOfLife::getNumOfRow()
{
    return gridManager.getNumOfRow();
}

unsigned int GameOfLife::getNumOfCol()
{
    return gridManager.getNumOfCol();
}