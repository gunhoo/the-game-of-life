#include "Grid.h"

Grid::Grid()
{
        numOfRow = 50;
        numOfColumn = 40;
        gridShow.assign(50, vector<bool>(40, false));
        tmpGrid.assign(50, vector<bool>(40, false));
}

/*
int Grid::getRow()
{
    return numOfRow;
}

int Grid::getColumn()
{
    return numOfColumn;
}
*/

void Grid::resizeGrid(int row, int col)
{
    numOfRow = row;
    numOfColumn = col;
    gridShow.assign(numOfRow, vector<bool>(numOfColumn, false));
    tmpGrid.assign(numOfRow, vector<bool>(numOfColumn, false));
    currLive.clear();
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
        for (int r = -1; r < 2; r++) {
            for (int c = -1; c < 2; c++) {
                if ((tmp.x + r) >= 0 && (tmp.y + c) >= 0 && (tmp.x + r) < numOfRow && (tmp.y + c) < numOfColumn) {
                    if (r != 0 || c != 0) {
                        if (!gridShow[tmp.x][tmp.y]) {
                            countGrid[tmp.x + r][tmp.y + c]++;
                        }
                    }
                }
            }
        }
    }

    for (unsigned int i = min_row; i <= max_row; i++) {
        for (unsigned int j = min_col; j <= max_col; j++) {
            if (countGrid[i][j] == 3) {
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

void Grid::readFromOut(const vector< vector<bool> > &grid)
{
    gridShow = grid;

    for (int i = 0; i < numOfRow; i++) {
        for (int j = 0; j < numOfColumn; j++) {
            if (grid[i][j]) {
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

void Grid::updateHelper(int x, int y, list<struct cell> &tmpList)
{
    int count = 0;
    for (int c = -1; c < 2; c++) {
        for (int d = -1; d < 2; d++) {
            if (c != 0 || d != 0) {	// get the number of living neighbors.
                if (x + c >= 0 && y + d >= 0 && x + c < numOfRow && y + d < numOfColumn && gridShow[x + c][y + d]) {
                    count++;
                }
            }
        }
    }
    if (gridShow[x][y] && count < 2) {
        tmpGrid[x][y] = false;
    }
    else if (gridShow[x][y] && (count == 2 || count == 3)) {
        tmpGrid[x][y] = true;
        struct cell living(x, y);
        tmpList.push_back(living);
    }
    else if (!gridShow[x][y] && count == 3) {
        tmpGrid[x][y] = true;
        struct cell living(x, y);
        tmpList.push_back(living);
    }
    else if (gridShow[x][y] && count > 3)
        tmpGrid[x][y] = false;
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

