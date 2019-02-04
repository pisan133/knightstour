/**
 * Testing of knight's tour
 */


#include <iostream>

using namespace std;

// forward declarations
int knightsTour();

// should try out knightsTour multiple times and report best result
void testAll() {
  int result = knightsTour();
  cout << "Best result for knight is " << result << endl;
}

int main() {
  testAll();
  cout << "Done!" << endl;
  return 0;
}
