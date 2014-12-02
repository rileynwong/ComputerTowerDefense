/* File: bug.cpp
   Author: Samy Lanka
   PennKey: lankas
   Description:
*/

using namespace std;
#include "bug.h"
#include <iostream>

void Bug::setHealth(int health) {
  if (health < 0) {
    //TODO: error checking?
  }
  m_health = health;
}

void Bug::setReward(int reward) {
  if (reward < 0) {
    //TODO: error checking
  }
  m_reward = reward;
}


void Bug::setXPosition(int x) {
  //TODO: Check bounds
  m_x = x;
}

void Bug::setYPosition(int y) {
  //TODO: Check bounds
  m_y = y;
}

int Bug::getXPosition() {
  return m_x;
}

int Bug::getYPosition() {
  return m_y;
}

int Bug::getHealth() {
	return m_health;
}

int Bug::getReward() {
	return m_reward;
}

int Bug::getMoveNum() {
	return m_move_num;
}

int Bug::takeDamage(int damage) {
  if (damage < 0) {
    //TODO: figure this part out
  }
  if (damage >= m_health) {
    m_health = 0;
    return 1;
  }
  m_health -= damage;
  cout << "took damage" << endl;
  return 0;
}

int Bug::move() {
  direction next = m_movements[m_move_num];
  switch(next) {
    case N:
      m_y += POS_INTERVAL;
      break;
    case E:
      m_x += POS_INTERVAL;
      break;
    case S:
      m_y -= POS_INTERVAL;
      break;
    case W:
      m_x -= POS_INTERVAL;
      break;
  }
  m_move_num ++;
  if (m_move_num >= (int) m_movements.size()) {
    return 1;
  }
  return 0;
}

void Bug::setMovements() {
	vector< direction > movements(6, E);
	m_movements = movements;
	m_movements.at(2) = N;
	m_movements.at(3) = S;
	m_movements.at(4) = N;
	m_movements.at(5) = W;
}

void Bug::printBug() {
	cout << "bug: ";
	cout << m_x << " ";
	cout << m_y << " ";
	cout << m_health << " ";
	cout << m_move_num;
	cout << endl;
}

Bug::Bug(int health, int reward, int x, int y) {
	m_move_num = 0;
	m_health = DEF_HEALTH;
	m_x = DEF_X_START;
	m_y = DEF_Y_START;
	m_reward = DEF_REWARD;
	setReward(reward);
	setHealth(health);
	setXPosition(x);
	setYPosition(y);
	setMovements();
}