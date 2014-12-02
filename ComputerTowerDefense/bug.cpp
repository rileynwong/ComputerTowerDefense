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

void Bug::printBug() {
	cout << "bug: ";
	cout << m_x << " ";
	cout << m_y << " ";
	//cout << m_health << " ";
	cout << endl;
}

Bug::Bug(int health, int reward, int x, int y) {
	m_health = DEF_HEALTH;
	m_x = DEF_X_START;
	m_y = DEF_Y_START;
	m_reward = DEF_REWARD;
	setReward(reward);
	setHealth(health);
	setXPosition(x);
	setYPosition(y);
}