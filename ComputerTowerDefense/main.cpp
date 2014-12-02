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

  int input, curr, score = 0;
  bool submenu = false, playing = false;
  clock_t start, timePassed, secondsPassed;
  Board *GameBoard = new Board();
  vector< vector<char> > GameScreen(VEC_L, vector<char>(VEC_W, '.'));


//  cin >> input;
/*
  while(input != EXIT) {
    switch(input) {
      case 0: // buying stuff
        cout << endl;
        PrintSubMenu();
        playing = false;
        submenu = true;
        break;
      case 1: // exit
        // TODO free memory and stuff
        cout << endl << "Bye!" << endl;
        exit(0);
        break;zf
    }

    // Refresh(&GameScreen);

  }
*/

  /* Game Start */
  playing = true;
  start = clock();
  curr = start;

  while(playing) {
    start = clock();

    if(((start - curr)/(double) CLOCKS_PER_SEC) >= 1) {
      // one second has passed 
//      cout << "1 second later..." << endl; 
      curr = start;

      PrintBoard(&GameScreen);
      PrintStats(GameBoard);

      if(submenu) { PrintSubMenu(); }
      else { PrintMenu(); }

      Refresh(&GameScreen, GameBoard); // redraw the board

      // if(GameBoard->getHealth() < 0) { GameOver(); }

    }
  }


  return 0;
}

