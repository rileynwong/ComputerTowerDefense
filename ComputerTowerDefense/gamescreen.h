/* File:   gamescreen.h 
   Author: Nancy Wong
   Desc:   header file for gamescreen.cpp
*/

#ifndef GS_H
#define GS_H

#include <vector>

#define VEC_L 15
#define VEC_W 50

// draw the board
void DrawInitA(vector< vector<char> > *GameScreen);
void DrawInitB(vector< vector<char> > *GameScreen);

// print stuff
void PrintMenu();
void PrintSubContents();
void PrintSubMenu();

// other stuff
void Shoot(vector< vector<char> > *GameScreen, int dir, int startX, int startY, 
                                                        int endX,   int endY);

#endif /* GS_H */
