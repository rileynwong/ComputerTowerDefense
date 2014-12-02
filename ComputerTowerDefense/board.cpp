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
	Bug *newBug = new Bug;

	m_bugPlacement.at(0) = newBug;
	m_towerPlacement.at(newBug->getYPosition()).at(newBug->getXPosition()) = BUG;
}

int Board::moveBugs() {
	cout << "move bugs" << endl;
	if (m_bugPlacement.at(PATH_LENGTH - 1)) {
		m_towerPlacement.at(m_pathYCoords.at(PATH_LENGTH - 1)).at(m_pathXCoords.at(PATH_LENGTH - 1)) = BUG;
		return 1;
	}
	for (int i = PATH_LENGTH - 1; i > 0; i--) {
		m_bugPlacement.at(i) = m_bugPlacement.at(i - 1);
		Bug *bug = m_bugPlacement.at(i);
		if (bug) {
			bug->setXPosition(m_pathXCoords.at(i));
			bug->setYPosition(m_pathYCoords.at(i));
			bug->printBug();
			m_towerPlacement.at(bug->getYPosition()).at(bug->getXPosition()) = BUG;

		}
		else {
			m_towerPlacement.at(m_pathYCoords.at(i)).at(m_pathXCoords.at(i)) = NO_OBJECT;	
		}
	}
	addBug();
	return 0;
}

void Board::removeBug(Bug *b) {
	for (int i = 0; i < (int) m_bugPlacement.size(); i++) {
		Bug *bug = m_bugPlacement.at(i);
		if (bug->getXPosition() == b->getXPosition() &&
			bug->getYPosition() == b->getYPosition()) {
			cout << "bug removed" << endl;
			m_bugPlacement.at(i) = NULL;

			m_towerPlacement.at(bug->getYPosition()).at(bug->getXPosition()) = NO_OBJECT;
			// TODO: destroy bug
			return;
		}
	}
}

Bug *Board::findBug(int x, int y) {
	for (int i = 0; i < PATH_LENGTH; i++) {
		if (x == m_pathXCoords.at(i) && y == m_pathYCoords.at(i)) {
			return m_bugPlacement.at(i);
		}
	}
	return NULL;
}

void Board::attackBug(Bug *bug, int attack) {
	if (bug->takeDamage(attack) == 1) {
		cout << "bug died" << endl;
		m_money += bug->getReward();
		removeBug(bug);
	}
}

void Board::attack() {
	for (int i = 0; i < (int) m_towers.size(); i++) {
		Tower *t = m_towers.at(i);
		Projectile *p = new Projectile(t->getXPosition(), t->getYPosition(), 
			t->getAttack(), t->getDirAttack(), t->getRadius());
		m_projectiles.push_back(p);

		p->printProjectile();

		moveProjectiles();
		// Advance projectile one step?? 
		// - depends on the order of things
	}
}

void Board::removeProjectile(Projectile *p) {
	vector<Projectile*> projList;
	for (int i = 0; i < (int) m_projectiles.size(); i++) {
		Projectile *proj = m_projectiles.at(i);
		if (proj->getXPosition() != p->getXPosition() ||
			proj->getYPosition() != p->getYPosition()) {
			
			projList.push_back(proj);
		}
		else {
			// TODO: destroy bug
			cout << "proj removed" << endl;
		}
	}
	m_projectiles = projList;
}

void Board::moveProjectile(Projectile *p) {
	cout << "move projectile" << endl;
	int x = p->getXPosition();
	int y = p->getYPosition();
	if (m_towerPlacement.at(y).at(x) == PROJECTILE) {
		cout << "prep remove projectile" << endl;
		m_towerPlacement.at(y).at(x) = NO_OBJECT;
	}

	if (p->move() != 0) {
		cout << "remove projectile" << endl;
		removeProjectile(p);
		return;
	}
	p->printProjectile();
	x = p->getXPosition();
	y = p->getYPosition();

	if (m_towerPlacement.at(y).at(x) == BUG) {
		Bug *bug = findBug(x, y);
		if (bug) {
			attackBug(bug, p->getAttack());
			cout << "remove projectile there" << endl;
			removeProjectile(p);
		}
	}
	else if (m_towerPlacement.at(y).at(x) != NO_OBJECT) {
		cout << "remove projectile here" << endl;
		removeProjectile(p);
	}

	else {
		cout << "place projectile" << endl;
		m_towerPlacement.at(y).at(x) = PROJECTILE;
	}

	
}


void Board::moveProjectiles() {
	for (int i = 0; i < (int) m_projectiles.size(); i++) {
		moveProjectile(m_projectiles.at(i));
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
	m_towers.push_back(tower);
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

	if (m_towerPlacement.at(y).at(x) == TOWER || containsPath(x, y)) {
		// TODO: deal with invalid position
	}

	else {
		m_towerPlacement.at(y).at(x) = TOWER;
		t->setXPosition(x);
		t->setYPosition(y);
	}
}

vector<Tower*> Board::getTowers() {
	return m_towers;
}

void Board::printBugs() {	
	vector<Bug*> bugs = m_bugPlacement;
	for (int i = 0; i < (int) m_bugPlacement.size(); i++) {
		if (m_bugPlacement.at(i)) {
			m_bugPlacement.at(i)->printBug();
		}
	}
}

void Board::printTowerLocations() {
	for (int i = 0; i < (int) m_towerPlacement.size(); i++) {
		for (int j = 0; j < (int) m_towerPlacement.at(i).size(); j++) {
			if (m_towerPlacement.at(i).at(j) == NO_OBJECT) {
				cout << "-" << " ";
			}
			else if (m_towerPlacement.at(i).at(j) == TOWER) {
				cout << 't' << " ";
			}
			else if (m_towerPlacement.at(i).at(j) == PROJECTILE){
				cout << '.' << " ";
			}
			else if (m_towerPlacement.at(i).at(j) == BUG) {
				cout << '*' << " ";
			}
		}
		cout << endl;
	}
}


void Board::addPath() {
	for (int i = 0; i < PATH_LENGTH; i++) {
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
