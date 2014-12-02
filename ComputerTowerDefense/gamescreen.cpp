/* File:   gamescreen.cpp 
   Author: Nancy Wong
   Desc:   Display and redraw the game screen
*/

#include <vector>
#include <iostream>
#include <cstdio>
#include <ctime>
#include <stdio.h>
#include <iomanip>
#include <iostream>

#include "gamescreen.h"
#include "board.h"

using namespace std;

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

void PrintBoard(vector< vector<char> > *GameScreen) {
  int row, col;

  cout << endl;
  cout << "    \\\\\\\\\\  COMPUTER TOWER DEFENSE aw yeah /////" << endl << endl;

  DrawInitA(GameScreen);
  DrawInitB(GameScreen);

  // draw board

  cout << "   0 2 4 6 810 2 4 6 820 2 4 6 830 2 4 6 840 2 4 6 8" << endl;
  for(row = 0; row < VEC_L; row++) {
    cout << setw(2) << right << row << " ";
    for(col = 0; col < VEC_W; col++) {
        cout << GameScreen->at(row).at(col);
    }
    cout << endl;
  }

  cout << endl;
}

void PrintStats(Board *GameBoard) {
  cout << "Stats:" << endl;
  cout << "\tBits:   " << GameBoard->getMoney()  << endl;
  cout << "\tHealth: " << GameBoard->getHealth() << endl;
}

bool PrintMenu() {
  int input = DO_NOTHING;
  // towers
  cout << endl << "Do something fun: " << endl;
  cout << "\t0 - Buy Towers" << endl;
  cout << "\t1 - Exit" << endl;
  cout << "\t2 - Do nothing" << endl;

  cin >> input;
  while (input != DO_NOTHING) {
    switch(input) {
      case BUY:
        PrintSubMenu();
        return true;
      case EXIT:
        return false;
      case NOTHING:
        return true;
    }
  }
  return false;
}

void PrintSubContents() {
  // towers
  cout << "\tTOWERS:" << endl;
  cout << "\t\t1 - North Shooting tower: i" << endl;
  cout << "\t\t2 - East Shooting tower: i" << endl;
  cout << "\t\t3 - South Shooting tower: i" << endl;
  cout << "\t\t4 - West Shooting tower: i" << endl;
  cout << endl;

  // spells
  // cout << "\tSPELLS:" << endl;
  // cout << "\t\t2 - spell 1" << endl;
  // cout << endl;
  cout << "\t0 - back to main menu" << endl;

}

void PrintSubMenu() {
  int input = DO_NOTHING;

  // 1. print contents
  PrintSubContents();

  // 2. handle input
  cin >> input;

  while(input != DO_NOTHING) {
    switch(input) {
      case 0: // return to main menu
        PrintMenu();
        break;
      case 1: // buy stuff
        break;
      case 2:
        break;
      case 3:
        break;
      case 4:
        break;
    }
    input = DO_NOTHING;
    // Refresh(&GameScreen);

  }

}

void InBounds(int *x) {
  if(*x < MIN_VAL) *x = MIN_VAL;
  if(*x < MAX_VAL) *x = MAX_VAL;
}


void Refresh(vector< vector<char> > *GameScreen, Board *GameBoard) {
  int i, j;

  // 1. Update and set pieces

  GameBoard->moveBugs();

  // set pieces (bugs, towers, projectiles) for the board
  vector< vector< int > > pieces = GameBoard->getPieces();
	for (i = 0; i < (int) pieces.size(); i++) {
		for (j = 0; j < (int) pieces.at(i).size(); j++) {
      switch(pieces.at(i).at(j)) {
        case TOWER:
          // TODO check tower type
          GameScreen->at(i).at(j) = 'I';
          break;
        case PROJECTILE:
          // TODO check projectile direction
          GameScreen->at(i).at(j) = 'v';
          break;
        case BUG:
          // TODO check bug type
          GameScreen->at(i).at(j) = '*';
          break;
      }
		}
	}

  // 2. Draw board
  // board base
  PrintBoard(GameScreen); 
  PrintStats(GameBoard);
  
}




