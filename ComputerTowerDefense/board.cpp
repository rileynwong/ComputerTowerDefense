/* File: board.cpp
   Author: Samy Lanka
   PennKey: lankas
   Description: 
*/

using namespace std;
#include "board.h"
#include <vector>
#include <iostream>

void Board::addBug() {
	Bug newBug;
	cout << "bug made" << endl;
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


void Board::attack() {
	for (int i = 0; i < (int) m_towers.size(); i++) {
		// find bugs that will be attacked
		// do damage
		// see if any were killed
		// if so, get money
		// if so, remove from vector
	}
}

// change to buy each specific tower and spell
void Board::buyTower() {
	// check if you have enough money
	// spend money
	// create tower
	// add to tower list
}

void Board::placeTower(Tower t, int x, int y) {
	// check if on path

	t.setXPosition(x);
	t.setYPosition(y);
}

/*
 * handle later 
 */
void Board::buySpell() {

}

void Board::playSpell() {

}

Board::Board() {
	m_money = 0;
}