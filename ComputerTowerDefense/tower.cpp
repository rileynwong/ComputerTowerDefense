/* File: tower.cpp
   Author: Samy Lanka
   PennKey: lankas
   Description:  Defines all functions associated with the Tower Object
*/

#include <stdlib.h>
#include "tower.h"
#include <iostream>

void Tower::setXPosition(int x) {
  	if (x > 0) {
		m_x = x;	
  	}
}

void Tower::setYPosition(int y) {
	if (y > 0) {
		m_y = y;	
	}
}

int Tower::getXPosition() {
  return m_x;
}

int Tower::getYPosition() {
  return m_y;
}

void Tower::setRadius(int radius) {
	if (radius > 0) {
		m_radius = radius;
	}
}

void Tower::setAttack(int attack) {
  if (attack > 0) {
	m_attack = attack;
  }
}

void Tower::setDirection(bool multipleDirs, direction dir) {
	m_multipleDirs = multipleDirs;
	m_dirAttack = dir;
}

int Tower::getAttack() {
  return m_attack;
}

int Tower::getRadius() {
	return m_radius;
}

direction Tower::getDirAttack() {
	if (m_multipleDirs) {
		// TODO: handle this case
		// TODO: have a vector of directions to return
		m_dirNum++;
		return m_dirAttack;
	}
	return m_dirAttack;
}

Tower::Tower(int attack, bool multipleDirs, direction dir, 
	int radius, int x, int y) {
	m_dirNum = 0;
	m_attack = DEF_ATTACK;
	m_x = DEF_X;
	m_y = DEF_Y;
	m_dirAttack = DEF_DIR;
	m_radius = DEF_RADIUS;
	m_multipleDirs = DEF_MULT_DIR;
	setDirection(multipleDirs, dir);
	setRadius(radius);
	setAttack(attack);
	setXPosition(x);
	setYPosition(y);
}
