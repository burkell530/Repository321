/*
 * Name        : four_max.cpp
 * Author      : Luke Sathrum
 * Description : Example of writing a bunch of overloaded functions that really
 *               do the same thing
 */

#include <iostream>
using std::cout;
using std::endl;

// First overloaded function
int Max(int x, int y) {
  if (x > y)
    return x;
  else
    return y;
}

// Second overloaded function
double Max(double x, double y) {
  if (x > y)
    return x;
  else
    return y;
}

// Third overloaded function
double Max(int x, double y) {
  if (x > y)
    return x;
  else
    return y;
}

// Fourth overloaded function
double Max(double x, int y) {
  if (x > y)
    return x;
  else
    return y;
}

// Program starts here
int main() {
  // Call our 4 overloaded functions
  cout << "Which is bigger (5, 10)?     ";
  cout << Max(5, 10) << endl;
  cout << "Which is bigger (5.5, 10.1)? ";
  cout << Max(5.5, 10.1) << endl;
  cout << "Which is bigger (10.5, 11)?   ";
  cout << Max(10.5, 11) << endl;
  cout << "Which is bigger (5, 10.1)?   ";
  cout << Max(5, 10.1) << endl;

  // This ends our program
  return 0;
}
