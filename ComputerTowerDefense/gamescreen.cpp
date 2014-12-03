/* File:   gamescreen.cpp 
   Author: Nancy Wong
   Desc:   Display and redraw the game screen
*/

#include <vector>
#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
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
  for(i = 0; i < PATH_TEN; i++) {
    GameScreen->at(PATH_SEVEN).at(i) = ' ';
  }

  // 5 down
  for(i = PATH_EIGHT; i < PATH_THIRTEEN; i++) {
    GameScreen->at(i).at(PATH_NINE) = ' ';
  }

  // 13 right
  for(i = PATH_TEN; i < PATH_TWENTY_FOUR; i++) {
    GameScreen->at(PATH_TWELVE).at(i) = ' ';
  }

  // 16 up
  for(i = PATH_FOUR; i < PATH_THIRTEEN; i++) {
    GameScreen->at(i).at(PATH_TWENTY_THREE) = ' ';
  }

  // 5 right
  for(i = PATH_TWENTY_FOUR; i < PATH_FOURTY; i++) {
    GameScreen->at(PATH_FOUR).at(i) = ' ';
  }

  // 7 down
  for(i = PATH_FOUR; i < PATH_ELEVEN; i++) {
    GameScreen->at(i).at(PATH_FOURTY) = ' ';
  }

  // 9 right
  for(i = PATH_FOURTY_ONE; i < PATH_FIFTY; i++) {
    GameScreen->at(PATH_TEN).at(i) = ' ';
  }

}

void DrawInitB(vector< vector<char> > *GameScreen) {
  int i;

  /* draw path */
  // 9 right - top
  for(i = 0; i < PATH_ELEVEN; i++) {
    GameScreen->at(PATH_SIX).at(i) = '-';
  }
  for(i = 0; i < PATH_EIGHT; i++) {
    GameScreen->at(PATH_EIGHT).at(i) = '-';
  }

  // 5 down
  for(i = PATH_SIX; i < PATH_TWELVE; i++) {
    GameScreen->at(i).at(PATH_TEN) = '|';
  }
  for(i = PATH_EIGHT; i < PATH_FOURTEEN; i++) {
    GameScreen->at(i).at(PATH_EIGHT) = '|';
  }

  // 13 right 
  for(i = PATH_ELEVEN; i < PATH_TWENTY_THREE; i++) {
    GameScreen->at(PATH_ELEVEN).at(i) = '-';
  }
  for(i = PATH_NINE; i < PATH_TWENTY_FOUR; i++) {
    GameScreen->at(PATH_THIRTEEN).at(i) = '-';
  }


  // 16 up 
  for(i = PATH_THREE; i < PATH_TWELVE; i++) {
    GameScreen->at(i).at(PATH_TWENTY_TWO) = '|';
  }
  for(i = PATH_FIVE; i < PATH_FOURTEEN; i++) {
    GameScreen->at(i).at(PATH_TWENTY_FOUR) = '|';
  }

  // 5 right
  for(i = PATH_TWENTY_THREE; i < PATH_FOURTY_ONE; i++) {
    GameScreen->at(PATH_THREE).at(i) = '-';
  }
  for(i = PATH_TWENTY_FIVE; i < PATH_THIRTY_NINE; i++) {
    GameScreen->at(PATH_FIVE).at(i) = '-';
  }


  // 7 down
  for(i = PATH_FIVE; i < PATH_TWELVE; i++) {
    GameScreen->at(i).at(PATH_THIRTY_NINE) = '|';
  }
  for(i = PATH_THREE; i < PATH_TEN; i++) {
    GameScreen->at(i).at(PATH_FOURTY_ONE) = '|';
  }


  // 9 right
  for(i = PATH_FOURTY_TWO; i < PATH_FIFTY; i++) {
    GameScreen->at(PATH_NINE).at(i) = '-';
  }
  for(i = PATH_FOURTY; i < PATH_FIFTY; i++) {
    GameScreen->at(PATH_ELEVEN).at(i) = '-';
  }

}

void PrintBoard(vector< vector<char> > *GameScreen) {
  int row, col;

  cout << endl;
  cout << "    \\\\\\\\\\ COMPUTER TOWER DEFENSE aw yeah /////" << endl << endl;

  // draw board

  cout << "   0 2 4 6 810 2 4 6 820 2 4 6 830 2 4 6 840 2 4 6 8" << endl;
  for(row = 0; row < VEC_L; row++) {
    cout << setw(WIDTH_1) << right << row << " ";
    for(col = 0; col < VEC_W; col++) {
        cout << GameScreen->at(row).at(col);
    }
    cout << endl;
  }

  cout << endl;
}

void PrintStats(Board *GameBoard) {
  cout << "\tBits:   " << GameBoard->getMoney()  << endl;
}

bool PrintMenu(Board *GameBoard) {
  int input;

  cout << "\tDo something fun: " << endl;
  cout << "\t\t1 - Buy towers" << endl;
  cout << "\t\t2 - Do nothing" << endl;
  cout << "\t\t0 - Exit" << endl;

  cin >> input;
  while(input < EXIT | input > NOTHING) {
      cout << "error: please enter a value between ";
      cout << EXIT << " and " << NOTHING << "." << endl;
      cin >> input;
  }

  switch(input) {
    case BUY:
      PrintSubMenu(GameBoard);
      return true;
    case NOTHING:
      return true;
    case EXIT:
      return false;
  }

  return false;
}

void PrintSubContents() {
  // towers
  cout << "\tTOWERS:" << endl;
  cout << "\t\t1 - Shooting tower - North (5 bits)" << endl;
  cout << "\t\t2 - Shooting tower - East  (5 bits)" << endl;
  cout << "\t\t3 - Shooting tower - South (5 bits)" << endl;
  cout << "\t\t4 - Shooting tower - West  (5 bits)" << endl;
  cout << "\t\t0 - back to main menu" << endl;

  cout << endl;
}

void PrintSubMenu(Board *GameBoard) {
  int x, y, input;

  // 1. print contents
  PrintSubContents();

  // 2. handle input
  cin >> input;
  while(input < MAIN | input > WEST) {
      cout << "error: please enter a value between ";
      cout << MAIN << " and " << WEST << "." << endl;
      cin >> input;
  }

  if(input != MAIN) {
    // 3. prompt x and y coordinates
    cout << "x coordinate: ";
    cin >> x;

    while(x < X_MIN | x > X_MAX) {
      cout << "error: please enter a value between ";
      cout << X_MIN << " and " << X_MAX << endl;
      cin >> x;
    }

    cout << "y coordinate: ";
    cin >> y;
    while(y < Y_MIN | y > Y_MAX) {
      cout << "error: please enter a value between ";
      cout << Y_MIN << " and " << Y_MAX << endl;
      cin >> y;
    }

    // 4. purchase tower
    switch(input) {
      case NORTH:
        GameBoard->buyNTower(x, y);
        break;
      case EAST: 
        GameBoard->buyETower(x, y);
        break;
      case SOUTH: 
        GameBoard->buySTower(x, y);
        break;
      case WEST:
        GameBoard->buyWTower(x, y);
        break;
    }
  }

}


void PrintWin() {
  cout << endl;

  std::cout << std::setfill ('x') << std::setw (10);
  std::cout << 77 << std::endl;

  cout << "-----------------------------------------------------" << endl;
  cout << "                     YOU WIN" << endl;
  cout << "-----------------------------------------------------" << endl;

  exit(0);
}

void GameOver() {
  cout << endl;

  std::cout << std::setfill ('x') << std::setw (10);
  std::cout << 77 << std::endl;

  cout << "-----------------------------------------------------" << endl;
  cout << "                     YOU LOSE" << endl;
  cout << "-----------------------------------------------------" << endl;

  exit(0);
}

void SetPieces(vector< vector< int > > pieces, 
               vector< vector<char> > *GameScreen, int* count) {
  int i, j;

	for (i = 0; i < (int) pieces.size(); i++) {
		for (j = 0; j < (int) pieces.at(i).size(); j++) {
      switch(pieces.at(i).at(j)) {
          GameScreen->at(i).at(j) = '.';
          break;
        case PATH:
          GameScreen->at(i).at(j) = ' ';
          break;
        case TOWER:
          GameScreen->at(i).at(j) = 'I';
          break;
        case PROJECTILE:
          // TODO check projectile direction
            GameScreen->at(i).at(j) = '^';
          break;
        case PROJ_ON_PATH:
          GameScreen->at(i).at(j) = '^';
          break;
        case BUG:
          // TODO check bug type
          GameScreen->at(i).at(j) = '*';
          break;
      }

      *count++;
		}
	}

}

void Refresh(vector< vector<char> > *GameScreen, Board *GameBoard, int count) {
  int lost;

  // board base
  DrawInitA(GameScreen);
  DrawInitB(GameScreen);

  lost = GameBoard->moveBugs();
  if(lost) {
    GameOver();
  }

  if(GameBoard->getMoney() >= GAME_WIN) {
    PrintWin();
    exit(0);
  }

  if(count % DELAY == 0) {
    GameBoard->attack();
  } else {
    GameBoard->moveProjectiles();
  }

  // set pieces (bugs, towers, projectiles) for the board
  SetPieces(GameBoard->getPieces(), GameScreen, &count);

  // draw board
  PrintBoard(GameScreen); 
  PrintStats(GameBoard);
}




