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
#include "projectile.h"
#include "bug.h"
#include "tower.h"

using namespace std;

#define START_MONEY       20
#define START_HEALTH      100
#define PATH_LENGTH       69
#define NO_OBJECT         0
#define TOWER             1
#define PROJECTILE        2
#define BUG               3

#define PATH_TWO          2
#define PATH_THREE        3
#define PATH_FOUR         4
#define PATH_FIVE         5
#define PATH_SIX          6
#define PATH_SEVEN        7
#define PATH_EIGHT        8
#define PATH_NINE         9
#define PATH_TEN          10
#define PATH_ELEVEN       11
#define PATH_TWELVE       12
#define PATH_THIRTEEN     13
#define PATH_FOURTEEN     14
#define PATH_FIFTEEN      15
#define PATH_SEVENTEEN    17
#define PATH_NINETEEN     19
#define PATH_TWENTY_TWO   22
#define PATH_TWENTY_THREE 23
#define PATH_TWENTY_FOUR  24
#define PATH_TWENTY_FIVE  25
#define PATH_TWENTY_NINE  29
#define PATH_THIRTY_SEVEN 37
#define PATH_THIRTY_NINE  39
#define PATH_FOURTY       40
#define PATH_FOURTY_ONE   41
#define PATH_FOURTY_TWO   42
#define PATH_FOURTY_FOUR  44
#define PATH_FOURTY_NINE  49
#define PATH_FIFTY        50
#define PATH_FIFTY_FOUR   54
#define PATH_SIXTY        60

class Board {
  private:
    vector<Tower*> m_towers; 
    vector< vector< int > > m_towerPlacement;
    vector<int> m_pathXCoords;
    vector<int> m_pathYCoords;
    vector<Bug*> m_bugPlacement;
    vector<Projectile*> m_projectiles;

    int m_money;
    int m_health;

    void addBug();
    void removeBug(Bug *b);

    Bug *findBug(int x, int y);

    void removeProjectile(Projectile *p);
    Projectile *moveProjectile(Projectile *p);  
    
    bool containsPath(int x, int y);
    bool buyTower();
    void placeTower(Tower *t, int x, int y);

    void addPath();
  public:
    int moveBugs();
    
    void attackBug(Bug *bug, int attack);
    void attack();
    
    int getMoney() { return m_money; };
    int getHealth() { return m_health; };

    vector< vector< int > > getPieces() { return m_towerPlacement; };

    // change to buy each specific tower and spell
    void moveProjectiles();

    void printBugs();
    void printTowerLocations();

    bool enoughMoney();
    void buyNTower(int x, int y);
    void buyETower(int x, int y);
    void buyWTower(int x, int y);
    void buySTower(int x, int y);   
    vector<Tower*> getTowers();

    void buySpell();
    void playSpell();

    Board();
};   

#endif
