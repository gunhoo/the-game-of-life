/* controd load and save
 * modify time: 17/11/25 17:30
 */

#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class FileManager {
public:



	/* get file from outside, store the cell status in a 2d vector
	 * @paramater: the reference to the grid we want to load in. (here is the the Grid's gridShow)
	 */
	int load(string fileName, vector< vector <bool> >& input, unsigned int& row, unsigned int& col);

	/*
		return -1: new -> save gui should run just like save as is pushed
	*/
	int save(const vector< vector <bool> >& grid, unsigned int row, unsigned int col);

	int saveAs(string fileName, const vector< vector <bool> >& grid, unsigned int row, unsigned int col);

	void saveResult(string fileName, const vector< vector <bool> >& pattern, unsigned int row, unsigned int col);

	void initName();

	bool isNewFile();

private:
	string FileName;

};

#endif