/* File: board.cpp
   Author: Samy Lanka
   PennKey: lankas
   Description: This object holds all state and performs all the interesting
   actions on the game state. The important public functions are moveBugs, 
   attack, moveProjectiles, and everything associated with buying towers
*/


#include <fstream>
#include "board.h"
#include "projectile.h"
#include <vector>
#include <iostream>


using namespace std;

/** Create and Move Bugs **/

/*****
Accessors for the gamescreen and main
******/

vector< vector < int > > Board::getPieces() {
	return m_placements;
}

int Board::getMoney() {
	return m_money;
}

int Board::getHealth() {
	return m_health;
}

/*****
Create and Move Bugs
*****/

void Board::addBug() {
	Bug *bug = new Bug(DEF_HEALTH, DEF_REWARD, m_pathXCoords.at(0), 
					   m_pathYCoords.at(0));

	m_bugPlacement.at(0) = bug;
	m_placements.at(bug->getYPosition()).at(bug->getXPosition()) = BUG;
}


int Board::moveBugs() {
	int end = m_pathLength - 1;
	if (m_bugPlacement.at(end)) {
		m_placements.at(m_pathYCoords.at(end)).at(m_pathXCoords.at(end)) = BUG;
		return 1;
	}
	for (int i = end; i > 0; i--) {
		m_bugPlacement.at(i) = m_bugPlacement.at(i - 1);
		Bug *bug = m_bugPlacement.at(i);

		if (bug) {
			bug->setXPosition(m_pathXCoords.at(i));
			bug->setYPosition(m_pathYCoords.at(i));
			m_placements.at(bug->getYPosition()).at(bug->getXPosition()) = BUG;
		}
		else {
			m_placements.at(m_pathYCoords.at(i))
						.at(m_pathXCoords.at(i)) = PATH;	
		}
	}
	addBug();
	return 0;
}


/** Attack and Kill Bugs **/

void Board::removeBug(Bug *b) {
	for (int i = 0; i < (int) m_bugPlacement.size(); i++) {
		Bug *bug = m_bugPlacement.at(i);
		if (bug->getXPosition() == b->getXPosition() &&
			bug->getYPosition() == b->getYPosition()) {
			m_bugPlacement.at(i) = NULL;

			m_placements.at(bug->getYPosition())
						.at(bug->getXPosition()) = PATH;
			delete(bug);
			return;
		}
	}
}

Bug *Board::findBug(int x, int y) {
	for (int i = 0; i < m_pathLength; i++) {
		if (x == m_pathXCoords.at(i) && y == m_pathYCoords.at(i)) {
			return m_bugPlacement.at(i);
		}
	}
	return NULL;
}

void Board::attackBug(Bug *bug, int attack) {
	if (bug->takeDamage(attack) == 1) {
		m_money += bug->getReward();
		removeBug(bug);
	}
}

void Board::attack() {
	for (int i = 0; i < (int) m_towers.size(); i++) {
		Tower *t = m_towers.at(i);
		Projectile *p = new Projectile(t->getXPosition(), t->getYPosition(), 
									   t->getAttack(), t->getDirAttack(), 
									   t->getRadius(), m_width, m_length);
		m_projectiles.push_back(p);

		moveProjectiles();
	}
}

/** Move/Remove Projectiles **/

void Board::removeProjectile(Projectile *p) {
	vector<Projectile*> projList;
	bool removed = false;
	for (int i = 0; i < (int) m_projectiles.size(); i++) {
		Projectile *proj = m_projectiles.at(i);
		if (removed ||
			proj->getXPosition() != p->getXPosition() ||
			proj->getYPosition() != p->getYPosition()) {
			
			projList.push_back(proj);
		}
		else {
			delete(proj);
			removed = true;
		}
	}
	m_projectiles = projList;
}

Projectile *Board::findProjectile(int x, int y) {
		for (int i = 0; i < m_pathLength; i++) {
		if (x == m_pathXCoords.at(i) && y == m_pathYCoords.at(i)) {
			return m_projectiles.at(i);
		}
	}
	return NULL;
}

Projectile *Board::moveProjectile(Projectile *p) {
	Bug *bug;

	int x = p->getXPosition();
	int y = p->getYPosition();

	if (m_placements.at(y).at(x) == PROJECTILE) {
		m_placements.at(y).at(x) = NO_OBJECT;
	}
	if (m_placements.at(y).at(x) == PROJ_ON_PATH) {
		m_placements.at(y).at(x) = PATH;
	}
	if (p->move() != 0) {
		return p;
	}

	x = p->getXPosition();
	y = p->getYPosition();

	switch(m_placements.at(y).at(x)) {
		case NO_OBJECT:
			m_placements.at(y).at(x) = PROJECTILE;
			return NULL;
		case TOWER:
			return p;
		case PROJECTILE:
			return p;
		case PROJ_ON_PATH:
			return p;
		case BUG:
			bug = findBug(x, y);
			if (bug) {
				attackBug(bug, p->getAttack());
				return p;
			}
			return NULL;
		case PATH:
			m_placements.at(y).at(x) = PROJ_ON_PATH;
			return NULL;
	}
	return NULL;
}


void Board::moveProjectiles() {
	vector<Projectile*> toRemove;
	for (int i = 0; i < (int) m_projectiles.size(); i++) {
		Projectile *p = moveProjectile(m_projectiles.at(i));
		if (p) {
			toRemove.push_back(p);
		}
	}

	for (int i = 0; i < (int) toRemove.size(); i++) {
		removeProjectile(toRemove.at(i));
	}
}


/** Buying Towers **/

bool Board::containsPath(int x, int y) {
	if (m_placements.at(y).at(x) == PATH || 
			m_placements.at(y).at(x) == BUG) {
			return true;
		}
	return false;
}

bool Board::validPosition(int x, int y) {
	if (x < 0 || y < 0 || x >= m_width || y >= m_length) {
		return false;
	}
	if (m_placements.at(y).at(x) == TOWER || containsPath(x, y)) {
		cout << "there" << endl;
		return false;
	}
	return true;
}

void Board::placeTower(Tower *t, int x, int y) {
	if (validPosition(x, y)) {
		m_placements.at(y).at(x) = TOWER;
		t->setXPosition(x);
		t->setYPosition(y);
	}
}

bool Board::enoughMoney() {
	return m_money >= COST_TOWER;
}

bool Board::buyTower() {
	if (m_money >= COST_TOWER) {
		m_money -= COST_TOWER;
		return true;
	}
	else {
		return false;
	}
}

void Board::buyNTower(int x, int y) {
	while (!validPosition(x, y)) {
		cout << x << ", " << y << " is not a valid position." << endl;
		cout << "Please choose new coordinates." << endl;
		cout << "x coordinate: " << endl;
        cin >> x;
        cout << "y coordinate: " << endl;
        cin >> y;
	}
	if (buyTower()) {
		Tower *tower = new Tower(DEF_ATTACK, DEF_MULT_DIR,
			N, DEF_RADIUS, x, y);
		m_towers.push_back(tower);
		placeTower(tower, x, y);
	}
	else {
		cout << "You don't have enough money! Go kill more bugs" << endl;
	}
}

void Board::buyETower(int x, int y) {
	while (!validPosition(x, y)) {
		cout << x << ", " << y << " is not a valid position." << endl;
		cout << "Please choose new coordinates." << endl;
		cout << "x coordinate: " << endl;
        cin >> x;
        cout << "y coordinate: " << endl;
        cin >> y;
	}
	if (buyTower()) {
		Tower *tower = new Tower(DEF_ATTACK, DEF_MULT_DIR,
			E, DEF_RADIUS, x, y);
		m_towers.push_back(tower);
		placeTower(tower, x, y);
	}
	else {
		cout << "You don't have enough money! Go kill more bugs" << endl;
	}
}

void Board::buySTower(int x, int y) {
	while (!validPosition(x, y)) {
		cout << x << ", " << y << " is not a valid position." << endl;
		cout << "Please choose new coordinates." << endl;
		cout << "x coordinate: " << endl;
        cin >> x;
        cout << "y coordinate: " << endl;
        cin >> y;
	}
	if (buyTower()) {
		Tower *tower = new Tower(DEF_ATTACK, DEF_MULT_DIR,
			S, DEF_RADIUS, x, y);
		m_towers.push_back(tower);
		placeTower(tower, x, y);
	}
	else {
		cout << "You don't have enough money! Go kill more bugs" << endl;
	}
}

void Board::buyWTower(int x, int y) {
	while (!validPosition(x, y)) {
		cout << x << ", " << y << " is not a valid position." << endl;
		cout << "Please choose new coordinates." << endl;
		cout << "x coordinate: " << endl;
        cin >> x;
        cout << "y coordinate: " << endl;
        cin >> y;
	}
	if (buyTower()) {
		Tower *tower = new Tower(DEF_ATTACK, DEF_MULT_DIR,
			W, DEF_RADIUS, x, y);
		m_towers.push_back(tower);
		placeTower(tower, x, y);
	}
	else {
		cout << "You don't have enough money! Go kill more bugs" << endl;
	}
}

vector<Tower*> Board::getTowers() {
	return m_towers;
}


/** Print things for debugging **/
void Board::printBugs() {	
	vector<Bug*> bugs = m_bugPlacement;
	for (int i = 0; i < (int) m_bugPlacement.size(); i++) {
		if (m_bugPlacement.at(i)) {
			m_bugPlacement.at(i)->printBug();
		}
	}
}

void Board::printTowerLocations() {
	for (int i = 0; i < (int) m_placements.size(); i++) {
		for (int j = 0; j < (int) m_placements.at(i).size(); j++) {
			if (m_placements.at(i).at(j) == NO_OBJECT) {
				cout << "-" << " ";
			}
			else if (m_placements.at(i).at(j) == TOWER) {
				cout << 't' << " ";
			}
			else if (m_placements.at(i).at(j) == PROJECTILE){
				cout << '.' << " ";
			}
			else if (m_placements.at(i).at(j) == BUG) {
				cout << '*' << " ";
			}
			else if (m_placements.at(i).at(j) == PATH) {
				cout << "p" << " ";
			}
		}
		cout << endl;
	}
	cout << endl;
}

void Board::readPath() {
	ifstream input;
	int x;
	int y;

	input.open("path.txt");

	input >> m_pathLength;
	input >> m_width;
	input >> m_length;

	m_placements.resize(m_length);

	for (int i = 0; i < m_length; i++) {
		m_placements.at(i).resize(m_width, false);
	}

	m_pathXCoords.resize(m_pathLength);
	m_pathYCoords.resize(m_pathLength);
	m_bugPlacement.resize(m_pathLength);

	for(int i = 0; i < m_pathLength; i++) {
		if (input) {
			input >> x >> y;
			m_pathXCoords.at(i) = x;

			m_pathYCoords.at(i) = y;

			m_placements.at(y).at(x) = PATH;

		}
		else {
			cout << "invalid file" << endl;
		}
	}
}

Board::Board() {
	m_money = START_MONEY;
  m_health = START_HEALTH;
	readPath();	
}
