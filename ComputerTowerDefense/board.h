/* File: board.h
   Author: Samy Lanka
   PennKey: lankas
   Description: This file contains the definition
   of all the functions and member variables associated with
   the Board object
*/
#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "bug.h"
#include "tower.h"

using namespace std;

class Board {
  private:
    vector< Bug > m_bugs;
    vector< Tower > m_towers; 
    int m_money;
  public:
    void addBug();
    int moveBugs();
    void attack();

    // change to buy each specific tower and spell
    void buyTower();
    void placeTower(Tower t, int x, int y);
    void buySpell();
    void playSpell();

    Board();
};   

#endif
