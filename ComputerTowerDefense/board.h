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

#define START_MONEY 5
#define GAME_WIDTH 10
#define PATH_LENGTH 3
#define NO_OBJECT 0
#define TOWER 1
#define PROJECTILE 2

class Board {
  private:
    vector<Bug*> m_bugs;
    vector<Tower> m_towers; 
    vector< vector< int > > m_towerPlacement;
    vector<int> m_pathXCoords;
    vector<int> m_pathYCoords;
    vector<Bug*> m_bugPlacement;
    int m_money;
    void removeBug(Bug *b);
    void addBug();

  public:
    void printBugs();
    void printTowerLocations();

    void addPath();
    bool containsPath(int x, int y);
    vector<Bug*> getBugs();
    
    int moveBugs();
    void attack();
    
    // change to buy each specific tower and spell
    vector<Tower> getTowers();
    Tower *buyTower();
    void placeTower(Tower *t, int x, int y);
    void buySpell();
    void playSpell();

    Board();
};   

#endif
