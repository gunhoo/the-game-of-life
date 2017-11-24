#include "FileManager.h"

int FileManager::load(string fileName, vector< vector <bool> >& input, unsigned int& row, unsigned int& col) {

	FileName = fileName;

	ifstream inFile;
	inFile.open(fileName);

	row = 0;
	col = 0;

	std::string str;

	while (row == 0) {
		std::getline(inFile, str);	//if this line is comment line just ignore this
		if (str[0] == '#') {
			row = 0;
		}
		else {						
			if (!isdigit(str[0])) {
				return -11;
			}
			stringstream geek(str);	//change string value to int value
			geek >> row;			
		}
	}

	std::getline(inFile, str);
	if (!isdigit(str[0])) {
		cout << "wrong format" << endl;
		return -11;
	}
	stringstream geek(str);
	geek >> col;

	input.assign(row, vector<bool>(col, false));			

	int cur_x = 0;
	int cur_y = 0;
	char element;
	while (std::getline(inFile, str)) 
	{

		while (element = str[cur_y]) {	
			if (element == '-') {	
				input[cur_x][cur_y] = false;
				cur_y++;				
			}
			else if (element == 'X') {
				input[cur_x][cur_y] = true;
				cur_y++;				 
			}
			else {
				return -11;
			}
		}
		cur_x++;						
		cur_y = 0;				
	}


	inFile.close();
	return 0;
}

void FileManager::initName()
{
	FileName = "untitle.txt";
}

int FileManager::save(const vector< vector <bool> >& grid, unsigned int row, unsigned int col) {

	//if user click new after click save CUI must give new filename value 
	if (FileName == "untitle.txt" && Modify == true) {
		string newfile;
		saveAs(newfile, grid, row, col);
		return -1;
	}

	if (Modify == false) {
		//file does not change at all
		return 0;
	}

	ofstream myfile;
	myfile.open(FileName);

	myfile << row;
	myfile << "\n";
	myfile << col;
	myfile << "\n";

	for (int cur_x = 0; cur_x < row; cur_x++) {
		for (int cur_y = 0; cur_y < col; cur_y++) {
			if (grid[cur_x][cur_y]) {
				myfile << "X";
			}
			else {
				myfile << "-";
			}

		}
		myfile << "\n";
	}
	myfile.close();
	return 0; //success
}

int FileManager::saveAs(string fileName, const vector< vector <bool> >& grid, unsigned int row, unsigned int col) {

	//don't need to implement modify exception user can want save same data in different text file.

	if (FileName == fileName) {
		// user wants to save the new file to old file we'd better ask about  user want overwriting or not.
		return -1;
	}

	ofstream myfile;
	myfile.open(fileName);

	myfile << row;
	myfile << "\n";
	myfile << col;
	myfile << "\n";

	for (int cur_x = 0; cur_x < row; cur_x++) {
		for (int cur_y = 0; cur_y < col; cur_y++) {
			if (grid[cur_x][cur_y]) {
				myfile << "X";
			}
			else {
				myfile << "-";
			}

		}
		myfile << "\n";
	}
	myfile.close();
	return 0; //success
}

void FileManager::saveResult(string fileName, const vector< vector <bool> >& pattern, unsigned int row, unsigned int col) {

	ofstream myfile;
	myfile.open(fileName);

	myfile << row;
	myfile << "\n";
	myfile << col;
	myfile << "\n";

	for (int cur_x = 0; cur_x < row; cur_x++) {
		for (int cur_y = 0; cur_y < col; cur_y++) {
			if (pattern[cur_x][cur_y]) {
				myfile << "X";
			}
			else {
				myfile << "-";
			}

		}
		myfile << "\n";
	}
	myfile.close();
}

bool FileManager::isModify() {
	Modify = true;
}