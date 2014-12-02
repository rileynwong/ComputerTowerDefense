
using namespace std;

#include "board.h"
#include <iostream>

int main() {
	Board board;
	cout << "board made" << endl;
	Tower tower;
	cout << "tower made" << endl;

	board.addBug();
	int lose = 0;
	while (lose != 1) {
		lose = board.moveBugs();
	}
	cout << "I lost!" << endl;
}