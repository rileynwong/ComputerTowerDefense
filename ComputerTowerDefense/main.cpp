/* File:   main.cpp 
   Author: Nancy Wong
   Desc:   Main file for executing Computer Tower Defense
*/

#include <iostream>
#include <time.h>

#include "board.h"
#include "gamescreen.h"

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


int main() {
	Board board;
	cout << "board made" << endl;
	Tower tower;
	cout << "tower made" << endl;

	board.addBug();
	int lose = 0;
	while (lose != 1) {
		lose = board.moveBugs();
	}
	cout << "I lost!" << endl;

  vector< vector<char> > GameScreen(VEC_L, vector<char>(VEC_W, '.')); // malloc?
  DrawInitA(&GameScreen);
  DrawInitB(&GameScreen);

  int row, col;
  for(row = 0; row < VEC_L; row++) {
      for(col = 0; col < VEC_W; col++) {
        cout << GameScreen.at(row).at(col);
    }
    cout << endl;
  }


/*
  // while(!exit) {}
  Refresh(GameScreen);

  // Exit(GameScreen); // destroy malloc

*/


  return 0;
}

