#include "Load.h"

using namespace std;

int Load::loadFile(string fileName) {
	int count = 0;
	int x, y;
	std::string str;
	char check; //check whether cell is - or X

	// get the text file name from Gui
	/*
	fileName = grid.get_fileName()

	cout << "type file name: " << endl;
	cin >> fileName;
	*/


	ifstream inFile;
	inFile.open(fileName);


	//file open error
	if (!inFile) {
		cerr << "Unable to open file datafile.txt";
		return -1;   // call system to stop
	}


	//Wrong format error (we need to add it)
	while (size_x == 0) {
		std::getline(inFile, str);	//if this line is comment line just ignore this
		if (str[0] == '#') {
			size_x = 0;
		}
		else {						//if this line is not comment line
			stringstream geek(str);	//change string value to int value
			geek >> size_x;				//put it in x
		}
	}

	//get y value
	std::getline(inFile, str);
	stringstream geek(str);
	geek >> size_y;

	isLive.assign(size_x, vector<bool>(size_y, false));


	x = 0;
	y = 0;
	while (std::getline(inFile, str)) //read one line
	{
		//cout << str << endl;

		while (check = str[y]) {	//read string character by character
			if (check == '-') {	//if character is - put - in table
				isLive[x][y] = false;
				y++;				// and move y ÁÂÇ¥
			}
			else if (check == 'X'){
				isLive[x][y] = true;
				count++;
				y++;				//and move y ÁÂÇ¥
			}
		}
		x++;						//move x ÁÂÇ¥
		y = 0;						//reset y ÁÂÇ¥
	}
	if (count == 0) {
		cout << "this text file has empty grid" << endl;
		return 0; //return 1? or return 0?
	}

	return 1; // success
	inFile.close();
}


vector< vector<bool> >& Load::getGrid() {
	return isLive;
}
int Load::getRow() {
	return size_x;
}
int Load::getCol() {
	return size_y;
}