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
#include "gameObject.h"
#include "bug.h"
#include "tower.h"

using namespace std;

#define START_MONEY 5
#define GAME_WIDTH 10


class Board {
  private:
    vector<Bug> m_bugs;
    vector<Tower> m_towers; 
    vector< vector< bool > > m_tower_placement;
    int m_money;
    void removeBug(Bug *b);

  public:
    void printBugs();
    void printTowerLocations();

    void addPath();
    vector<Bug> getBugs();
    void addBug();
    int moveBugs();
    void attack();
    vector<Tower> getTowers();

    // change to buy each specific tower and spell
    Tower *buyTower();
    void placeTower(Tower *t, int x, int y);
    void buySpell();
    void playSpell();

    Board();
};   

#endif
