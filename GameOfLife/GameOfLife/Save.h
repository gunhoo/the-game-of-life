#pragma once

#ifndef _Save_h
#define _Save_h

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;
class Save {

private:

public:

	/*
	save success = return 1
	save fail (if file is already exist) = reuturn -1
	*/
	int saveFile(string fileName, vector< vector< bool >> grid, int row, int col);

};



#endif // !_Save_h#pragma once
