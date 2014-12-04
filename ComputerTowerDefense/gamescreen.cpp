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
  while(input < EXIT || input > NOTHING) {
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
  while(input < MAIN || input > WEST) {
      cout << "error: please enter a value between ";
      cout << MAIN << " and " << WEST << "." << endl;
      cin >> input;
  }

  if(input != MAIN) {
    // 3. prompt x and y coordinates
    cout << "x coordinate: ";
    cin >> x;

    while(x < X_MIN || x > X_MAX) {
      cout << "error: please enter a value between ";
      cout << X_MIN << " and " << X_MAX << endl;
      cin >> x;
    }

    cout << "y coordinate: ";
    cin >> y;
    while(y < Y_MIN || y > Y_MAX) {
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

void Reprompt(Board *GameBoard) {
  string filename;
  cout << "Play again? What map what you like to play?" << endl;
  cin >> filename;

  delete GameBoard;
  GameBoard = NULL;
  GameBoard = new Board(filename);
}

void GameEnd(Board *GameBoard, int res) {
  string result;

  if(res == WIN) {
    result = "WIN";
  } else {
    result = "LOSE";
  }

  cout << endl;
  cout << "-----------------------------------------------------" << endl;
  cout << "                     YOU " << result << endl;
  cout << "-----------------------------------------------------" << endl;

  cout << endl;
  Reprompt(GameBoard);
}

void SetPieces(vector< vector< int > > pieces, 
               vector< vector<char> > *GameScreen) {
  int i, j;

  for (i = 0; i < (int) pieces.size(); i++) {
    for (j = 0; j < (int) pieces.at(i).size(); j++) {
      switch(pieces.at(i).at(j)) {
        case NO_OBJECT:
          GameScreen->at(i).at(j) = '.';
          break;
        case PATH:
          GameScreen->at(i).at(j) = ' ';
          break;
        case TOWER:
          GameScreen->at(i).at(j) = 'I';
          break;
        case PROJECTILE:
            GameScreen->at(i).at(j) = '^';
          break;
        case PROJ_ON_PATH:
          GameScreen->at(i).at(j) = '^';
          break;
        case BUG:
          GameScreen->at(i).at(j) = '*';
          break;
      }
    }
  }
}

void Refresh(vector< vector<char> > *GameScreen, Board *GameBoard, int count) {
  int lost;

  // board base
  lost = GameBoard->moveBugs();
  if(lost) {
    GameEnd(GameBoard, LOSE);
  }

  if(GameBoard->getMoney() >= GAME_WIN) {
    GameEnd(GameBoard, WIN);
  }

  if(count % DELAY == 0) {
    GameBoard->attack();
  } else {
    GameBoard->moveProjectiles();
  }

  // set pieces (bugs, towers, projectiles) for the board
  SetPieces(GameBoard->getPieces(), GameScreen);

  // draw board
  PrintBoard(GameScreen); 
  PrintStats(GameBoard);
}




