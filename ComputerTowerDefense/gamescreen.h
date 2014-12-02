/* File:   gamescreen.h 
   Author: Nancy Wong
   Desc:   header file for gamescreen.cpp
*/

#ifndef GS_H
#define GS_H

#include <vector>

#include "board.h"

#define VEC_L 15
#define VEC_W 50

#define BUY        0
#define NOTHING    1
#define EXIT       2
#define MIN_VAL    0
#define MAX_VAL    50
#define DO_NOTHING 5

using namespace std;

// draw the board
void DrawInitA(vector< vector<char> > *GameScreen);
void DrawInitB(vector< vector<char> > *GameScreen);

// print stuff
void PrintBoard(vector< vector<char> > *GameScreen);
void PrintStats(Board *GameBoard);
bool PrintMenu(Board *GameBoard);
void PrintSubContents();
void PrintSubMenu(Board *GameBoard);
void PrintScore(int score);
void PrintHealth(int health);

// other stuff
//void Shoot(vector< vector<char> > *GameScreen, int dir, int startX, int startY, 
  //                                                      int endX,   int endY);

void Refresh(vector< vector<char> > *GameScreen, Board *GameBoard, int count);
// void GameOver();

#endif /* GS_H */
