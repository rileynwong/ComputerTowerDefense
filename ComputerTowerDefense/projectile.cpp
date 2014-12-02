/* File: projectile.cpp
   Author: Samy Lanka
   PennKey: lankas
   Description: 
*/
using namespace std;

#include "projectile.h"
#include <iostream>

void Projectile::setAttack(int attack) {
	if (attack < 0) {
		// TODO: handle errors
	}
	m_attack = attack;
}

void Projectile::setXPosition(int x) {
	//TODO: check bounds
	m_x = x;
}

void Projectile::setYPosition(int y) {
	//TODO: check bounds
	m_y = y;
}
void Projectile::setDirection(direction dir) {
	m_dir = dir;
}

void Projectile::setDistance(int distance) {
	if (distance < 0) {
		// TODO: error
	}
	m_distance = distance;
}

int Projectile::getAttack() {
	return m_attack;
}

int Projectile::getXPosition() {
	return m_x;
}

int Projectile::getYPosition() {
	return m_y;
}

int Projectile::move() {
	if (m_distance <= 0) {
		// TODO: how is this destroyed
	}
	switch(m_dir) {
		case N:
			m_y--;
			if (m_y < 0) {
				cout << "neg y" << endl;
				return 1;
			}
			break;
		case E:
			m_x++;
			if (m_x > GAME_WIDTH) {
				cout << "pos x" << endl;
				return 1;
			}
			break;
		case S:
			m_y++;
			if (m_y > GAME_WIDTH) {
				cout << "pos y" << endl;
				return 1;
			}
			break;
		case W:
			m_x--;
			if (m_x < 0) {
				cout << "neg x" << endl;
				return 1;
			}
			break;
	}
	m_distance--;
	return 0;
}

void Projectile::printProjectile() {
	cout << "projectile: " << m_x << " " << m_y << endl;
}

Projectile::Projectile(int x, int y, int attack, direction dir, int distance) {
	m_x = DEF_X_PROJ;
	m_y = DEF_Y_PROJ;
	m_attack = DEF_ATTACK;
	m_dir = DIR_ATTACK;
	m_distance = DEF_DIST;

	cout << "x and y: " << x << " " << y << endl;
	setAttack(attack);
	setXPosition(x);
	setYPosition(y);
	setDirection(dir);
	setDistance(distance);
}

