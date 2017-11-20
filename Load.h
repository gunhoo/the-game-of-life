#pragma once

#ifndef _Load_h
#define _Load_h

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class Load {
private:
	int size_x; //row
	int size_y; //column

	vector< vector <bool> > isLive;

public:

	// return -1 mean load orror
	// return 1 mean load success
	int loadFile(string fileName);

	vector< vector<bool> >& getGrid();
	int getRow();
	int getCol();


};
#endif // _load_h