/* File: bug.h
   Author: Samy Lanka
   PennKey: lankas
   Description: This file contains the definition
   of all the functions and member variables associated with
   the Bug object
*/

#ifndef BUG_H
#define BUG_H

#include <vector>

#define DEF_HEALTH 1
#define DEF_REWARD 1
#define DEF_X_START 0
#define DEF_Y_START 7

class Bug {
  private:
    int m_x;
    int m_y;
    int m_health;
    int m_reward;

    void setHealth(int health);
    void setReward(int reward);
    void setMovements();

  public:

    void printBug();
    void setXPosition(int x);
    void setYPosition(int y);
    int getXPosition();
    int getYPosition();
    int getHealth();
    int getReward();
    int takeDamage(int damage);
    int move();

    Bug(int health = DEF_HEALTH, int reward = DEF_REWARD, 
      int x = DEF_X_START, int y = DEF_Y_START);
};

#endif
