#include "Grid.h"
#include "Load.h"
#include "Save.h"
#include <chrono>
#include <thread>

using namespace std::this_thread;
using namespace std::chrono_literals;

int main() {

	int i;
	int exit = 0;
	int choose = 0;
	int stop;
	int check;
	string fileName;

	Save savePart;
	Grid gridPart;
	Load loadPart;
	vector< vector <bool> > grid = gridPart.getGrid();
	//print table 50 * 40


	while (exit == 0) {
		cout << "1:run" << endl << "2:step" << endl << "3:save" << endl << "4:load" << endl << "5:exit" << endl;
		cout << "choose function" << endl;
		cin >> choose;

		switch (choose) {
		case 1:
			//run
			//run game of life
			grid = gridPart.getGrid();
			

			for (int k = 0; k < 10; k++) {
				gridPart.updateGrid();
				grid = gridPart.getGrid();
				for (int i = 0, x_size = gridPart.getRow(); i < x_size; i++) {
					for (int j = 0, y_size = gridPart.getColumn(); j < y_size; j++) {
						if (grid[i][j]) {
							cout << "X";
						}
						else {
							cout << "-";
						}
					}
					cout << "\n";
				}
				sleep_for(0.5s);
				system("CLS");
			}
			break;
		case 2:
			//step print onece
			grid = gridPart.getGrid();
			gridPart.updateGrid();
			for (int i = 0, x_size = gridPart.getRow(); i < x_size; i++) {
				for (int j = 0, y_size = gridPart.getColumn(); j < y_size; j++) {
					if (grid[i][j]) {
						cout << "X";
					}
					else {
						cout << "-";
					}
				}
				cout << "\n";
			}
			sleep_for(0.3s);
			system("CLS");	
			break;
		case 3:
			//save file
			grid = gridPart.getGrid();
			cout << "type new text file name: example.txt" << endl;
			cin >> fileName;
			grid = gridPart.getGrid();

			check = savePart.saveFile(fileName, grid, gridPart.getRow(), gridPart.getColumn());

			if (check == 1) cout << "success" << endl;
			break;
		case 4:
			//load
			cout << "type file name plz" << endl;
			cin >> fileName;

			check = loadPart.loadFile(fileName);
			if (check == 1) cout << "success" << endl;
			gridPart.resizeGrid(loadPart.getRow(), loadPart.getCol());
			gridPart.readFromOut(loadPart.getGrid());

			break;
		case 5:
			//exit
			exit = 1;
			break;
		}
	}


	//save file
	//saveFile(inputTable);

	/*GUI

	start -  stop 버튼 그냥 계속 실행

	step by step 버튼

	save 버튼

	http://web.stanford.edu/~cdebs/GameOfLife/
	참고 ㅎㅎ

	버튼 클릭으로 점 추가 하기

	*/

	return 0;

}