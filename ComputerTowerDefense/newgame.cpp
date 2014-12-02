
using namespace std;

#include "board.h"
#include <iostream>

int main() {
	Board board;
	board.printTowerLocations();
	Tower *t = board.buyTower();
	board.placeTower(t, 1, 3);
	cout << endl << endl;

	//while (lose != 1) {
		// lose = board.moveBugs();
	//}
	board.moveBugs();
	board.printTowerLocations();

	board.moveBugs();
	board.attack();
	board.printTowerLocations();

	board.moveBugs();
	board.printTowerLocations();

	board.moveBugs();
	board.attack();
	board.printTowerLocations();

	board.moveBugs();
	board.printTowerLocations();


	cout << "I lost!" << endl;

	return 0;
	// cout << "attacking" << endl;
	// board.attack();

	// board.printBugs();
}