/* File: tower.cpp
   Author: Samy Lanka
   PennKey: lankas
   Description: 
*/

#include <stdlib.h>
#include "tower.h"
#include <iostream>

void Tower::setXPosition(int x) {
  	// TODO: Check bounds
	m_x = x;
}

void Tower::setYPosition(int y) {
  //TODO: Check bounds
  m_y = y;
}

int Tower::getXPosition() {
  return m_x;
}

int Tower::getYPosition() {
  return m_y;
}

void Tower::setRadius(int radius) {
	// TODO: check bounds
	m_radius = radius;
}

void Tower::setAttack(int attack) {
  //TODO: error checking
  m_attack = attack;
}

int Tower::getAttack() {
  return m_attack;
}

direction Tower::getDirAttack() {
  return m_dirAttack;
}

Tower::Tower(int attack, direction dir, int radius, int x, int y) {
  m_attack = DEF_ATTACK;
  m_x = DEF_X;
  m_y = DEF_Y;
  m_dirAttack = dir;
  setAttack(attack);
  setXPosition(x);
  setYPosition(y);
}
