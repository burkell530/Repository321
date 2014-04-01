/*
 * Name        : unit_test.cpp
 * Author      : Luke Sathrum
 * Description : Trying to test code.
 */

#include <iostream>
#include <cassert>
#include <cstdlib>
using std::cout;
using std::cerr;
using std::cin;
using std::endl;

/* This function will do integer division on its two parameters and output the
 * quotient.
 * @param num1 - The dividend
 * @param num2 - The divisor
 */
void Divide(int num1, int num2) {
  cout << "The quotient is: " << (num1 / num2);
}

// Program starts here
int main() {
  int val1, val2, test;
  cout << "Enter the dividend: ";
  cin >> val1;
  cout << "Enter the divisor: ";
  cin >> val2;
  cout << "Enter 1 to run assertion example, otherwise enter 2: ";
  cin >> test;
  if (test == 1) {
    assert(val2 != 0);
    Divide(val1, val2);
  } else {
    try {
      if (val2 == 0)
        throw 5;
    } catch (int i) {
      cerr << "Error: divide by 0" << endl;
      exit(i);
    }
    Divide(val1, val2);
  }

// This ends our program
  return 0;
}
