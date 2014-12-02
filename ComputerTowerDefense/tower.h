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
#define DIR_ATTACK N
#define DEF_MULT_DIR false
#define DEF_RADIUS 2
#define DEF_X 0
#define DEF_Y 0

enum direction {N, S, E, W};

class Tower {
  private:
    int m_x;
    int m_y;
    int m_radius;
    int m_attack;
    int m_dirNum;
    bool m_multipleDirs;
    direction m_dirAttack;
    void setRadius(int radius);
    void setAttack(int attack);
    void setDirection(bool multipleDirs, direction dir);
  
  public:
    void setXPosition(int x);
    void setYPosition(int y);
    int getXPosition();
    int getYPosition();
    int getAttack();
    int getRadius();
    direction getDirAttack();

    Tower(int attack = DEF_ATTACK, 
      bool multipleDirs = DEF_MULT_DIR,
      direction dir = DIR_ATTACK, 
      int radius = DEF_RADIUS,
      int x = DEF_X, int y = DEF_Y);
};

#endif
