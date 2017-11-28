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
    
    void run();
	void stop();
    
    /* update the pattern, get the reference to pattern grid
     * if this is the 1st time run, pass pattern to initGrid
     */
    const vector< vector<bool> >& next();

    /* create a new file with default size 50 * 40
     * clear the notFstRun, fileName(in fileManager)
     */
	const vector< vector<bool> >& newFile();

    /* return value to check if we open file successful
     * -11 means the file format not match
     * @parameter: file name or file path
     */
    int loadFile(string fileName);

    /* save the pattern into a file.
     * return value to check if save file successful
     * -22 means there is already a file with same file name;
     * @parameter: file name
     */
    int saveFile();
    void saveResultFile(string fileName);
    int saveAsFile(string fileName);

    /* clear the grid, set all the element to dead.
     * in the grid class, all the gridShow, tmpGrid and currLive are cleared.
     */
    void clear();

    /* give the new row and col number to resize the grid
     * all element will be set to false. 
     * @parameter: number of row, number of column
     */ 
    void resizeGrid(unsigned int row, unsigned int col);

    /* change cell's status depends on click on GUI
     * will change the GridManager's initGrid and Grid's gridShow at sametime
     * @parameter: coordinations from GUI grid
     * */
    void setByClick(unsigned int row, unsigned int col);

    const vector< vector<bool> >& getPattern();

    unsigned int getNumOfRow(); // return the number of row
    unsigned int getNumOfCol(); // return the number of column

private:
    GridManager gridManager;
    FileManager fileManager;

    bool isRunning;
};

#endif