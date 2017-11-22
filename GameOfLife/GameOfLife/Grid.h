/* 17/11/15 ZHU GUANGYU
* Grid
* the main class of the game of life
* provide the grid, update cell's state
* associate with Load and Store class to input or output data file.
*/

#ifndef _grid_h
#define _grid_h

#include <vector>
#include <list>

using namespace std;

class Grid {
public:
	/* constructor.
	* Grid be represented by a 2-d bool vector
	* default size is 50 * 40
	*/
	Grid(int row = 50, int col = 40);
	// ~Grid();

	int getRow(); // return the #row

	int getColumn(); // return the #column

					 /* resize the grid, set all the element to false
					 * @parameter: #row, #column
					 */
	void resizeGrid(int row, int col);

	/* check every cell's 8 neighbors
	* depends on the number of living neighbors, set cell's state.
	* then update the pattern
	*/
	void updateGrid();

	/* get the clicked cells' position from GUI
	* update the gridShow, then we can start to update the pattern
	* @parameter: a list of cell's coordinates
	*/
	void readFromOut(vector< vector<bool> > grid); // change cell's state

	const vector< vector<bool> >& getGrid();

private:
	int numOfRow;
	int numOfColumn;
	vector< vector<bool> > gridShow;
	vector< vector<bool> > tmpGrid; // a temperary grid for helping generate next pattern

	struct cell {
		int x;
		int y;
	};

	int getLivingNeighbors(int x, int y);

};

#endif
// matrix.resize(row_count, vector<char>(column_count, initialization_char));
