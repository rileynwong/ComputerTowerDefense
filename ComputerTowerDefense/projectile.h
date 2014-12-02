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
#define GAME_WIDTH 10
#define DEF_DIST 1
#define DEF_X_PROJ 0
#define DEF_Y_PROJ 0

class Projectile {
  private:
  	int m_x;
  	int m_y;
  	int m_attack;  	
  	int m_distance;
  	direction m_dir;

  	void setAttack(int attack);
  	void setXPosition(int x);
  	void setYPosition(int y);
  	void setDirection(direction dir);
  	void setDistance(int distance);

  public: 
  	void printProjectile();
  	int getXPosition();
  	int getYPosition();
  	int getAttack();
  	int move();

  	Projectile(int x = DEF_X_PROJ, int y = DEF_Y_PROJ, int attack = DEF_ATTACK,
  		direction dir = DIR_ATTACK, int distance = DEF_DIST);
};

#endif