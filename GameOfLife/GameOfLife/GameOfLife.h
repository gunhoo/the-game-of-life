#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#include "Grid.h"
#include "Save.h"
#include "Load.h"
#include <string>

using namespace std;

class GameOfLife {
public:
	//GameOfLife();
	void updateGrid();
	const vector< vector<bool> >& getGrid();

	/* return value to check if we open file successful
	* -11 means the file format not match
	* @parameter: file name
	*/
	int load(string fileName);

	/* return value to check if save file successful
	* -22 means there is already a file with same file name;
	* @parameter: file name
	*/
	int save(string fileName);

	/* give the new row and col number to resize the grid
	* all element will be set to false.
	* @parameter: number of row, number of column
	*/
	void resizeGrid(int row, int col);

	/* read grid from GUI
	* @parameter: the 2d vector of grid
	*/
	void readFromOut(const vector< vector<bool> > &grid);

	int getRow(); // return the number of row
	int getCol(); // return the number of column

private:
	Grid gridPart;
	Save savePart;
	Load loadPart;
};

#endif