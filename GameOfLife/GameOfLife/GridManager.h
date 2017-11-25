/* GridManager
 * Store the file data read from data file
 * pass data to Grid, let it update the pattern
 * @authot: ZHU GUANGYU
 * @modify time: 17/11/25 10:40
 */

#ifndef GRIDMANAGER_H
#define GRIDMANAGER_H

#include "Grid.h"
#include <vector>
using namespace std;

class GridManager {
public:
    /* the constructor
     * build a default grid which size is 50 * 40
     */
    GridManager();

    /* pass grid's referenec
     * let load to modify the initGrid
     */
    vector< vector<bool> >& setInitGrid();
    
    unsigned int& setRow();
    unsigned int& setCol();

    const vector< vector<bool> >& getSaveGrid();
    
    unsigned int getNumOfRow();
    
    unsigned int getNumOfCol();

    void resize(unsigned int row, unsigned int col);

    /* clear current grid
     * set all the cells to be dead
     */
    const vector< vector<bool> > & clear();

    /* create a new default grid
     * clear all the current data
     */
    void newGrid();

    void setGnrtGrid(const vector< vector<bool> >& grid);

    const vector< vector<bool> >& generateGrid();

    const vector< vector<bool> >& getPattern();

    void setByClick(unsigned int row, unsigned  int col, vector< vector<bool> >& grid);


private:
    vector< vector<bool> > initGrid;
    unsigned int numOfRow;
    unsigned int numOfCol;

    Grid gridUpdate;
};
#endif
