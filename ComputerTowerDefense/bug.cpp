/* File: bug.cpp
   Author: Samy Lanka
   PennKey: lankas
   Description:
*/

using namespace std;
#include "bug.h"

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

void Bug::takeDamage(int damage) {
  if (damage < 0) {
    //TODO: figure this part out
  }
  if (damage > m_health) {
    //die();
    return;
  }
  else m_health -= damage;
}

void Bug::move() {
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
    //TODO: Lost the game
  }
  //TODO: move the thing
  //TODO: Increment move_num
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