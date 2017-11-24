/* GridManager
 * Store the file data read from data file
 * pass data to Grid, let it update the pattern
 * @authot: ZHU GUANGYU
 * @modify time: 17/11/24 15:54
 */

#ifndef GRIDMANAGER_H
#define GRIDMANAGER_H

#include "Grid.h"
#include <vector>
using namespace std;

class GridManager {
public:
    /* the constructor
     * if there is given size, build grid depends on the size
     * else, build a default grid which size is 50 * 40
     */
    GridManager(int row = 50, int col = 40);

    /* pass grid's referenec
     * let load to modify the initGrid
     */
    vector< vector<bool> > & getInitGrid();
    int getNumOfRow();
    int getNumOfCol();

    void setNumOfRow(unsigned int row);
    void setNumOfCol(unsigned int col);

    /* clear current grid
     * set all the cells to be dead
     */
    void clear();

    /* create a new default grid
     * clear all the current data
     */
    void newGrid();

    const vector< vector<bool> >& generateGrid();

private:
    vector< vector<bool> > initGrid;
    unsigned int numOfRow;
    unsigned int numOfCol;

    Grid gridUpdate;
};
#endif
