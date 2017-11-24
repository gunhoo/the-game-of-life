<<<<<<< Updated upstream
#ifndef _FileManager_h
#define _FileMAnager_h
>>>>>>> Stashed changes

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class FileManager {
public:

	void newGrid();

	/*
	save success reuturn 0 (modify == false is also return 0 because don't need to save file)
	In save as function if filename is already exsist return -1;
	*/

	/*
		check gridmanager geter and setter inside my code to checi initialization in side funcs
	*/
	int save();

	int saveAs(string fileName);
	
	int load(string fileName);

	bool isModify();

private:
	string FileName;
	bool modify = false;
};
#endif 
