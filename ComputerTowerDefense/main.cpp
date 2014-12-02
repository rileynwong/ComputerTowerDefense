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
//#include "gamescreen.h"

#define BUY       0
#define EXIT      1
#define MIN_VAL   0
#define MAX_VAL   50

using namespace std;

/* File:    
   Author: Nancy Wong
   Desc:
*/

#include "gamescreen.h"
#include <vector>


void DrawInitA(vector< vector<char> > *GameScreen) {
  int i;

  /* draw path */

  // 9 right
  for(i = 0; i < 10; i++) {
    GameScreen->at(7).at(i) = ' ';
  }

  // 5 down
  for(i = 8; i < 13; i++) {
    GameScreen->at(i).at(9) = ' ';
  }

  // 13 right
  for(i = 10; i < 24; i++) {
    GameScreen->at(12).at(i) = ' ';
  }

  // 16 up
  for(i = 4; i < 13; i++) {
    GameScreen->at(i).at(23) = ' ';
  }

  // 5 right
  for(i = 24; i < 40; i++) {
    GameScreen->at(4).at(i) = ' ';
  }

  // 7 down
  for(i = 4; i < 11; i++) {
    GameScreen->at(i).at(40) = ' ';
  }

  // 9 right
  for(i = 41; i < 50; i++) {
    GameScreen->at(10).at(i) = ' ';
  }

}

void DrawInitB(vector< vector<char> > *GameScreen) {
  int i;

  /* draw path */
  // 9 right - top
  for(i = 0; i < 11; i++) {
    GameScreen->at(6).at(i) = '-';
  }
  for(i = 0; i < 8; i++) {
    GameScreen->at(8).at(i) = '-';
  }

  // 5 down
  for(i = 6; i < 12; i++) {
    GameScreen->at(i).at(10) = '|';
  }
  for(i = 8; i < 14; i++) {
    GameScreen->at(i).at(8) = '|';
  }

  // 13 right 
  for(i = 11; i < 23; i++) {
    GameScreen->at(11).at(i) = '-';
  }
  for(i = 9; i < 24; i++) {
    GameScreen->at(13).at(i) = '-';
  }


  // 16 up 
  for(i = 3; i < 12; i++) {
    GameScreen->at(i).at(22) = '|';
  }
  for(i = 5; i < 14; i++) {
    GameScreen->at(i).at(24) = '|';
  }

  // 5 right
  for(i = 23; i < 41; i++) {
    GameScreen->at(3).at(i) = '-';
  }
  for(i = 25; i < 39; i++) {
    GameScreen->at(5).at(i) = '-';
  }


  // 7 down
  for(i = 5; i < 12; i++) {
    GameScreen->at(i).at(39) = '|';
  }
  for(i = 3; i < 10; i++) {
    GameScreen->at(i).at(41) = '|';
  }


  // 9 right
  for(i = 42; i < 50; i++) {
    GameScreen->at(9).at(i) = '-';
  }
  for(i = 40; i < 50; i++) {
    GameScreen->at(11).at(i) = '-';
  }

}

void PrintMenu() {
  // towers
  cout << endl << "Do something fun: " << endl;
  cout << "\t0 - Buy Towers and Spells" << endl;
  cout << "\t1 - Exit" << endl;

}

void PrintSubContents() {
  // towers
  cout << "\tTOWERS:" << endl;
  cout << "\t\t0 - baby tower: i" << endl;
  cout << "\t\t1 - meta tower: I" << endl;
  cout << endl;

  // spells
  cout << "\tSPELLS:" << endl;
  cout << "\t\t2 - spell 1" << endl;
  cout << endl;
  cout << "\t0 - back to main menu" << endl;

}

void PrintSubMenu() {
  int input = 5;

  // 1. print contents
  PrintSubContents();

  // 2. handle input
  
//  cin >> input;

  while(input != EXIT) {
    switch(input) {
      case 0: // return to main menu
        PrintMenu();
        break;
      case 1: // buy stuff
        break;
    }

    // Refresh(&GameScreen);

  }

}

void InBounds(int *x) {
  if(*x < MIN_VAL) *x = MIN_VAL;
  if(*x < MAX_VAL) *x = MAX_VAL;
}

void Shoot(vector< vector<char> > *GameScreen, int dir, int startX, int startY, 
                                                        int endX,   int endY) {
  InBounds(&startX);
  InBounds(&startY);
  InBounds(&endX);
  InBounds(&endY);

  // direction - an enum w/ switch case?
  switch(dir) {
    case 0: // north ^
      while(startX) {

      }

      break;
    case 1: // east >
      break;
    case 2: // south v
      break;
    case 3: // west <
      break;
  }

  // stop when you hit a game object or edge

}

void Refresh(vector< vector<int> > *GameScreen) {
}



int main() {

  int input, curr, score = 0;
  bool playing = false;
  clock_t start, timePassed, secondsPassed;

  cout << endl;
  cout << "    \\\\\\\\\\  COMPUTER TOWER DEFENSE aw yeah /////" << endl << endl;

  vector< vector<char> > GameScreen(VEC_L, vector<char>(VEC_W, '.'));
  DrawInitA(&GameScreen);
  DrawInitB(&GameScreen);

  // draw board
  int row, col;

  cout << "   0 2 4 6 810 2 4 6 820 2 4 6 830 2 4 6 840 2 4 6 8" << endl;
  for(row = 0; row < VEC_L; row++) {
    cout << setw(2) << right << row << " ";
    for(col = 0; col < VEC_W; col++) {
        cout << GameScreen.at(row).at(col);
    }
    cout << endl;
  }

  cout << endl;

  PrintMenu();
//  PrintSubMenu();
//  cin >> input;
/*
  while(input != EXIT) {
    switch(input) {
      case 0: // buying stuff
        cout << endl;
        PrintSubMenu();
        playing = false;
        break;
      case 1: // exit
        // TODO free memory and stuff
        cout << endl << "Bye!" << endl;
        exit(0);
        break;
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
    }
  }


  return 0;
}

