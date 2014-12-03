/* File:   main.cpp 
   Author: Nancy Wong
   Desc:   Main file for executing Computer Tower Defense
*/

#include <iostream>
#include <cstdio>
#include <ctime>
#include <stdio.h>
#include <iomanip>
#include <iostream>

#include "board.h"
#include "gamescreen.h"

using namespace std;

int main() {

  int curr, count;
  bool submenu = false, playing = false;
  clock_t start;
  Board *GameBoard = new Board();
  vector< vector<char> > GameScreen(VEC_L, vector<char>(VEC_W, '.'));

  /* Game Start */
  playing = true;
  start = clock();
  curr = start;
  count = 0;

//  Refresh(&GameScreen, GameBoard, count);
//  PrintMenu(GameBoard);

  while(playing) {
    start = clock();
    curr = start;

    Refresh(&GameScreen, GameBoard, count++); // redraw the board

    if(submenu) { 
      PrintSubMenu(GameBoard); 
      // TODO: fix this later
    }
    else { 
      playing = PrintMenu(GameBoard);
    }
  }

  return 0;
}

