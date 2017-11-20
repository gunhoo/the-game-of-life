#include "Grid.h"

Grid::Grid(int row, int col)
{
    if(row != 50 && col != 40) {
        numOfRow = row;
        numOfColumn = col;
        //gridShow.clear();
        //tmpGrid.clear();
        gridShow.assign(numOfRow, vector<bool>(numOfColumn, false));
        tmpGrid.assign(numOfRow, vector<bool>(numOfColumn, false));
    }
    else {
        numOfRow = 50;
        numOfColumn = 40;
        //gridShow.clear();
        //tmpGrid.clear();
        gridShow.assign(50, vector<bool>(40, false));
        tmpGrid.assign(50, vector<bool>(40, false));
    }
}

int Grid::getRow()
{
    return numOfRow;
}

int Grid::getColumn()
{
    return numOfColumn;
}

void Grid::resizeGrid(int row, int col)
{
    numOfRow = row;
    numOfColumn = col;
    //gridShow.clear();
   // tmpGrid.clear();
    gridShow.assign(numOfRow, vector<bool>(numOfColumn, false));
    tmpGrid.assign(numOfRow, vector<bool>(numOfColumn, false));
}

void Grid::updateGrid()
{
	/* 
    for (int i = 0; i < numOfRow; i++) {
        for (int j = 0; j < numOfColumn; i++) {
            bool isLiving = gridShow[i][j];
            int count = getLivingNeighbors(i, j);
			printf("check2\n");
            if(isLiving && count < 2)
                tmpGrid[i][j] = false;
            else if(isLiving && (count == 2 || count == 3))
                tmpGrid[i][j] = true;
            else if(isLiving && count == 3)
                tmpGrid[i][j] = true;
            else if(isLiving && count > 3)
                tmpGrid[i][j] = false;
        }
    }
	*/
	for (int a = 0; a < numOfRow; a++) {		//x 좌표
		for (int b = 0; b < numOfColumn; b++) {	//y 좌표
			int count = 0;
			for (int c = -1; c < 2; c++) {
				for (int d = -1; d < 2; d++) {
					if (c != 0 || d != 0) {	//자기 자신을 count 하지 않기 위해
						if (a + c >= 0 && b + d >= 0 && a + c < numOfRow && b + d < numOfColumn && gridShow[a + c][b + d] == true) {
							count++;
						}
					}
				}
			}
			if (gridShow[a][b] && count < 2)
				tmpGrid[a][b] = false;
			else if (gridShow[a][b] && (count == 2 || count == 3))
				tmpGrid[a][b] = true;
			else if (!gridShow[a][b] && count == 3)
				tmpGrid[a][b] = true;
			else if (gridShow[a][b] && count > 3)
				tmpGrid[a][b] = false;
		}
	}
    gridShow = tmpGrid; 
}

void Grid::readFromOut(vector< vector<bool> > grid)
{
    gridShow = grid;
}

int Grid::getLivingNeighbors(int x, int y)
{
    int count = 0;

    // Check cell on the right.
    if (x != numOfRow - 1)
        if (gridShow[x+1][y])
            count++;
 
    // Check cell on the bottom right.
    if (x != numOfRow - 1 && y != numOfColumn - 1)
        if (gridShow[x+1][y+1])
            count++;
 
    // Check cell on the bottom.
    if (y != numOfColumn - 1)
        if (gridShow[x][y+1])
            count++;
 
    // Check cell on the bottom left.
    if (x != 0 && y != numOfColumn - 1)
        if (gridShow[x-1][y+1])
            count++;
 
    // Check cell on the left.
    if (x != 0)
        if (gridShow[x-1][y])
            count++;
 
    // Check cell on the top left.
    if (x != 0 && y != 0)
        if (gridShow[x-1][y-1])
            count++;
 
    // Check cell on the top.
    if (y != 0)
        if (gridShow[x][y-1])
            count++;
 
    // Check cell on the top right.
    if (x != numOfRow - 1 && y != 0)
        if (gridShow[x+1][y-1])
            count++;
 
    return count;
}

const vector< vector<bool> >& Grid::getGrid()
{
	return gridShow;
}