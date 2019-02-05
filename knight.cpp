//
// Created by Yusuf Pisan on 2/3/19.
//

#include <iostream>

using namespace std;

const int BSIZE = 8;

void printBoardLine() {
  for (int i = 0; i < BSIZE; ++i) {
    cout << "____";
  }
  cout << endl;
}

void printBoard(const int board[BSIZE][BSIZE]) {
  cout << "Board:" << endl;
  printBoardLine();
  for (int i = 0; i < BSIZE; ++i) {
    for (int j = 0; j < BSIZE; ++j) {
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

void resetBoard(int board[BSIZE][BSIZE]) {
  for (int i = 0; i < BSIZE; ++i) {
    for (int j = 0; j < BSIZE; ++j) {
      board[i][j] = 0;
    }
  }
}

bool isAvailable(const int board[BSIZE][BSIZE], int row, int col) {
  return row >= 0 && col >= 0 &&
      row < BSIZE && col < BSIZE && board[row][col] == 0;
}
void getNextLocation(const int board[BSIZE][BSIZE], int &row, int &col) {
  // there are 8 possibilities for the knight
  // we should probably choose a location at random or use a heuristic
  // for now it only goes right and down
  int horizontal[BSIZE];
  int vertical[BSIZE];
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
  int board[BSIZE][BSIZE];
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