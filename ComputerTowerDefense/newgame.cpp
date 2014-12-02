
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
	board.placeTower(t, 6, 1);
	cout << endl << endl;
	board.printTowerLocations();

	// board.addBug();

	int lose = 0;
	while (lose != 1) {
		lose = board.moveBugs();
	}
	cout << "I lost!" << endl;

	// cout << "attacking" << endl;
	// board.attack();

	// board.printBugs();
}