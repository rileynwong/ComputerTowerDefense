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

#define BUY     0
#define EXIT    1

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

void PrintMenu() {
  // towers
  cout << "0 - Buy Towers and Spells" << endl;
  cout << "1 - Exit" << endl;

}

void PrintSubMenu() {
  int input;

  // print submenu contents
  // towers
  cout << "TOWERS:" << endl;


  cout << endl;

  // spells
  cout << "SPELLS:" << endl;



  cout << endl;
  cout << "0 - back to main menu" << endl;

  cin >> input;

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

int main() {

  int input, curr;
  bool playing = false;
  clock_t start, timePassed, secondsPassed;

	Board board;
	cout << "board made" << endl;
	Tower tower;
	cout << "tower made" << endl;

	board.addBug();
	int lose = 0;
	while (lose != 1) {
		lose = board.moveBugs();
	}
	cout << "I lost!" << endl << endl;

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

  /* WAVE 1 */
  playing = true;
  start = clock();
  curr = start;

  while(playing) {
    start = clock();

    if(((start - curr)/(double) 1000000) >= 1) {
      cout << "1 second later..." << endl; 
      curr = start;
    }
  }


  return 0;
}

