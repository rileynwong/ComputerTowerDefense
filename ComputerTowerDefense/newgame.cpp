
using namespace std;

#include "board.h"
#include <iostream>

int main() {
	Board board;
	cout << "printing game" << endl;
	board.printTowerLocations();
	cout << "buying tower" << endl;
	Tower *t = board.buyTower();
	cout << "placing tower" << endl;
	board.placeTower(t, 1, 3);
	cout << endl << endl;

	

	int lose = 0;
	//while (lose != 1) {
		// lose = board.moveBugs();
	//}
	lose = board.moveBugs();
	board.attack();

	board.printTowerLocations();

	board.attack();

	board.printTowerLocations();
	cout << "I lost!" << endl;

	return 0;
	// cout << "attacking" << endl;
	// board.attack();

	// board.printBugs();
}