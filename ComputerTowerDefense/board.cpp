/* File: board.cpp
   Author: Samy Lanka
   PennKey: lankas
   Description: 
*/

#include "board.h"

void Board::addBug() {
	Bug newBug();
	m_bugs.pushback(newBug);
}

void Board::moveBugs() {
	for (int i = 0; i < (int) m_bugs.size(); i++) {
		m_bugs.at(i).move();
	}
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