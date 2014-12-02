/* File: tower.h
   Author: Samy Lanka
   PennKey: lankas
   Description: This file contains the definition
   of all the functions and member variables associated with
   the Tower object
*/

#ifndef TOWER_H
#define TOWER_H


#define COST_TOWER 5
#define DEF_ATTACK 1
#define DEF_X 0
#define DEF_Y 0

class Tower {
  private:
    int m_x;
    int m_y;
    int m_attack;

    void setAttack(int attack);

  public:
    void setXPosition(int x);
    void setYPosition(int y);
    int getXPosition();
    int getYPosition();
    int getAttack();

    Tower(int attack = DEF_ATTACK, 
      int x = DEF_X, int y = DEF_Y);
};

#endif
