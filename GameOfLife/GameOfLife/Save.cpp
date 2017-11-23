#include "Save.h"

using namespace std;

int Save::saveFile(string fileName, vector <vector< bool > > grid, int row, int col) {
	int x, y;
	
	//GUI ���� 
	
	//if save button clicked Gui will ask for filename and it will be send to here
	

	//if textfile is already exists than show error message or ask overwrite? return 0;

	//open file
	
	fstream file;
	file.open(fileName, ios_base::out | ios_base::in);  // will not create file
	if (file.is_open())
	{
		
		//Gui
		cout << "Warning, file already exists";
		
		file.close();
		return 0;
	}
	
	ofstream myfile;
	myfile.open(fileName);

	myfile << row;
	myfile << "\n";
	myfile << col;
	myfile << "\n";

	for (x = 0; x < row; x++) {
		for (y = 0; y < col; y++) {
			if (grid[x][y]) {
				myfile << "X";
			}
			else {
				myfile << "-";
			}
			
		}
		myfile << "\n";
	}

	return 1; //success
	myfile.close();


}