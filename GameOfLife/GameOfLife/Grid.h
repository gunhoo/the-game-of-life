/* Grid
 * the main class of the game of life
 * provide the grid, update cell's state
 * associate with Load and Store class to input or output data file.
 * @creater: ZHU GUANGYU
 * @modify time: 17/11/24 18:57
 */

#ifndef GRID_H
#define GRID_H

#include <vector>
#include <list>
#include <iterator>

using namespace std;

class Grid {
public:
    /* constructor. 
     * Grid be represented by a 2-d bool vector
     * size is 50 * 40
     * tmpGrid also be initial at here.
     */
    Grid(); 

/*
    int getRow(); // return the #row
    
    int getColumn(); // return the #column
*/

    /* resize the grid, set all the element to false
     * @parameter: #row, #column
     */
    void resizeGrid(int row, int col);

    /* check living cell and its 8 neighbors
     * depends on the number of living neighbors, set cell's state.
     * then update the pattern
     */
	const vector< vector<bool> >& updateGrid();

    /* read a new grid from out
     * update the currLive list at same time.
     * @parameter: 2d vector from GridManager's initGrid
     */
    void readFromOut(const vector< vector<bool> > &grid); // change cell's state

    /* set all the element's to dead, clear the living cell list
     * does not change the #row and #col
     */
    const vector< vector<bool> >& clear();


private:
    // cell structure for store the living cells into list.
    struct cell {
        int x;
        int y;

        cell(int _x, int _y): x(_x), y(_y){}

        inline cell& operator=(const cell& source) {
            this->x = source.x;
            this->y = source.y;

            return *this;
        }

        inline cell(const cell& source) {
            x = source.x;
            y = source.y;
        }
    };

    int numOfRow;
    int numOfColumn;
    vector< vector<bool> > gridShow;
    vector< vector<bool> > tmpGrid; // a temperary grid for helping generate next pattern
    list<struct cell> currLive; // a list for store all the living cells

    void updateHelper(int x, int y, list<struct cell> &tmpList); // function which check the living cells around a cell

    /* found the minimal block we need to check.
     * thus we can reduce the check which count the living cells.
     * @parameter: living cell's row and col, current time's max/min row and min.
     */
    void getMinBlock(unsigned int this_row, unsigned int this_col, unsigned int& max_row, unsigned int& min_row, unsigned int& max_col, unsigned int& min_col);
    
};

#endif
