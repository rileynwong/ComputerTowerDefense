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

  int count = 0;
  bool submenu = false, playing = false;

  Board *GameBoard = new Board();
  vector< vector<char> > GameScreen(VEC_L, vector<char>(VEC_W, '.'));

  /* Game Start */
  playing = true;
  count = 0;

  while(playing) {

    Refresh(&GameScreen, GameBoard, count++); // redraw the board
    playing = PrintMenu(GameBoard);
    if(submenu) { 
      PrintSubMenu(GameBoard); 
    }
  }

  return 0;
}

