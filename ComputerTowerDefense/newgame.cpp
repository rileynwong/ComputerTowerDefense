
using namespace std;

#include "board.h"
#include <iostream>

int main() {
	cout << "creating board" << endl;
	Board board;
	cout << "buying tower" << endl;
	if (board.enoughMoney()) {
		board.buyWTower(1, 3);
	}
	cout << endl << endl;

	//while (lose != 1) {
		// lose = board.moveBugs();
	//}
	board.moveBugs();
	cout << "print" << endl;
	board.printTowerLocations();

	board.moveBugs();
	//board.attack();
	board.printTowerLocations();

	board.moveBugs();
	board.printTowerLocations();

	//board.moveBugs();
	board.attack();
	board.printTowerLocations();

	//board.moveBugs();
	board.attack();
	board.attack();
		board.printTowerLocations();

	board.attack();
	board.printTowerLocations();

	return 0;
	// cout << "attacking" << endl;
	// board.attack();

	// board.printBugs();
}