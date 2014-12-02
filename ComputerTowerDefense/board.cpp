/* File: board.cpp
   Author: Samy Lanka
   PennKey: lankas
   Description: 
*/

using namespace std;
#include "board.h"
#include "projectile.h"
#include <vector>
#include <iostream>

/*****
Create and Move Bugs
*****/

void Board::addBug() {
	Bug *newBug = new Bug;

	m_bugPlacement.at(0) = newBug;
	m_towerPlacement.at(newBug->getYPosition()).at(newBug->getXPosition()) = BUG;
}

int Board::moveBugs() {
	cout << "move bugs" << endl;
	if (m_bugPlacement.at(PATH_LENGTH - 1)) {
		cout << "here" << endl;
		m_towerPlacement.at(m_pathYCoords.at(PATH_LENGTH - 1)).at(m_pathXCoords.at(PATH_LENGTH - 1)) = BUG;
		return 1;
	}
	for (int i = PATH_LENGTH - 1; i > 0; i--) {
		cout << "i: " << i << endl;
		m_bugPlacement.at(i) = m_bugPlacement.at(i - 1);
		Bug *bug = m_bugPlacement.at(i);

		if (bug) {
			cout << "in here" << endl;

			bug->setXPosition(m_pathXCoords.at(i));
			bug->setYPosition(m_pathYCoords.at(i));
			bug->printBug();
			m_towerPlacement.at(bug->getYPosition()).at(bug->getXPosition()) = BUG;

		}
		else {
			cout << "here" << endl;
			cout << "this x and y: " << m_pathXCoords.at(i) << " " << m_pathYCoords.at(i) << endl;
			m_towerPlacement.at(m_pathYCoords.at(i)).at(m_pathXCoords.at(i)) = NO_OBJECT;	
		cout << "here" << endl;
			
		}
	}
	addBug();
	return 0;
}


/*****
Attack and Kill Bugs
*****/

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
		//cout << "proj created: " << t->getXPosition() << " " << t->getYPosition()<< endl;
		Projectile *p = new Projectile(t->getXPosition(), t->getYPosition(), 
			t->getAttack(), t->getDirAttack(), t->getRadius());
		m_projectiles.push_back(p);

		moveProjectiles();
		// Advance projectile one step?? 
		// - depends on the order of things
	}
}

/*****
Move/Remove Projectiles
*****/

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
			// TODO: destroy proj
			removed = true;
			//cout << "proj removed" << endl;
		}
	}
	m_projectiles = projList;
}

Projectile *Board::moveProjectile(Projectile *p) {
	int x = p->getXPosition();
	int y = p->getYPosition();
	//cout << "move projectile: " << x << " " << y << endl;

	if (m_towerPlacement.at(y).at(x) == PROJECTILE) {
		//cout << "prep remove projectile" << endl;
		m_towerPlacement.at(y).at(x) = NO_OBJECT;
	}

	if (p->move() != 0) {
		//cout << "remove projectile" << endl;
		return p;
	}
	//cout << "just moved: ";
	//p->printProjectile();
	x = p->getXPosition();
	y = p->getYPosition();

	if (m_towerPlacement.at(y).at(x) == BUG) {
		Bug *bug = findBug(x, y);
		if (bug) {
			attackBug(bug, p->getAttack());
			//cout << "projectile hit bug" << endl;
			return p;
		}
	}
	else if (m_towerPlacement.at(y).at(x) != NO_OBJECT) {
		//cout << "projectile hit object: " << m_towerPlacement.at(y).at(x) << endl;
		return p;
	}

	else {
		//cout << "place projectile" << endl;
		m_towerPlacement.at(y).at(x) = PROJECTILE;
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


/*****
Buying Towers
*****/

bool Board::containsPath(int x, int y) {
	for (int i = 0; i < PATH_LENGTH; i++) {
		if (x == m_pathXCoords.at(i) && y == m_pathYCoords.at(i)) {
			return true;
		}
	}
	return false;
}

void Board::placeTower(Tower *t, int x, int y) {
	if (x < 0 || y < 0 || x >= GAME_WIDTH || y >= GAME_LENGTH) {
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
	if (buyTower()) {
		Tower *tower = new Tower(DEF_ATTACK, DEF_MULT_DIR,
			N, DEF_RADIUS, x, y);
		m_towers.push_back(tower);
		placeTower(tower, x, y);
	}
	else {
		// Error out
	}
}

void Board::buyETower(int x, int y) {
	if (buyTower()) {
		Tower *tower = new Tower(DEF_ATTACK, DEF_MULT_DIR,
			E, DEF_RADIUS, x, y);
		m_towers.push_back(tower);
		placeTower(tower, x, y);
	}
	else {
		// Error out
	}
}

void Board::buySTower(int x, int y) {
	if (buyTower()) {
		Tower *tower = new Tower(DEF_ATTACK, DEF_MULT_DIR,
			S, DEF_RADIUS, x, y);
		m_towers.push_back(tower);
		placeTower(tower, x, y);
	}
	else {
		// Error out
	}
}

void Board::buyWTower(int x, int y) {
	if (buyTower()) {
		Tower *tower = new Tower(DEF_ATTACK, DEF_MULT_DIR,
			W, DEF_RADIUS, x, y);
		m_towers.push_back(tower);
		placeTower(tower, x, y);
	}
	else {
		// Error out
	}
}

vector<Tower*> Board::getTowers() {
	return m_towers;
}


/*****
Print things for debugging
*****/

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
	cout << endl;
}


void Board::addPath() {

	for (int i = 0; i < PATH_LENGTH; i++) {
		if (i < PATH_TEN) {
			m_pathXCoords.at(i) = i;
			m_pathYCoords.at(i) = PATH_SEVEN;
		}
		else if (i < PATH_FIFTEEN) {
			m_pathXCoords.at(i) = PATH_NINE;
			m_pathYCoords.at(i) = i - PATH_TWO;
		}
		else if (i < PATH_TWENTY_NINE) {
			m_pathXCoords.at(i) = i - PATH_FIVE;
			m_pathYCoords.at(i) = PATH_TWELVE;
		}
		else if (i < PATH_THIRTY_SEVEN) {
			m_pathXCoords.at(i) = PATH_TWENTY_THREE;
			m_pathYCoords.at(i) = PATH_FOURTY - i;
		}
		else if (i < PATH_FIFTY_FOUR) {
			m_pathXCoords.at(i) = i - PATH_THIRTEEN;
			m_pathYCoords.at(i) = PATH_FOUR;
		}
		else if (i < PATH_SIXTY) {
			m_pathXCoords.at(i) = PATH_FOURTY;
			m_pathYCoords.at(i) = i - PATH_FOURTY_NINE;
		}
		else {
			m_pathXCoords.at(i) = i - PATH_NINETEEN;
			m_pathYCoords.at(i) = PATH_TEN;
		}
	}
}

Board::Board() {
	m_money = START_MONEY;
  	m_health = START_HEALTH;
	m_towerPlacement.resize(GAME_LENGTH);

	for (int i = 0; i < GAME_LENGTH; i++) {
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
