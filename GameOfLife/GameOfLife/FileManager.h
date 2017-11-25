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



	/*
	save success reuturn 0 (modify == false is also return 0 because don't need to save file)
	In save as function if filename is already exsist return -1;
	*/
	int load(string fileName, vector< vector <bool> >& input, unsigned int& row, unsigned int& col);

	/*
		return -1: new -> save gui should run just like save as is pushed
	*/
	int save(const vector< vector <bool> >& grid, unsigned int row, unsigned int col);

	int saveAs(string fileName, const vector< vector <bool> >& grid, unsigned int row, unsigned int col);

	void saveResult(string fileName, const vector< vector <bool> >& pattern, unsigned int row, unsigned int col);

	void initName();

	void isModify();

private:
	string FileName;
	//modify false = not chage		modify true = changed
	bool Modify = false;

};

#endif