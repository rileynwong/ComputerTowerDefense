/* File: board.cpp
   Author: Samy Lanka
   PennKey: lankas
   Description: 
*/

using namespace std;
#include "board.h"
#include <vector>
#include <iostream>

vector<Bug*> Board::getBugs() {
	return m_bugs;
}

void Board::addBug() {
	Bug *newBug = new Bug;
	m_bugs.push_back(newBug);

	m_bugPlacement.at(0) = newBug;
}

int Board::moveBugs() {
	cout << "move bugs" << endl;
	if (m_bugPlacement.at(PATH_LENGTH - 1)) {
		return 1;
	}
	for (int i = PATH_LENGTH - 1; i > 0; i--) {
		m_bugPlacement.at(i) = m_bugPlacement.at(i - 1);
		if (m_bugPlacement.at(i)) {
			m_bugPlacement.at(i)->setXPosition(m_pathXCoords.at(i));
			m_bugPlacement.at(i)->setYPosition(m_pathYCoords.at(i));
			m_bugPlacement.at(i)->printBug();
		}
	}
	addBug();
	return 0;
}

// TODO: THIS IS IN BAD SHAPE AND SHOULD BE FIXED
void Board::removeBug(Bug *b) {
	// vector < Bug > listBugs;
	// for (int i = 0; i < (int) m_bugs.size(); i++) {
	// 	cout << "i: " << i << endl;
		
	// 	if (b != &(m_bugs.at(i))) {
	// 		cout << "bug not removed" << endl;
	// 		listBugs.push_back(m_bugs.at(i));
	// 	}
	// }
	// m_bugs = listBugs;
}

void Board::attack() {
	for (int i = 0; i < (int) m_towers.size(); i++) {
		// find bugs that will be attacked
		// do damage
		direction dir = m_towers.at(i).getDirAttack();

		if (m_bugs.at(0)->takeDamage(m_towers.at(i).getAttack()) == 1) {
			cout << "bug died" << endl;
			m_money += m_bugs.at(0)->getReward();
			removeBug(m_bugs.at(0));
		}
	}
}

// change to buy each specific tower and spell
Tower *Board::buyTower() {
	// check if you have enough money
	// spend money
	if (m_money < COST_TOWER) {
		//TODO: some sort of error checking
	}

	m_money -= COST_TOWER;
	Tower *tower = new Tower;
	m_towers.push_back(*tower);
	return tower;
}

bool Board::containsPath(int x, int y) {
	for (int i = 0; i < PATH_LENGTH; i++) {
		if (x == m_pathXCoords.at(i) && y == m_pathYCoords.at(i)) {
			return true;
		}
	}
	return false;
}

void Board::placeTower(Tower *t, int x, int y) {
	if (x < 0 || y < 0 || x >= GAME_WIDTH || y >= GAME_WIDTH) {
		// TODO: deal with invalid position
	}

	if (m_towerPlacement.at(y).at(x) == 1 || containsPath(x, y)) {
		// TODO: deal with invalid position
	}

	else {
		m_towerPlacement.at(y).at(x) = 1;
		t->setXPosition(x);
		t->setYPosition(y);
	}
}


void Board::printBugs() {	
	vector<Bug*> bugs = getBugs();
	for (int i = 0; i < (int) bugs.size(); i++) {
		bugs.at(i)->printBug();
	}
}

void Board::printTowerLocations() {
	for (int i = 0; i < (int) m_towerPlacement.size(); i++) {
		for (int j = 0; j < (int) m_towerPlacement.at(i).size(); j++) {
			if (m_towerPlacement.at(i).at(j) == 0) {
				cout << "-" << " ";
			}
			else if (m_towerPlacement.at(i).at(j) == 1) {
				cout << 't' << " ";
			}
			else {
				cout << '.' << " ";
			}
		}
		cout << endl;
	}
}

vector<Tower> Board::getTowers() {
	return m_towers;
}

void Board::addPath() {
	for (int i = 0; i < 3; i++) {
		m_pathXCoords.at(i) = i;
		m_pathYCoords.at(i) = 2;
	}
}

Board::Board() {
	m_money = START_MONEY;
	m_towerPlacement.resize(GAME_WIDTH);

	for (int i = 0; i < GAME_WIDTH; i++) {
		m_towerPlacement.at(i).resize(GAME_WIDTH, false);
	}
	m_pathXCoords.resize(PATH_LENGTH);
	m_pathYCoords.resize(PATH_LENGTH);
	m_bugPlacement.resize(PATH_LENGTH);

	addPath();
}


/**************************
 * handle later 
 *************************/
void Board::buySpell() {

}

void Board::playSpell() {

}
