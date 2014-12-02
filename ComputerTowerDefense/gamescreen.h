/* File:   gamescreen.h 
   Author: Nancy Wong
   Desc:   header file for gamescreen.cpp
*/

#ifndef GS_H
#define GS_H
#include <vector>

#define VEC_L 15
#define VEC_W 50

void DrawInit();
void DrawInit(vector< vector<char> > *GameScreen);
void Refresh(vector< vector<char> > *GameScreen);

#endif /* GS_H */
