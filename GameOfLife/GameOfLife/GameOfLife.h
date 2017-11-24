/* the class which connecs Grid, Load, Save together
 * GUI interact with GameOfLife to implement utilities
 * @author: ZHU GUANGYU
 * @modify time: 17/11/23 16:23
 */
 
#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#include "GridManager.h"
#include "FileManager.h"
#include <string>

using namespace std;

class GameOfLife {
public:
    /* get the next generated pattern
     * then use getGrid() again can fetch the new pattern
     */
    void updateGrid();
	const vector< vector<bool> >& getGrid();

    /* return value to check if we open file successful
     * -11 means the file format not match
     * @parameter: file name
     */
    int load(string fileName);

    /* save the pattern into a file.
     * return value to check if save file successful
     * -22 means there is already a file with same file name;
     * @parameter: file name
     */
    int save(string fileName);
    int saveResult(string fileName);
    int saveAs(string fileName);

    /* clear the grid, set all the element to dead.
     * in the grid class, all the gridShow, tmpGrid and currLive are cleared.
     */
    void clear();

    /* give the new row and col number to resize the grid
     * all element will be set to false. 
     * @parameter: number of row, number of column
     */ 
    void resizeGrid(unsigned int row, unsigned int col);

    /* read grid from GUI 
     * @parameter: the 2d vector of grid
     */
    void readFromOut(const vector< vector<bool> > &grid);

    unsigned int getNumOfRow(); // return the number of row
    unsigned int getNumOfCol(); // return the number of column

private:
    GridManager gridManager;
    FileManager fileManager;
};

#endif