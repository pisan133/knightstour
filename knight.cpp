//
// Created by Yusuf Pisan on 2/3/19.
//

#include <iostream>

using namespace std;

const int BOARDSIZE = 8;

void printBoardLine() {
  for (int i = 0; i < BOARDSIZE; ++i) {
    cout << "____";
  }
  cout << endl;
}

void printBoard(const int board[BOARDSIZE][BOARDSIZE]) {
  cout << "Board:" << endl;
  printBoardLine();
  for (int i = 0; i < BOARDSIZE; ++i) {
    for (int j = 0; j < BOARDSIZE; ++j) {
      if (board[i][j] == 0) {
        cout << "  ";
      } else {
        if (board[i][j] < 10)
          cout << " ";
        cout << board[i][j];
      }
      cout << " |";
    }
    cout << endl;
    printBoardLine();
  }
}

void resetBoard(int board[BOARDSIZE][BOARDSIZE]) {
  for (int i = 0; i < BOARDSIZE; ++i) {
    for (int j = 0; j < BOARDSIZE; ++j) {
      board[i][j] = 0;
    }
  }
}

bool isAvailable(const int board[BOARDSIZE][BOARDSIZE], int row, int col) {
  return row >= 0 && col >= 0 &&
      row < BOARDSIZE && col < BOARDSIZE && board[row][col] == 0;
}
void getNextLocation(const int board[BOARDSIZE][BOARDSIZE], int &row, int &col) {
  // there are 8 possibilities for the knight
  // we should probably choose a location at random or use a heuristic
  // for now it only goes right and down
  int horizontal[BOARDSIZE];
  int vertical[BOARDSIZE];
  // 8 possible moves
  horizontal[0] = 2;
  vertical[0] = -1;
  horizontal[1] = 1;
  vertical[1] = -2;
  horizontal[2] = -1;
  vertical[2] = -2;
  horizontal[3] = -2;
  vertical[3] = -1;
  horizontal[4] = -2;
  vertical[4] = 1;
  horizontal[5] = -1;
  vertical[5] = 2;
  horizontal[6] = 1;
  vertical[6] = 2;
  horizontal[7] = 2;
  vertical[7] = 1;
  // random move index
  int rm = rand() % 8;
  while (!isAvailable(board, row + vertical[rm], col + horizontal[rm])) {
    rm = rand() % 8;
  }
  row = row + vertical[rm];
  col = col + horizontal[rm];
}

int knightsTour() {
  int board[BOARDSIZE][BOARDSIZE];
  resetBoard(board);
  int row = 0;
  int col = 0;
  int counter = 0;
  while (row != -1 && col != -1) {
    ++counter;
    board[row][col] = counter;
    printBoard(board);
    getNextLocation(board, row, col);
  }
  return counter;
}