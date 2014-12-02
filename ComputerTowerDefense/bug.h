
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
#define DEF_Y_START 0
#define POS_INTERVAL 10

enum direction {N, S, E, W};

class Bug {
  private:
    int m_x;
    int m_y;
    int m_health;
    int m_move_num;
    int m_reward;
    std::vector< direction > m_movements;

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
    int getMoveNum();
    int takeDamage(int damage);
    int move();

    Bug(int health = DEF_HEALTH, int reward = DEF_REWARD, 
      int x = DEF_X_START, int y = DEF_Y_START);
};

#endif
