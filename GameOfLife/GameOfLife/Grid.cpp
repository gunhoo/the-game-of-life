#include "Grid.h"

Grid::Grid()
{
        numOfRow = 50;
        numOfColumn = 40;
        gridShow.assign(50, vector<bool>(40, false));
        tmpGrid.assign(50, vector<bool>(40, false));
}

void Grid::resizeGrid(unsigned int row, unsigned int col)
{
    if (row > numOfRow && col > numOfColumn) {
        vector< vector<bool> > newShow(row, vector<bool>(col, false));
        for (int i = 0; i < numOfRow; i++) {
            for (int j = 0; j < numOfColumn; j++) {
                newShow[i][j] = gridShow[i][j];
            }
        }
        gridShow = newShow;
        tmpGrid = newShow;
        numOfRow = row;
        numOfColumn = col;
    }
}

void Grid::setTmpSize(unsigned int row, unsigned int col)
{
    tmpGrid.assign(numOfRow, vector<bool>(numOfColumn, false));
}

const vector< vector<bool> >& Grid::updateGrid()
{
    // for find the min block we need to check
    unsigned int min_row = numOfRow - 1;
    unsigned int max_row = 0;
    unsigned int min_col = numOfColumn - 1;
    unsigned int max_col = 0;

    list<struct cell> updateCell;
    vector< vector<unsigned int> > countGrid(numOfRow, vector<unsigned int>(numOfColumn, 0)); // the grid for count the # of living neighbors

    while(!currLive.empty()) {
        struct cell tmp(currLive.back());
        currLive.pop_back();
        getMinBlock(tmp.row, tmp.col, max_row, min_row, max_col, min_col);
        updateHelper(tmp.row, tmp.col, updateCell);
        for (int r = -1; r < 2; r++) {
            for (int c = -1; c < 2; c++) {
                if ((tmp.row + r) >= 0 && (tmp.col + c) >= 0 && (tmp.row + r) < numOfRow && (tmp.col + c) < numOfColumn) {
                    if (r != 0 || c != 0) {
                        if (!gridShow[tmp.row + r][tmp.col + c]) {
                            countGrid[tmp.row + r][tmp.col + c]++;
                        }
                    }
                }
            }
        }
    }

    for (unsigned int i = min_row; i <= max_row; i++) {
        for (unsigned int j = min_col; j <= max_col; j++) {
            if (countGrid[i][j] == 3){
                tmpGrid[i][j] = true;
                struct cell livingCell(i, j);
                updateCell.push_back(livingCell);
            }
        }
    }

    currLive = updateCell;
    gridShow = tmpGrid; 

    return gridShow;
}

void Grid::updateCurrLive()
{
    for (int i = 0; i < numOfRow; i++) {
        for (int j = 0; j < numOfColumn; j++) {
            if (gridShow[i][j]) {
                struct cell livingCell(i, j);
                currLive.push_back(livingCell);                
            }
        }
    }
}

const vector< vector<bool> >& Grid::clear()
{
    gridShow.assign(numOfRow, vector<bool>(numOfColumn, false));
    tmpGrid.assign(numOfRow, vector<bool>(numOfColumn, false));
    currLive.clear();
    return gridShow;
}

const vector< vector<bool> >& Grid::getPattern()
{
    return gridShow;
}

void Grid::updateHelper(unsigned int row, unsigned int col, list<struct cell> &tmpList)
{
    int count = 0;
    for (int c = -1; c < 2; c++) {
        for (int d = -1; d < 2; d++) {
            if (c != 0 || d != 0) {	// get the number of living neighbors.
                if (row + c >= 0 && col + d >= 0 && row + c < numOfRow && col + d < numOfColumn && gridShow[row + c][col + d]) {
                    count++;
                }
            }
        }
    }
    if (gridShow[row][col] && count < 2) {
        tmpGrid[row][col] = false;
    }
    else if (gridShow[row][col] && (count == 2 || count == 3)) {
        tmpGrid[row][col] = true;
        struct cell living(row, col);
        tmpList.push_back(living);
    }
    else if (!gridShow[row][col] && count == 3) {
        tmpGrid[row][col] = true;
        struct cell living(row, col);
        tmpList.push_back(living);
    }
    else if (gridShow[row][col] && count > 3)
        tmpGrid[row][col] = false;
}

void Grid::changeStatus(unsigned int row, unsigned int col)
{
    if (gridShow[row][col]) {
        gridShow[row][col] = false;
        tmpGrid[row][col] = false;
        deleteFromList(row, col);
    }
    else {
        gridShow[row][col] = true;
        tmpGrid[row][col] = true;
        struct cell newCell(row, col);
        currLive.push_back(newCell);
    }
}

vector< vector<bool> >& Grid::gridRef()
{
    return gridShow;
}

unsigned int& Grid::rowRef()
{
    return numOfRow;
}

unsigned int& Grid::colRef()
{
    return numOfColumn;
}

unsigned int Grid::getNumOfRow()
{
    return numOfRow;
}

unsigned int Grid::getNumOfCol()
{
    return numOfColumn; 
}

void Grid::getMinBlock(unsigned int this_row, unsigned int this_col, unsigned int &max_row, unsigned int &min_row, unsigned int &max_col, unsigned int &min_col)
{
	if (this_row == 0)
		min_row = 0;
	else {
		if (this_row - 1 < min_row)
			min_row = this_row - 1;
	}

	if (this_row == numOfRow - 1)
		max_row = this_row;
	else {
		if (this_row + 1> max_row)
			max_row = this_row + 1;
	}

	if (this_col == 0)
		min_col = 0;
	else {
		if (this_col - 1 < min_col)
			min_col = this_col - 1;
	}

	if (this_col == numOfColumn - 1)
		max_col = this_col;
	else {
		if (this_col + 1 > max_col)
			max_col = this_col + 1;
	}
}

void Grid::deleteFromList(unsigned int row, unsigned int col)
{
    list<cell>::iterator it;
    for (it = currLive.begin(); it != currLive.end(); it++)
    {
        if (it->row == row && it->col == col)
            break;
    }
    currLive.erase(it);
}


