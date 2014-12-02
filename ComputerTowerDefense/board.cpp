/* File: board.cpp
   Author: Samy Lanka
   PennKey: lankas
   Description: 
*/

using namespace std;
#include "board.h"
#include <vector>
#include <iostream>

vector<Bug> Board::getBugs() {
	return m_bugs;
}

void Board::addBug() {
	Bug newBug;
	m_bugs.push_back(newBug);
	for (int i = 0; i < (int) m_bugs.size(); i++) {
		m_bugs.at(i).printBug();
	}
}

int Board::moveBugs() {
	for (int i = 0; i < (int) m_bugs.size(); i++) {
		if (m_bugs.at(i).move() == 1) {
			m_bugs.at(i).printBug();
			return 1;
		}
		m_bugs.at(i).printBug();
	}
	return 0;
}

void Board::removeBug(Bug *b) {
	vector < Bug > listBugs;
	for (int i = 0; i < (int) m_bugs.size(); i++) {
		cout << "i: " << i << endl;
		
		if (b != &(m_bugs.at(i))) {
			cout << "bug not removed" << endl;
			listBugs.push_back(m_bugs.at(i));
		}
	}
	m_bugs = listBugs;
}

void Board::attack() {
	for (int i = 0; i < (int) m_towers.size(); i++) {
		// find bugs that will be attacked
		// do damage

		if (m_bugs.at(0).takeDamage(m_towers.at(i).getAttack()) == 1) {
			cout << "bug died" << endl;
			m_money += m_bugs.at(0).getReward();
			removeBug(&(m_bugs.at(0)));
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

void Board::placeTower(Tower *t, int x, int y) {
	if (x < 0 || y < 0 || x >= GAME_WIDTH || y >= GAME_WIDTH) {
		// TODO: deal with invalid position
	}

	if (m_tower_placement.at(y).at(x)) {
		// TODO: deal with invalid position
	}

	else {
		m_tower_placement.at(y).at(x) = true;
		t->setXPosition(x);
		t->setYPosition(y);
	}
}


void Board::printBugs() {	
	vector<Bug> bugs = getBugs();
	for (int i = 0; i < (int) bugs.size(); i++) {
		bugs.at(i).printBug();
	}
}

void Board::printTowerLocations() {
	for (int i = 0; i < (int) m_tower_placement.size(); i++) {
		for (int j = 0; j < (int) m_tower_placement.at(i).size(); j++) {
			if (!m_tower_placement.at(i).at(j)) {
				cout << "-" << " ";
			}
			else {
				cout << 't' << " ";
			}
		}
		cout << endl;
	}
}

vector<Tower> Board::getTowers() {
	return m_towers;
}

Board::Board() {
	m_money = START_MONEY;
	m_tower_placement.resize(GAME_WIDTH);

	for (int i = 0; i < GAME_WIDTH; i++) {
		m_tower_placement.at(i).resize(GAME_WIDTH, false);
	}
	//addPath();
}

// void Board::addPath() {
// 	for (int i = 0; i < 3; i++) {
// 		m_tower_placement.at(1).at(i) = new GameObject(true);
// 	}
// 	for (int i = 2; i < 7; i++) {
// 		m_tower_placement.at(i).at(2) = new GameObject(true);
// 	}
// 	for (int i = 3; i < 10; i++) {
// 		m_tower_placement.at(6).at(i) = new GameObject(true);
// 	}
// }


/**************************
 * handle later 
 *************************/
void Board::buySpell() {

}

void Board::playSpell() {

}
