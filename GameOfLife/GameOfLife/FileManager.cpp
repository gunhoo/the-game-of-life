#include "FileManager.h"

int FileManager::Load(string fileName) {

	FileName = fileName;

	ifstream inFile;
	inFile.open(fileName);

	//get it from grid manager
	vector< vector <bool> > tmp;
	unsigned int row = 0;
	unsigned int col = 0;

	std::string str;

	while (row == 0) {
		std::getline(inFile, str);	//if this line is comment line just ignore this
		if (str[0] == '#') {
			row = 0;
		}
		else {						//if this line is not comment line
			if (!isdigit(str[0])) {
				cout << "wrong format" << endl;
				return -11;
			}
			stringstream geek(str);	//change string value to int value
			geek >> row;				//put it in x
		}
	}

	//get y value
	std::getline(inFile, str);
	if (!isdigit(str[0])) {
		cout << "wrong format" << endl;
		return -11;
	}
	stringstream geek(str);
	geek >> col;

	tmp.assign(row, vector<bool>(col, false));			//check

	int cur_x = 0;
	int cur_y = 0;
	char element;
	while (std::getline(inFile, str)) //read one line
	{

		while (element = str[cur_y]) {	//read string character by character
			if (element == '-') {	//if character is - put - in table
				tmp[cur_x][cur_y] = false;
				cur_y++;				// and move y ÁÂÇ¥
			}
			else if (element == 'X') {
				tmp[cur_x][cur_y] = true;
				cur_y++;				//and move y ÁÂÇ¥
			}
			else {
				cout << "wrong format" << endl;
				return -11;
			}
		}
		cur_x++;						//move x ÁÂÇ¥
		cur_y = 0;						//reset y ÁÂÇ¥
	}

	setInitGrid(tmp, row, col);

	inFile.close();
	return 0; // success


}

int FileManager::SaveAs(string fileName) {

	//don't need to implement modify exception user can want save same data in different text file.

	vector< vector <bool> > tmp = getSaveGrid();
	unsigned int row = getNumOfRow();
	unsigned int col = getNumOfCol();

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
			if (tmp[cur_x][cur_y]) {
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

void FileManager::New()
{
	/*
		1: grid row col FileName ÃÊ±âÈ­ ÇØÁÖ±â ³¡?? 
	*/
	
	vector< vector <bool> > tmp;

	unsigned int row = 50;
	unsigned int col = 40;

	tmp.assign(row, vector<bool>(col, false));

	setInitGrid(tmp, row, col);

	FileName = "untitle.txt";
}

int FileManager::Save() {

	//if user click new after click save CUI must give new filename value 
	if (FileName == "untitle.txt" && Modify == true) {
		string newfile;
		SaveAs(newfile);
		return 0;
	}

	if (Modify == false) {
		//file does not change at all
		return 0;
	}

	vector< vector <bool> > tmp = getSaveGrid();
	unsigned int row = getNumOfRow();
	unsigned int col = getNumOfCol();

	ofstream myfile;
	myfile.open(FileName);

	myfile << row;
	myfile << "\n";
	myfile << col;
	myfile << "\n";

	for (int cur_x = 0; cur_x < row; cur_x++) {
		for (int cur_y = 0; cur_y < col; cur_y++) {
			if (tmp[cur_x][cur_y]) {
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

bool FileManager::isModify() {
	Modify = true;
}