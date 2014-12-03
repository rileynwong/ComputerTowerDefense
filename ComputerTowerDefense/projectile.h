/* File: projectile.h
   Author: Samy Lanka
   PennKey: lankas
   Description: This file contains the definition
   of all the functions and member variables associated with
   the Projectile object
*/

#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "tower.h"
#include "definitions.h"

#define GAME_WIDTH  50
#define GAME_LENGTH 14
#define DEF_DIST    2
#define DEF_X_PROJ  0
#define DEF_Y_PROJ  0

class Projectile {
  private:
  	int m_x;
  	int m_y;
  	int m_attack;  	
  	int m_distance;
    int m_width;
    int m_length;
  	direction m_dir;

  	void setAttack(int attack);
  	void setXPosition(int x);
  	void setYPosition(int y);
  	void setDirection(direction dir);
  	void setDistance(int distance);
    void setWidth(int width);
    void setLength(int length);

  public: 
  	void printProjectile();
  	int getXPosition();
  	int getYPosition();
  	int getAttack();
  	int move();

    direction getDirection() {return m_dir; }; 

  	Projectile(int x = DEF_X_PROJ, int y = DEF_Y_PROJ, int attack = DEF_ATTACK,
  		direction dir = DEF_DIR, int distance = DEF_DIST, 
      int width = GAME_WIDTH, int length = GAME_LENGTH);
};

#endif